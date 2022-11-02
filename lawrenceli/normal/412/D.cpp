#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 30010;

int n, m, ar[MAXN], ind[MAXN];
set<pii> st;
queue<pii> que;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        st.insert(pii(a, b));
    }

    rep(i, n) ar[i] = i+1, ind[i+1] = i;
    rep(i, n-1)
        if (st.count(pii(ar[i], ar[i+1])))
            que.push(pii(ar[i], ar[i+1]));

    while (!que.empty()) {
        pii p = que.front(); que.pop();
        int a = p.fi, b = p.se;
        if (ind[a]+1 != ind[b]) continue;
        swap(ar[ind[a]], ar[ind[b]]);
        swap(ind[a], ind[b]);
        swap(a, b);
        if (ind[a] && st.count(pii(ar[ind[a]-1], a))) que.push(pii(ar[ind[a]-1], a));
        if (ind[b]<n && st.count(pii(b, ar[ind[b]+1]))) que.push(pii(b, ar[ind[b]+1]));
    }

    rep(i, n) cout << ar[i] << ' ';
    return 0;
}