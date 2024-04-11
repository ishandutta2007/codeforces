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

int m, n, s;
VI ke[5050];
bool visited[5050];
bool shouldCheck[5050];

void dfs(int i) {
    visited[i] = true;
    Rep(k, ke[i].size()) {
        int j = ke[i][k];
        if (!visited[j]) dfs(j);
    }
}

int main() {
    cin >> n >> m >> s;
    Rep(i, m) {
        int u, v;
        cin >> u >> v;
        ke[u].pb(v);
    }
    dfs(s);
    For(i, 1, n) if (!visited[i]) {
        shouldCheck[i] = true;
        dfs(i);
    }
    memset(visited, 0, sizeof(visited));
    dfs(s);
    int res = 0;
    Ford(i, n, 1) if (!visited[i] && shouldCheck[i]) {
        ++res;
        dfs(i);
    }    
    cout << res << endl;
    return 0;
}