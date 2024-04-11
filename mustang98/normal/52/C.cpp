#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;
const ll inf = 1e14;

struct seg_tree {
    ll tr[max_n * 4];
    ll add[max_n * 4];

    seg_tree() {
        for (int i = 0; i < max_n * 4; ++i) {
            tr[i] = inf;
        }
    }

    void push(int cur) {
        tr[cur * 2] += add[cur];
        add[cur * 2] += add[cur];
        add[cur * 2 + 1] += add[cur];
        tr[cur * 2 + 1] += add[cur];
        add[cur] = 0;
    }

    void inc(int cur, int l, int r, int ql, int qr, ll val) {
        if (ql == l && qr == r) {
            add[cur] += val;
            tr[cur] += val;
            return;
        }
        if (r < ql || l > qr) {
            return;
        }
        push(cur);
        int mid = (l + r) / 2;
        inc(cur * 2, l, mid, ql, min(mid, qr), val);
        inc(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr, val);
        tr[cur] = min(tr[cur * 2], tr[cur * 2 + 1]);
    }

    ll getmin(int cur, int l, int r, int ql, int qr) {
        if (ql == l && qr == r) {
            return tr[cur];
        }
        if (ql > r || qr < l) {
            return inf;
        }
        push(cur);
        int mid = (l + r) / 2;
        return min(getmin(cur * 2, l, mid, ql, min(mid, qr)), getmin(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr));
    }
} st;

char buf[100];

string read_str() {
    gets(buf);
    return buf;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        st.inc(1, 0, n - 1, i, i, -inf + a);
    }
    cin >> q;
    string s;
    s = read_str();
    for (int i = 0; i < q; ++i) {
        s = read_str();
        int cpr = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' && (i == 0 || s[i - 1] != ' ')) {
                ++cpr;
            }
        }
        istringstream iss(s);
        int l, r;
        iss >> l >> r;
        if (cpr == 1) {
            ll ans = inf;
            if (r >= l) {
                ans = st.getmin(1, 0, n - 1, l, r);
            } else {
                ans = min(st.getmin(1, 0, n - 1, 0, r), st.getmin(1, 0, n - 1, l, n - 1));
            }
            printf("%I64d\n", ans);
        } else {
            int val;
            iss >> val;
            if (r >= l) {
                st.inc(1, 0, n - 1, l, r, val);
            } else {
                st.inc(1, 0, n - 1, 0, r, val);
                st.inc(1, 0, n - 1, l, n - 1, val);
            }
        }
    }

    return 0;
}