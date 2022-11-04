#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int dp[30][30][10];
string s;

int obtRes (int a, int b, int i) {
    if (i == 6) {
        return a == b ? 0 : 1e9;
    }

    int &res = dp[a][b][i];
    if (res != -1)
        return res;
    res = 1e9;

    int &c = i < 3 ? a : b;

    for (int d = 0; d < 10; d++) {
        c += d;

        if (d == s[i] - '0')
            res = min(res, obtRes(a, b, i+1));
        else
            res = min(res, obtRes(a, b, i+1) + 1);

        c -= d;
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 30; i++)
        for (int j = 0; j < 30; j++)
            for (int k = 0; k < 10; k++)
                dp[i][j][k] = -1;

    cin >> s;
    cout << obtRes(0, 0, 0) << endl;

    return 0;
}