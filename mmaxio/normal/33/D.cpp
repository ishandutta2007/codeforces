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

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

const int inf = 1000000001;

vector<int> g[1001];
bool use[1001];
int dist[1001][1001];
int where[1000];

int x[1000], y[1000], xc[1000], yc[1000], r[1000];

void DFS(int v, int orig, int dd) {
    dist[v][orig] = dd;
    use[v] = 1;
    REP(i,sz(g[v])) if (!use[g[v][i]]) {
        DFS(g[v][i],orig,dd+1);
    }
}

bool insCirc(int i, int j) {
    if (r[i] >= r[j]) return 0;
    return sqr(ll(xc[i])-xc[j]) + sqr(ll(yc[i])-yc[j]) < sqr(ll(r[j]) - r[i]);
}

bool insPnt(int i, int j) {
    return sqr(ll(x[i])-xc[j]) + sqr(ll(y[i])-yc[j]) < sqr(ll(r[j]));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n, m, k, v1, v2;
    scanf("%d%d%d",&n,&m,&k);
    REP(i,n) scanf("%d%d",&x[i],&y[i]);
    REP(i,m) scanf("%d%d%d",&r[i],&xc[i],&yc[i]);

    REP(i,m) {
        int rmin = inf, tmp;
        REP(j,m) if (r[j] < rmin && insCirc(i,j)) {
            rmin = r[j], tmp = j;
        }

        //cerr << i << ' ' << (rmin == inf ? m : tmp) << '\n';
        if (rmin == inf) g[m].pb(i), g[i].pb(m);
        else g[tmp].pb(i), g[i].pb(tmp);
    }

    REP(i,n) {
        int rmin = inf, tmp;
        REP(j,m) if (r[j] < rmin && insPnt(i,j)) {
            rmin = r[j], tmp = j;
        }
        if (rmin == inf) where[i] = m;
        else where[i] = tmp;

        //cerr << where[i] << ' ';
    }

    REP(i,m+1) clean(use), DFS(i,i,0);

    REP(i,k) {
        scanf("%d%d", &v1, &v2);
        printf("%d\n",dist[where[v1-1]][where[v2-1]]);
    }
}