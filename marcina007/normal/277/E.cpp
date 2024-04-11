#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef double LD;
typedef pair<LD, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN (1007) //*2 jesli ograniczenia na wierzcholkach

struct MinCostMaxFlow { // indeksy: 1..n, dozwolone krawedzie wielokrotne, LL jesli trzeba!
    int n, e[MAXN+1];
    LD fi[MAXN+1], dis[MAXN+1];
    VI f, c, v, G[MAXN+1];
    vector<LD> k;
    bool vis[MAXN+1];

    void init(int n_) {
        n = n_;
        f.clear();
        c.clear();
        v.clear();
        k.clear();
        CLR(fi);
        CLR(dis);
        CLR(e);
        FOR(i,1,n) G[i].clear();
    }

    void add(int a,int b,int cc,LD kk) {
        G[a].PB(SZ(v)); v.PB(b); c.PB(cc); k.PB(kk); f.PB(0);
        G[b].PB(SZ(v)); v.PB(a); c.PB(0); k.PB(-kk); f.PB(0);
    }

    P flow(int s,int d) { //returns (vol, cost)
        int vol = 0;
        LD cost = 0;
        while(1) {
            FOR(i,1,n) dis[i] = INF;
            dis[s] = 0;
            CLR(vis);
            dis[0]=INF;
            while(1) {
                int x = 0;
                FOR(i,1,n) if(!vis[i] && dis[i]<dis[x]) x = i;
                if(!x) break;
                vis[x] =true;
                FORE(i,G[x]) if(f[*i] < c[*i]) {
                    int w = v[*i];
                    LD dd = dis[x] + k[*i] + fi[x] - fi[w];
                    assert(dd >= dis[x]-1E-6);
                    if(dd < dis[w]) {
                        dis[w] = dd;
                        e[w] = *i;
                    }
                }
            }
            if(dis[d] == INF) break;
            int aug = INF;
            for(int i = d; i != s; i = v[1 ^ e[i]]) mini(aug, c[e[i]] - f[e[i]]);
            for(int i = d; i != s; i = v[1 ^ e[i]]) f[e[i]] += aug, f[1 ^ e[i]] -= aug;
            vol += aug;
            FOR(i,1,n) if(dis[i] != INF) fi[i] += dis[i];
        }
        REP(i,SZ(f)) if(f[i] > 0) cost += f[i] * k[i];
        return P(cost, vol);
    }
};

int n,x[MAXN],y[MAXN];
MinCostMaxFlow f;

int down(int xx){return 2*xx-1;}
int up(int xx){return 2*xx;}

int main(){
    ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    //in
    cin >> n;
    FOR(i,1,n) cin >> x[i] >> y[i];
    //sol
    int in = 2*n + 1;
    int out = 2*n + 2;
    f.init(out);
    FOR(i,1,n) f.add(in, down(i), 1, 0);
    FOR(i,1,n) f.add(up(i), out, 2, 0);
    FOR(i,1,n) FOR(j,1,n) if(y[j] > y[i])
        f.add(down(i), up(j), 1, sqrtl(SQR(x[i]-x[j])+SQR(y[i]-y[j])));
    //out
    P p = f.flow(in,out);
    if(p.Y != n-1) cout << -1 << endl;
    else cout << p.X << endl;
    return 0;
}