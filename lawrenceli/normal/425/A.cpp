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

const int MAXN = 205;
const int INF = 1e9;

int n, k, a[MAXN];
int v1[MAXN], v2[MAXN];
int s1, s2;
int ans = -INF;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(l, n)
        for (int r=l+1; r<=n; r++) {
            s1 = s2 = 0;
            int sum = 0;
            rep(i, n)
                if (l <= i && i < r) v1[s1++] = a[i], sum += a[i];
                else v2[s2++] = a[i];
            sort(v1, v1+s1); reverse(v1, v1+s1);
            sort(v2, v2+s2);
            ans = max(ans, sum);
            rep(i, k) {
                if (!s1 || !s2) break;
                sum += v2[--s2]-v1[--s1];
                ans = max(ans, sum);
            }
        }
    cout << ans << '\n';
    return 0;
}