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
#define DEBUG 0
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const LL INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 200007

int n,h[MAXN],next[MAXN],deg[MAXN],size[MAXN],ojc[MAXN];
VI G[MAXN],GG[MAXN];
LL dp[MAXN];
bool is[MAXN];

void sety(int x,int o){
    deg[x] = SZ(G[x]);
    size[x] = 1;
    FORE(i,G[x]) if(*i != o){
        h[*i] = h[x] + 1;
        ojc[*i] = x;
        GG[x].PB(*i);
        sety(*i, x);
        next[x] = next[*i];
        size[x] += size[*i];
    }
    if(deg[x] != 2)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        next[x] = x;
}

LL go(int v,int w);

LL go(int v) {
    if(is[v]) return dp[v];
    if(size[v]%2 == 1) return 0;
    debug(v);
    if(!v) return 1;
    if(deg[next[v]] == 1)
        return size[v]/2;
    LL ans = 0;
    //w prawo
    int w = next[v];
    int d = h[w]-h[v];
    debug(w);
    debug(d);
    REP(i,2) {
        int x = GG[w][0];
        debug(x);
        if(deg[next[x]] <= 1 && size[x] == d-1)
            ans += go(GG[w][1]);
        else REP(j,2) {
            int l = GG[x][0];
            int r = GG[x][1];
            if(deg[next[l]] <= 1 && size[l] == d && (j == 0 || l != r)) {
//                cout << "move " << v << " " << w << " " << x << " " << l << " -> " << r << " " << GG[w][1] << endl;
                ans += go(r, GG[w][1]);
            }
            swap(GG[x][0], GG[x][1]);
        }
        swap(GG[w][0], GG[w][1]);
    }
    //w dol
    debug(v << " " << ans << "pre");
    if(deg[v] == 2) {//!!!!!!!!!!!!!!!!!!
        if(deg[GG[v][0]] <= 2)
            ans += go(GG[GG[v][0]][0]);
    }
    debug(v << " " << ans);
    dp[v]=ans%INF;
    is[v]=true;
    return ans%INF;
}

LL go(int v,int w) {
    debug(v << " " << w)
    if((size[v]+size[w])%2 == 1) return 0;
    if(v == 0) return go(w);
    if(w == 0) return go(v);
    if(deg[v]>2 || deg[w]>2) return 0;
    return go(GG[v][0], GG[w][0]);
}

LL res;

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n;
    FOR(i,1,2*n-1) {
        int a,b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
//    sety(1,1);
//        FOR(i,1,2*n) REP(j,2) GG[i].PB(0);
//    debug(go(1));
//    return 0;
	//sol
    if(n == 1){cout << 2 << endl; return 0;}
    FOR(i,1,2*n) if(SZ(G[i]) > 3) {cout << 0 << endl; return 0;}
    FOR(root,1,2*n) if(SZ(G[root]) == 3) {
        sety(root, root);
        FOR(i,1,2*n) REP(j,2) GG[i].PB(0);
        VI sons = G[root];
        sort(ALL(sons));
        do{
            if(deg[sons[1]] == 1) {
                    res = (res + go(sons[0]) * go(sons[2]))%INF;
            } else { //deg=2,3
                REP(i,2) {
                    res = (res + go(sons[0], GG[sons[1]][0]) * go(sons[2], GG[sons[1]][1]))%INF;
                    swap(GG[sons[1]][0], GG[sons[1]][1]);
                }
            }
        }while(next_permutation(ALL(sons)));
        cout << (2*res)%INF << endl;
        return 0;
    }
	//out
    cout << 2*(2+(LL)n*((LL)n-1))%INF << endl;
	return 0;
}