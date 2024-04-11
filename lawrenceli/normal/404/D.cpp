#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define fi first
#define se second
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i, n) for (int i=(n); --i>=0; )
#define repr(i, l, r) for (int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i, l, r) for (int i=(r), _##i=(l); --i>=_##i; )
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define dwni(i, n) for (__typeof((n).rbegin()) i=(n).rbegin(), _##i=(n).rend(); i!=_##i; ++i)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; ++i)
#define dwnv(i, n) for (int i=((n).size()); --i>=0; )
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 1000100;
const int MOD = 1e9 + 7;

int n;
string s;
int dp[MAXN][4][4];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s; n = s.length();
    rep(i, n)
        if (s[i] == '*')
            s[i] = '3';
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int i=0; i<n; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                for (int l=0; l<4; l++) {
                    if (i > 0 && s[i-1] != '?' && s[i-1] - '0' != k || s[i] != '?' && s[i] - '0' != l) continue;
                    int cnt = 0;
                    if (j == 3) cnt++;
                    if (l == 3) cnt++;
                    if (k != 3 && k != cnt) continue;
                    dp[i+1][k][l] = (dp[i+1][k][l] + dp[i][j][k]) % MOD;
                }

    int ans = 0;
    rep(i, 4)
        rep(j, 4)
            if (j == 3 || j == 0 && i != 3 || j == 1 && i == 3)
                ans = (ans + dp[n][i][j]) % MOD;

    cout << ans << '\n';
    return 0;
}