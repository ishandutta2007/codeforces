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

const int MAXN = 200100;

int n, m, a[MAXN], b[MAXN], l[MAXN], r[MAXN], p[MAXN], pre[MAXN];
int lo[MAXN], hi[MAXN], dp1[MAXN], dp2[MAXN];

int main() { _
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a, a+n), sort(b, b+m);

    int _n = n; n = 0;
    rep(i, _n) {
        if (!i || a[i] != a[i-1]+1) l[++n] = a[i];
        r[n] = a[i];
    }
    for (int i=1; i<=n; i++) p[i] = p[i-1]+r[i]-l[i]+1;

    for (int i=0, pnt=0; i<MAXN; i++) {
        if (pnt<n && p[pnt+1] == i) pnt++;
        lo[i] = pnt;
    }
    for (int i=MAXN-1, pnt=n+1; i>=0; i--) {
        if (pnt>0 && p[pnt-1] == i) pnt--;
        hi[i] = pnt;
    }

    for (int i=1, pnt=0; i<MAXN; i++) {
        if (pnt<m && b[pnt] == i) pre[i] = pre[i-1]+1, pnt++;
        else pre[i] = pre[i-1];
    }

    for (int i=1; i<=n; i++) {
        dp1[i] = dp2[i-1];
        dp2[i] = max(dp2[i], dp2[i-1]);
        rep(k, m) {
            if (b[k] <= r[i]) {
                int x = b[k]+p[i]-r[i]-1;
                if (x>=0) dp1[i] = max(dp1[i], dp2[lo[x]]+pre[r[i]]-pre[b[k]-1]);
            } else {
                int x = b[k]+p[i]-r[i];
                if (x<MAXN) dp2[hi[x]] = max(dp2[hi[x]], dp1[i]+pre[b[k]]-pre[r[i]]);
            }
        }
        dp2[i] = max(dp2[i], dp1[i]);
    }

    cout << dp2[n] << '\n';
    return 0;
}