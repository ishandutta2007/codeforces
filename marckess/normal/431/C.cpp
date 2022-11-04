#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int n, k, d, mod = 1e9+7;
vector<vi> dp(105, vi(2, -1));

ll obtRes ( int n, int f ) {
    if ( n < 0 || (n == 0 && f == 0) )
        return 0;

    if ( n == 0 && f ) {
        return 1;
    }

    if ( dp[n][f] > -1 )
        return dp[n][f];

    ll res = 0;
    for (int i = 1; i <= k; i++)
        res += obtRes ( n-i, i >= d ? 1 : f );

    return dp[n][f] = res % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k >> d;

    ll res = 0;
    for ( int i = 1; i <= k; i++ )
        res += obtRes ( n-i,  i >= d ? 1 : 0 );

    cout << res % mod << endl;

    return 0;
}