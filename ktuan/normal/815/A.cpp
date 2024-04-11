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
#define Foreach(i,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }

int m, n;
int a[111][111];
// int minrow[111], mincol[111];
vector<PII> res;

int main() {
    cout.sync_with_stdio(false);
    cin >> m >> n;
    Rep(i, m) Rep(j, n) cin >> a[i][j];
    bool noSolution = false;
    int sum = 0;
    Rep(i, m) Rep(j, n) sum += a[i][j];
    while (sum > 0) {
        if (noSolution) break;
        bool hasZero = false;
        int minv = 1000000000;
        int u, v;
        Rep(i, m) Rep(j, n) {
            if (minv > a[i][j]) {
                minv = a[i][j]; u = i; v = j;
            }
            if (a[i][j] == 0) {
                Rep(v, n) if (a[i][v] > 0) {
                    int minc = 1000000000;
                    Rep(t, m) minc = min(minc, a[t][v]);
                    if (minc == 0) {
                        noSolution = true;
                    } else {
                        sum -= minc * m;
                        Rep(t, m) a[t][v] -= minc;
                        Rep(t, minc) res.pb(MP(1, v));
                    }
                }

                Rep(u, m) if (a[u][j] > 0) {
                    int minr = 1000000000;
                    Rep(t, n) minr = min(minr, a[u][t]);
                    if (minr == 0) {
                        noSolution = true;
                    } else {
                        sum -= minr * n;
                        Rep(t, n) a[u][t] -= minr;
                        Rep(t, minr) res.pb(MP(0, u));
                    }
                }
            }
        }    
        if (minv > 0) {
            sum -= minv * m * n;
            if (m < n) {
                Rep(x, minv)
                Rep(k, m) {
                    res.pb(MP(0, k));
                }
            } else {
                Rep(x, minv)
                Rep(k, n) {
                    res.pb(MP(1, k));
                }
            }
            Rep(k, m) Rep(t, n) a[k][t] -= minv;
        }
    }

    if (noSolution) cout << -1 << endl;
    else {
        cout << res.size() << endl;
        Rep(i, res.size()) {
            cout << (res[i].fi == 0 ? "row" : "col") << " " << res[i].se + 1 << endl;
        }
    }
    
    return 0;
}