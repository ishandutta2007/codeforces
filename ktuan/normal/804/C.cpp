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

VI v[300030];
VI ke[300030];
VI p;
int n, m;
bool used[300030];
int color[300030];

void dfs(int i, int fi) {
    p.pb(i);
    Rep(k, ke[i].size()) {
        int j = ke[i][k];
        if (j != fi) {
            dfs(j, i);
        }
    }
}

int main() {
    cout.sync_with_stdio(false);
    cin >> n >> m;
    For(i, 1, n) {
        int s;
        cin >> s;
        Rep(j, s) {
            int x;
            cin >> x;
            v[i].pb(x);
        }
    }
    Rep(i, n-1) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v); ke[v].pb(u);
    }
    dfs(1, -1);
    Rep(kk, p.size()) {
        int i = p[kk];
        Rep(k2, v[i].size()) {
            int u = v[i][k2];
            if (color[u] != 0) used[color[u]] = true;
        }
        int firstToConsider = 1;
        Rep(k2, v[i].size()) {
            int u = v[i][k2];
            if (color[u] == 0) {
                while (used[firstToConsider]) ++firstToConsider;
                color[u] = firstToConsider;
                used[firstToConsider] = true;
            }
        }
        Rep(k2, v[i].size()) {
            int u = v[i][k2];
            used[color[u]] = false;
        }
    }
    For(i, 1, m) if (color[i] == 0) color[i] = 1;
    int max = *max_element(color + 1, color + 1 + m);
    cout << max << endl;
    For(i, 1, m) cout << color[i] << " "; cout << endl;
    return 0;
}