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

int bp(const vec< int > & a, int l, int r) {
    if(a.empty()) return 0;
    int bl, br, bm, ll, rr;
    bl = 0, br = (int)a.size() - 1;
    
    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(a[bm] < l) bl = bm + 1;
        else br = bm;
    }

    if(a[bl] >= l) ll = bl;
    else if(a[br] >= l) ll = br;
    else return 0;

    bl = 0, br = (int)a.size() - 1;

    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(a[bm] > r) br = bm - 1;
        else bl = bm;
    }

    if(a[br] <= r) rr = br;
    else if(a[bl] <= r) rr = bl;
    else return 0;

    return (rr - ll + 1);
}

int n, k, timer = 0;
vec< vec< int > > g;
vec< int > in, out, hh, p;
vec< vec< int> > h;

void dfs(int v, int par = -1, int H = 0) {
    in[v] = timer++;
    h[H].push_back(in[v]);
    hh[v] = H;
    p[v] = par;
    for(int i = 0;i < (int)g[v].size();i++) {
        int to = g[v][i];
        if(to != par) dfs(to, v, H + 1);
    }
    out[v] = timer++;
}

bool solve()
{
    scanf("%d %d", &n, &k);

    g.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    h.resize(n + 1);
    hh.resize(n + 1);
    p.resize(n + 1);

    for(int u, v, i = 0;i < n - 1;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);

    LL ans = 0;

    for(int i = 0;i <= n;i++) {
        sort(ALL(h[i]));
    }
    
    for(int i = 1;i <= n;i++) {
        int v = i, c = 0, last = -1; 
        while(v != -1 && c <= k) {
            if(c == k) {
                ans++;
                break;
            }
            
            if(hh[v] + k - c <= n) ans += bp(h[hh[v] + k - c], in[v], out[v]);
            if(last != -1 && hh[last] + k - c - 1 <= n) ans -= bp(h[hh[last] + k - c - 1], in[last], out[last]);

            last = v;
            v = p[v];
            c++;
        }
    }
    
    cout << ans / 2 << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}