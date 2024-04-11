#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <iomanip>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

struct edge {
    int to;
    string znak;
    edge() {
        to = 0;
        znak = "";
    }
    edge(int t, string s) {
        to = t;
        znak = s;
    }
};

int n, k;
vec< vec< edge > > g;

bool check(int l, int r, int ll, int rr, int x, int y) {
    for(int i = 0;i < (int)g[x].size();i++) {
        string s = g[x][i].znak;
        int to = g[x][i].to;
        if(s == "=") {
            if(to != x && to != y) return 0;
        }else if(s == "<") {
            if(to < l || to > r) return 0;
        }else if(s == ">") {
            if(ll < to && to < rr) return 0;
        }else if(s == ">=") {
            if(l <= to && to <= r) return 0;
        }else if(s == "<=") {
            if(to <= ll || to >= rr) return 0;
        }
    }

    for(int i = 0;i < (int)g[y].size();i++) {
        string s = g[y][i].znak;
        int to = g[y][i].to;
        if(s == "=") {
            if(to != x && to != y) return 0;
        }else if(s == "<") {
            if(to < l || to > r) return 0;
        }else if(s == ">") {
            if(ll < to && to < rr) return 0;
        }else if(s == ">=") {
            if(l <= to && to <= r) return 0;
        }else if(s == "<=") {
            if(to <= ll || to >= rr) return 0;
        }
    }

    return 1;
}

bool solve()
{
    scanf("%d %d", &n, &k);

    g.resize(2 * n + 1);

    for(int i = 0;i < k;i++) {
        int u, v;
        string x;
        cin >> u >> x >> v;
        g[u].push_back(edge(v, x));
    }

    vec< vec< LL> > dp(2 * n + 1, vec< LL >(2 * n + 1, 0));

    for(int i = 1;i + 1 <= 2 * n;i++) {
        if(check(i + 1, i, i - 1, i + 2, i, i + 1)) dp[i][i + 1] = 1;
    }

    for(int len = 4;len <= 2 * n;len += 2) {
        for(int l = 1;l + len - 1 <= 2 * n;l++) {
            int r = l + len - 1;
            if(check(l + 1, r - 1, l - 1, r + 1, l, r)) 
                dp[l][r] += dp[l + 1][r - 1];
            if(check(l, r - 2, l - 1, r + 1, r - 1, r))
                dp[l][r] += dp[l][r - 2];
            if(check(l + 2, r, l - 1, r + 1, l, l + 1))
                dp[l][r] += dp[l + 2][r];
        }
    }

    cout << dp[1][2 * n] << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}