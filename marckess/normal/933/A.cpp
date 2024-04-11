#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int acu[2][2005], n, a[2005];
int dp[2005][2005];

int precal (int i, int j) {
    if (i > j)
        return 0;
    
    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = max(
                        precal(i+1, j) + int(a[i] == 2),
                        precal(i, j-1) + int(a[j] == 1)
                    );
}

int flan () {
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            mx = max(
                    mx,
                    acu[0][i-1] + precal(i, j) + acu[1][n] - acu[1][j]
                );
        }
    }
    return mx;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    fill(acu[0], acu[0]+n, 0);
    fill(acu[1], acu[1]+n, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        acu[a[i]-1][i] = 1;
    } 

    for (int i = 1; i <= n; i++) {
        acu[0][i] += acu[0][i-1];
        acu[1][i] += acu[1][i-1];
    }

    for (int j = 0; j < 2005; j++)
        for (int k = 0; k < 2005; k++)
            dp[j][k] = -1;

    cout << flan() << endl;

    return 0;
}