#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const ll inf = 10000000000000ll;

vector<pair<int,int> > g[100000];
vector<int> ans;
set<pair<ll,int> > q;

ll d[100000];
int p[100000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, m;
    scanf("%d%d",&n,&m);
    REP(i,m) {
        int v1, v2, cost;
        scanf("%d%d%d",&v1,&v2,&cost);
        v1--, v2--;
        g[v1].pb(mp(v2,cost));
        g[v2].pb(mp(v1,cost));
    }
    REP(i,n) d[i] = inf;
    d[0] = 0;
    q.insert(mp(d[0],0));
    while (!q.empty()) {
        int v = q.begin()->sc;
        q.erase(q.begin());
        
        REP(i,sz(g[v])) {
            int to = g[v][i].fs, cost = g[v][i].sc;
            if (d[v]+cost<d[to]) {
                q.erase(mp(d[to],to));
                d[to] = d[v]+cost;
                p[to] = v;
                q.insert(mp(d[to],to));
            }
        }
    }
    if (d[n-1]==inf) 
        puts("-1");
    else {
        int c = n-1;
        while (c!=0) {
            ans.pb(c+1);
            c = p[c];
        }
        ans.pb(1);
        FORP(i,sz(ans)-1,0) printf("%d ",ans[i]);
    }
}