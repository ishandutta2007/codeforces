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
typedef pair<LL, LL>P;
//typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1007

int n,m,k,pl[MAXN][MAXN],pl2[MAXN][MAXN],res,pocz,perm[11],kk,act;
bool vis[11];
vector<P> M;

int mnoz(LL a,LL b){ return ((a*b)%INF); }

void go(int poz,int val) {
    vector<P> next;
    FOR(c,1,k) if(val == c || val == 0) {
        FORE(i,M) if((act=((i->X>>(3*c))&7)) > poz){
            int mn = 1;
            bool ok = true;
            if(!vis[c] && act == 7) {
                mn = 0;
                FOR(cc,1,k) if(!vis[cc] && (((i->X>>(3*cc))&7) == 7)) {
                    if(cc < c) {ok= false; break;}
                    mn ++;
                }
            } 
            if(!ok) continue;
            LL v = i->X&(~(7LL<<(3*c)));
            v |= ((LL)poz) << (3*c);
            next.PB(P(v, mnoz(i->Y, mn)));
//            next[v] += i->Y;
//            next[v] %= INF;
        }
    }
    sort(ALL(next));
    M.clear();
    FORE(i,next)
        if(!M.empty() && M.back().X == i->X) {
            M.back().Y += i->Y;
            M.back().Y %= INF;
        } else
            M.PB(*i);
}
int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m >> k;
    REP(i,n) REP(j,m) cin >> pl[i][j];
	//speedup
    if(n+m-1 > k) {cout << 0 << endl; return 0;}
    if(n < m) {
        REP(i,n) REP(j,m) pl2[j][i] = pl[i][j];
        swap(n,m);
        REP(i,n) REP(j,m) pl[i][j] = pl2[i][j];
    }  
    REP(i,n) REP(j,m) vis[pl[i][j]] = true;
    //sol 
    REP(i,n) REP(j,m) vis[pl[i][j]] = true;
    LL v;
    FOR(i,1,k) v |= 7LL<<(3*i);
    M.PB(P(v,1));
    REP(i,n) REP(j,m) {//if((i != 0 || j != 0) && (i != n-1 || j != m-1)) {
//        cout << "! " << i << " " << j << " " << M.size() << endl;
        go(j, pl[i][j]);
    }
	//out
    FORE(i,M) {
        res += i->Y;
        res %= INF;
    }
    cout << res << endl;
	return 0;
}