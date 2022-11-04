#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int t, n, k, dp[3][105];
char c[3][105];

int obtRes (int i, int j) {
    if (i < 0 || i >= 3)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (j && j+j*2-2 < n && (c[i][j+j*2] != '.' || c[i][j+j*2-1] != '.' || c[i][j+j*2-2] != '.')) {
        return dp[i][j] = 0;
    }

    if (j == n-1)
        return dp[i][j] = 1;

    return dp[i][j] = (j+j*2+1 >= n || c[i][j+j*2+1] == '.')
                    && (obtRes(i-1, j+1) || obtRes(i, j+1) || obtRes(i+1, j+1));
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n >> k >> c[0] >> c[1] >> c[2];

        FOR (i, 3) {
            fill(dp[i], dp[i]+105, -1);
            for (int j = n; j < 105; j++)
                c[i][j] = '.';
        }

        FOR (i, 3)
            if (c[i][0] == 's')
                if (obtRes(i, 0))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
    }

    return 0;
}