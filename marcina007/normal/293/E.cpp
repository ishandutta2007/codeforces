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
#include<bitset>
#include<stack>
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
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

vector<P> G[MAXN];
bool del[MAXN];

int size, roz[MAXN];
P best;

int dfs(int x, int o) {
    roz[x] = 1;
    FORE(i,G[x]) if(i->X != o && !del[i->X])
        roz[x] += dfs(i->X, x);
    return roz[x];
}

void go(int x,int o) {
    int act = 0;
    maxi(act, size - roz[x]);
    FORE(i,G[x]) if(i->X != o && !del[i->X]) {
        go(i->X, x);
        maxi(act, roz[i->X]);
    }
    mini(best, P(act, x));
}

int find(int x) {
    size = dfs(x, x);
    best = P(INF,INF);
    go(x,x);
    return best.Y;
}

vector<P> v;

void dfs2(int x,int o,int l,int w) {
    v.PB(P(w,l));
    FORE(i,G[x]) if(i->X != o && !del[i->X])
        dfs2(i->X, x, l + 1, w + i->Y);
}

struct DP{
    typedef int TYP;
    TYP tab[MAXN];

    void add(int x, TYP w){
        while(x < MAXN) {tab[x] += w; x += x&(-x);}
    }

    TYP get(int x){
        TYP res = 0;
        while(x) {res += tab[x]; x -= x&(-x);}
        return res;
    }

    TYP get(int a,int b){return get(b)-get(a-1);}
};

DP dp;

LL count2(int x,int L,int W) {
    //cout << "count " << x << " " << L << " " << W << endl;
    LL res = 0;
    v.clear();
    dfs2(x,x,0,0);
    int it = SZ(v) - 1;
    sort(ALL(v));
    reverse(ALL(v));
    VI add;
    FORE(i,v) {
        //cout << "p " << i->X << " " << i->Y << endl;
        while(it >= 0 && v[it].X + i->X <= W) {
            dp.add(v[it].Y + 1, 1);
            add.PB(v[it].Y + 1);
            it--;
        }
        if(L - i->Y + 1 > 0) res += dp.get(L - i->Y + 1);
    }
    FORE(i,add) dp.add(*i, -1);
    //cout << res << endl;
    return res;
}

LL res = 0;
int n,l,w;

void solve(int x) {
    //cout << "solve " << x << endl;
    x = find(x);
    //cout << "root " << root << endl;
    res += count2(x, l, w) - 1;
    del[x] = true;
    FORE(i,G[x]) if(!del[i->X])
        res -= count2(i->X, l - 2, w - 2 * i->Y);
    FORE(i,G[x]) if(!del[i->X])
        solve(i->X);
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> l >> w;
    FOR(a,2,n) {
        int b,ww;
        cin >> b >> ww;
        G[a].PB(P(b,ww));
        G[b].PB(P(a,ww));
    }
	//sol
    solve(1);
	//out
    cout << res/2 << endl;
	return 0;
}