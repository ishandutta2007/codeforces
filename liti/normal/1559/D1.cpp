//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 1000 * 100 + 100;

set<int> gg[N];

set<pii> gmp[N];

int par[2][N];

int dfind(int t, int u) { 
    return par[t][u] == -1? u : par[t][u] = dfind(t, par[t][u]);
}

void join(int u, int v) { 
    u = dfind(0, u), v = dfind(0, v); 

    if(gg[u].size() > gg[v].size())
        swap(u, v); 

    par[0][u] = v; 

    auto hint = gg[v].begin(); 

    for(auto x: gg[u]) { 
        int root = dfind(1, x); 
        gmp[root].erase( pii(u, x) );
        gmp[root].insert( pii(v, x) );

        hint = gg[v].insert(hint, x);
    }

    gg[u].clear();
}

void merge(int u, int v) {
    u = dfind(1, u); 
    v = dfind(1, v); 

    if( gmp[u].size() > gmp[v].size() )
        swap(u, v); 

    par[1][u] = v;

    auto hint = gmp[v].begin();
    for(auto x: gmp[u])
        hint = gmp[v].insert(hint, x); 

    gmp[u].clear();
}


vector<pii> ans; 

bool test(int u, int v, pii ucand, pii vcand) { 
    if(ucand.first != vcand.first) {
        ans.push_back( pii(ucand.second, vcand.second) );

        merge(u, v); 

        join(ucand.first, vcand.first); 
        return true;
    }
    return false;
}

bool match(int u, int v) { 
    return test(u, v, *gmp[u].begin(), *gmp[v].begin()) ||
        test(u, v, *gmp[u].begin(), *gmp[v].rbegin()) ||
        test(u, v, *gmp[u].rbegin(), *gmp[v].begin());
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    memset(par, -1, sizeof par); 

    int n, m1, m2;
    cin >> n >> m1 >> m2; 

    for(int i = 0; i < n; i++) { 
        gg[i].insert(i);
        gmp[i].insert(pii(i, i));
    }

    for(int i = 0; i < m1; i++) { 
        int u, v;
        cin >> u >> v;
        u--; v--; 

        join(v, u); 
    }

    for(int i = 0; i < m2; i++) { 
        int u, v;
        cin >> u >> v;
        u--; v--; 
        merge(u, v);
    }

    int last = -1; 
    for(int t = 0; t < 25; t++) { 
        for(int i = 0; i < n; i++)
            if(par[1][i] == -1 && i != last) {
                if(last != -1 && !match(last, i)) {
                    //merge(i, last);
                }
                last = dfind(1, i); 
            }
    }


    cout << ans.size() << endl;
    for(auto x: ans) 
        cout << x.first+1 << ' ' << x.second+1 << '\n';

    return 0;
}