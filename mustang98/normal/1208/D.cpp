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
ll inf = 1e18;

ll m[max_n];
int n;

struct segment_tree {
    ll tr[max_n * 4];
    ll add[max_n * 4];

    void build(int cur, int l, int r) {
        if (l == r) {
            tr[cur] = m[l];
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        tr[cur] = min(tr[cur * 2], tr[cur * 2 + 1]);
    }


    void push(int cur, int l, int r) {
        tr[cur] += add[cur];
        if (l != r) {
            add[cur * 2] += add[cur];
            add[cur * 2 + 1] += add[cur];
        }
        add[cur] = 0;
    }

    void add_val(int cur, int l, int r, int ql, int qr, ll val) {
        if (l == ql && r == qr) {
            add[cur] += val;
            push(cur, l, r);
            return;
        }
        push(cur, l, r);
        if (l > qr || r < ql) {
            return;
        }
        int mid = (l + r) / 2;
        add_val(cur * 2, l, mid, ql, min(mid, qr), val);
        add_val(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr, val);
        tr[cur] = min(tr[cur * 2], tr[cur * 2 + 1]);
    }

    int getlst(int cur, int l, int r) {
        push(cur, l, r);
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        push(cur * 2, l, mid);
        push(cur * 2 + 1, mid + 1, r);
        if (tr[cur * 2 + 1] == 0) {
            return getlst(cur * 2 + 1, mid + 1, r);
        } else {
            return getlst(cur * 2, l, mid);
        }
    }

} st;

int ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i =0 ; i < n; ++i) {
        cin >> m[i];
    }
    st.build(1, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        int pos = st.getlst(1, 0, n - 1);
        ans[pos] = i + 1;
        st.add_val(1, 0, n - 1, pos, pos, inf);
        st.add_val(1, 0, n - 1, pos, n - 1, -(i + 1));
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}