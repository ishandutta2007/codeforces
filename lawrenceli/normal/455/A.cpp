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

const int MAXN = 100100;
const ll INF = 1e15;

int n, ar[MAXN], freq[MAXN];
ll dp[MAXN], dp2[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        cin >> ar[i];
        freq[ar[i]]++;
    }

    rep(i, MAXN) dp[i] = -INF;
    dp[0] = 0;

    for (int i=1; i<MAXN; i++) {
        if (i>1) dp[i] = ll(i-1)*freq[i-1]+dp2[i-2];
        dp2[i] = max(dp[i], dp2[i-1]);
    }

    cout << dp2[MAXN-1] << '\n';
    return 0;
}