#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;
int dp[55][2][2][2];
string s[55];

int obtRes (int i, int j, int k, int l) {
    if (i == n) {
        if (j * k * l)
            return 0;
        return 1e9;
    }

    int &res = dp[i][j][k][l];
    if (res != -1)
        return res;
    res = 1e9;

    for (int p = 0; p < m; p++) {
        if ('0' <= s[i][p] && s[i][p] <= '9')
            res = min(res, obtRes(i+1, 1, k, l) + min(p, m-p));
        else if ('a' <= s[i][p] && s[i][p] <= 'z')
            res = min(res, obtRes(i+1, j, 1, l) + min(p, m-p));
        else
            res = min(res, obtRes(i+1, j, k, 1) + min(p, m-p));
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 55; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = -1;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    cout << obtRes(0, 0, 0, 0) << endl;

    return 0;
}