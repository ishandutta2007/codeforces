#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }

const int mod = 1000000007;

int n;
string a[3];
int b[3][10010];

int F[3][10010][2][8];

int solve(int i, int j, int canPush) {
    // cout << i << " " << j << " " << canPush << endl;
    if (j >= n) {
        if (canPush) {
            for (int k = 0; k < 3; ++k) if (!b[k][j-1] && a[k][j-1] == '.') return 0;
            return 1;
        }
        return 0;
    }
    if (j > 0) {
        for (int k = i - 1; k >= 0; --k) if (!b[k][j-1] && a[k][j-1] == '.') return 0;
    }
    if (i >= 3) return solve(0, j + 1, canPush);
    int bit = 0;
    for (int k = i - 1; k >= 0; --k) bit = bit * 2 + (b[k][j] ? 1 : 0);
    if (j > 0) {
        for (int k = 2; k >= i; --k) bit = bit * 2 + (b[k][j - 1] ? 1 : 0);
    }
    int &ret = F[i][j][canPush ? 1 : 0][bit];
    if (ret != -1) return ret;
    ret = 0;
    // if (i > 0) cout << i << " " << b[i][j] << " " << b[i-1][j] << " " << a[i][j] << " "  << a[i-1][j] << endl;
    if (i > 0 && !b[i][j] && !b[i-1][j] && a[i][j] == '.' && a[i-1][j] == '.') {
        // debug;
        b[i][j] = 1;
        b[i-1][j] = 1;
        int newCanPush = canPush;
        if ((i >= 2 && a[i-2][j] == 'O') || (i + 1 < 3 && a[i+1][j] == 'O')) newCanPush = 1;
        ret = ret + solve(i + 1, j, newCanPush);
        if (ret >= mod) ret -= mod;
        b[i][j] = 0;
        b[i-1][j] = 0;
    }

    if (j > 0 && !b[i][j] && !b[i][j-1] && a[i][j] == '.' && a[i][j-1] == '.') {
        b[i][j] = 1;
        b[i][j-1] = 1;
        int newCanPush = canPush;
        if ((j >= 2 && a[i][j-2] == 'O') || (j + 1 < n && a[i][j+1] == 'O')) newCanPush = 1;
        ret = ret + solve(i + 1, j, newCanPush);
        if (ret >= mod) ret -= mod;
        b[i][j] = 0;
        b[i][j-1] = 0;
    }

    ret = ret + solve(i + 1, j, canPush);
    if (ret >= mod) ret -= mod;
    return ret;
}

int main() {
    cin >> n;
    Rep(i, 3) cin >> a[i];
    memset(F, -1, sizeof(F));
    int res = solve(0, 0, 0);
    cout << res << endl;
    return 0;
}