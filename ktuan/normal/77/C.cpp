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
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

typedef long long LL;
typedef pair<LL,LL> PLL;

int n;
int C[100010];
VI ke[100010];
PLL F[100010];

PLL go(int i, int fi) {
    int z = C[i];
    if(fi > 0) z--;
    
    int sc = 0;
    vector<PLL> v;
    
    Rep(k,ke[i].size()) {
        int j = ke[i][k];
        if(j != fi) {
            ++sc, v.pb(go(j, i));
        }
    }   
    
    //cout << i << " " << z << endl;
    
    if(sc >= z) {
        // cout << i << " " << z << endl;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        LL total = 0;
        Rep(k,z) total += v[k].fi + 1;
        return MP(total,0);
    }
    else {
        /*if(i == 4) {
            cout << "here" << endl;
            cout << v.size() << endl;
        }*/
        LL total = 0;
        Rep(k,v.size()) total += v[k].fi + 1;
        LL rem = z - sc;
        Rep(k,v.size()) if(v[k].se > 0) {
            LL r = min(v[k].se, rem);
            total += r;
            rem -= r;   
        }   
        return MP(total, rem);
    }
}

int main() {
    scanf("%d", &n);
    For(i,1,n) scanf("%d", C+i);
    For(i,1,n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
        ke[v].pb(u);    
    }
    int root;
    scanf("%d", &root);
    PLL res = go(root, -1);
    cout << res.fi * 2 << endl;
    return 0;   
}