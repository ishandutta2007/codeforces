#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111, inf = 1000111222;

struct segment_tree {
    ll tr[max_n * 4];
    ll buf[max_n * 4];

    void push(int cur) {
        buf[cur * 2] += buf[cur];
        tr[cur * 2] += buf[cur];
        buf[cur * 2 + 1] += buf[cur];
        tr[cur * 2 + 1] += buf[cur];
        buf[cur] = 0;
    }

    void add(int cur, int l, int r, int ql, int qr, ll val) {
        if (l == ql && r == qr) {
            buf[cur] += val;
            tr[cur] += val;
            return;
        }
        if (l > qr || r < ql) {
            return;
        }
        push(cur);
        int mid = (l + r) / 2;
        add(cur * 2, l, mid, ql, min(mid, qr), val);
        add(cur * 2 + 1, mid + 1, r, max(ql, mid + 1), qr, val);
        tr[cur] = max(tr[cur * 2], tr[cur * 2 + 1]);
    }

    int get_pos(int cur, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) {
            return -1;
        }
        if (tr[cur] <= 0) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        push(cur);
        int mid = (l + r) / 2;
        int resl = get_pos(cur * 2, l, mid, ql, min(mid, qr));
        if (resl != -1) {
            return resl;
        } else {
            return get_pos(cur * 2 + 1, mid + 1, r, max(ql, mid + 1), qr);
        }
    }
} st;

pair<char, int> qr[max_n];
int q;
int pos[max_n];
pair<int, int> val[max_n];
int sz = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        scanf("\n%c %d", &qr[i].F, &qr[i].S);
        if (qr[i].F == '+') {
            val[sz++] = MP(qr[i].S, i);
        }
    }
    sort(val, val + sz);
    for (int i = 0; i < sz; ++i) {
        pos[val[i].S] = i;
    }
    set<pair<int, int>> active;
    for (int i = 0; i < q; ++i) {
        int t = qr[i].F;
        int val = qr[i].S;
        if (t == '+') {
            int p = pos[i];
            active.insert(MP(val, p));
            st.add(1, 0, sz - 1, p, p, val);
            if (p != sz - 1) {
                st.add(1, 0, sz - 1, p + 1, sz - 1, -2 * val);
            }
        } else {
            auto it = active.lower_bound(MP(val, -1));
            if (it->F != val) {
                exit(228);
            }
            int p = it->S;
            active.erase(it);
            st.add(1, 0, sz - 1, p, p, -val);
            if (p != sz - 1) {
                st.add(1, 0, sz - 1, p + 1, sz - 1, 2 * val);
            }
        }
        int cnt_bad = 0;
        int cur = 0;
        while (cur < sz) {
            cur = st.get_pos(1, 0, sz - 1, cur, sz - 1);
            if (cur == -1) {
                break;
            } else {
                ++cnt_bad;
                ++cur;
            }
        }
        printf("%d\n", int(active.size()) - cnt_bad);
    }
    return 0;
}