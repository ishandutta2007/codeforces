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
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 507

int n,G[MAXN][MAXN],best[MAXN][MAXN],x[MAXN];
bool vis[MAXN];
vector<LL> ans;
VI is;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    REP(i,n) REP(j,n) cin >> G[i][j];
    REP(i,n) cin >> x[i];
	//sol
    REP(i,n) REP(j,n) best[i][j] = INF;
    REP(i,n) best[i][i]=0;
    FORD(f,n-1,0) {
        int v = x[f]-1;
        REP(i,n) if(vis[i]) REP(j,n) if(vis[j]) {
       // FORE(i,is) FORE(j,is) {
            mini(best[v][i], G[v][j] + best[j][i]);
            mini(best[i][v], G[j][v] + best[i][j]);
        }
        REP(i,n) if(vis[i]) REP(j,n) if(vis[j])
        //FORE(i,is) FORE(j,is)
            mini(best[i][j], best[i][v] + best[v][j]);
        vis[v] = true;
        LL sum = 0;
        is.PB(v);
//        cout << vis[0] << " " << vis[1] << " " << best[0][1] << " " << best[1][0] << endl;
        REP(i,n) if(vis[i]) REP(j,n) if(vis[j])
        //FORE(i,is) FORE(j,is)
            sum += best[i][j];
        ans.PB(sum);
    }
	//out
    reverse(ALL(ans));
    FORE(i,ans)
        cout << *i << " ";
    cout << endl;
	return 0;
}