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

int n, b;
int c[5050], d[5050];
VI ke[5050];
int f[2][5050][5050];
int C[5050];

void dfs(int i) {
    C[i] = 1;
    Rep(k, ke[i].size()) {
        int j = ke[i][k];
        dfs(j);
        C[i] += C[j];
    }
}

void solve(int i) {
    vector<PII> v;
    Rep(k, ke[i].size()) {
        int j = ke[i][k];
        solve(j);
        v.pb(MP(C[j], j));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    f[0][i][0] = 0;
    f[1][i][0] = 1000000001;
    f[0][i][1] = c[i];
    f[1][i][1] = c[i] - d[i];
    For(w, 2, C[i]) f[0][i][w] = f[1][i][w] = 1000000001;
    int sz = 1;
    Rep(k, v.size()) {
        int j = v[k].se;
        sz += C[j];
        if (k == 0) {
            Ford(w, sz, 0) {
                Ford(t, min(C[j], w), 1) {
                    f[0][i][w] = min(f[0][i][w], f[0][i][w - t] + f[0][j][t]);
                    f[1][i][w] = min(f[1][i][w], f[1][i][w - t] + min(f[0][j][t], f[1][j][t]));
                    if (w - t >= 2) break;
                }
            }    
        } else {
            Ford(w, sz, 0) {
                For(t, 1, C[j]) if (w >= t) {
                        f[0][i][w] = min(f[0][i][w], f[0][i][w - t] + f[0][j][t]);
                        f[1][i][w] = min(f[1][i][w], f[1][i][w - t] + min(f[0][j][t], f[1][j][t]));
                }
            }  
        }
    }
}

int main() {
    cout.sync_with_stdio(false);
    cin >> n >> b;
    Rep(i, n) {
        cin >> c[i] >> d[i];
        if (i > 0) {
            int x;
            cin >> x;
            ke[x-1].pb(i);
        }
    }    
    dfs(0);
    solve(0);
    int best = 0;
    For(i, 0, n) if (f[0][0][i] <= b || f[1][0][i] <= b) {
        // cout << i << " " << f[0][0][i] << " " << f[1][0][i] << endl;

        best = i;
    }
    cout << best << endl;
    return 0;
}