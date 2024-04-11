#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1<<17;

int n, ar[MAXN], tree[2*MAXN];
map<int, ll> mp;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) tree[cur] = ar[lt];
    else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        tree[cur] = gcd(tree[2*cur], tree[2*cur+1]);
    }
}

int find(int cur, int lt, int rt, int ql, int qr, int x) {
    //cout << lt << ' ' << rt << ' ' << ql << ' ' << qr << endl;
    if (rt <= ql || lt >= qr) return rt;
    else if (lt >= ql && rt <= qr) {
        if (tree[cur]%x == 0) return rt;
    }
    if (lt + 1 == rt) return lt;
    int mid = (lt + rt) / 2;
    int res = find(2*cur, lt, mid, ql, qr, x);
    if (res < mid) return res;
    return find(2*cur+1, mid, rt, ql, qr, x);
}

int query(int cur, int lt, int rt, int ql, int qr) {
    if (rt <= ql || lt >= qr) return 0;
    else if (lt >= ql && rt <= qr) return tree[cur];
    else {
        int mid = (lt + rt) / 2;
        return gcd(query(2*cur, lt, mid, ql, qr),
                   query(2*cur+1, mid, rt, ql, qr));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i];
    init(1, 0, n);

    for (int i=0; i<n; i++) {
        int cur = i, x = ar[i];
        while (cur < n) {
            int nxt = find(1, 0, n, cur+1, n, x);
            mp[x] += nxt-cur;
            cur = nxt;
            x = query(1, 0, n, i, cur+1);
        }
    }

    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int x; cin >> x;
        cout << mp[x] << '\n';
    }
    return 0;
}