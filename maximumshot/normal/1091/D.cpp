#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e6 + 5;
const int mod = 998244353;

int n;
int dp[N];
int fc[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fc[0] = 1;
    dp[0] = 1;

    for(int i = 1;i < N;i++) {
        fc[i] = (1ll * fc[i - 1] * i) % mod;
        dp[i] = 1ll * ((dp[i - 1] + fc[i - 1] - 1) % mod) * i % mod;
    }

    cin >> n;
    cout << dp[n] << "\n";

    return 0;
}