#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 3005;
ll dp[MX][MX];
int n, a[MX], b[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(b+1, b+n+1);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1e18;
        for (int j = 1; j <= n; j++)
            dp[i][j] = min(dp[i][j-1], dp[i-1][j] + abs(b[j] - a[i]));
    }    

    cout << dp[n][n] << endl;

    return 0;
}