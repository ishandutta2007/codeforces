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
#define Fit(i,c) for(decltype(c.begin()) i=c.begin();i!=c.end();++i)
#define Fid(i,c) for(decltype(c.rbegin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

const int maxn = 2020;

int n, k;
string a[maxn];
int f[maxn][maxn];
bool isMin[maxn][maxn];

int main() {
    int inf = 1000000;
    cin >> n >> k;
    Rep(i, n) cin >> a[i];
    Rep(i, n) Rep(j, n) {
        int z = a[i][j] == 'a' ? 0 : 1;
        if (i == 0 && j == 0) f[i][j] = z;
        else {
            f[i][j] = inf;
            if (i > 0) f[i][j] = min(f[i][j], z + f[i-1][j]);
            if (j > 0) f[i][j] = min(f[i][j], z + f[i][j-1]);
        }
    }
    Rep(i, n) Rep(j, n) if (f[i][j] <= k) a[i][j] = 'a';
    isMin[0][0] = true;
    string res = "";
    res = res + a[0][0];
    For(tij, 1, 2 * n - 2) {
        char possibleChar = 'z' + 1;
        Rep(i, min(n, tij + 1)) {
            int j = tij - i;
            if (j >= n) continue;
            bool nextToMin = (i > 0 && isMin[i-1][j]) || (j > 0 && isMin[i][j-1]);
            if (a[i][j] < possibleChar && nextToMin) {
                possibleChar = a[i][j];
            }
        }
        res = res + possibleChar;
        Rep(i, min(n, tij + 1)) {
            int j = tij - i;
            if (j >= n) continue;
            bool nextToMin = (i > 0 && isMin[i-1][j]) || (j > 0 && isMin[i][j-1]);
            if (a[i][j] == possibleChar && nextToMin) {
                isMin[i][j] = true;
            }
        }
    }
    cout << res << endl;
    return 0;
}