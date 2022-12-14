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
#define MAXN 157
#define NIC (MAXN/2)

int cnt[MAXN][MAXN],n,t,x,y,res;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
	//sol
    cnt[NIC][NIC] = n;
    bool ok;
    do {
        ok = false;
        REP(i,MAXN) REP(j,MAXN) if(cnt[i][j] >= 4) {
            ok = true;
            int c = cnt[i][j]/4;
            REP(k,4) cnt[i+dx[k]][j+dy[k]] += c;
            cnt[i][j] %= 4;
        }
        REP(i,MAXN) assert(!cnt[i][0] && !cnt[i][MAXN-1] && !cnt[0][i] && !cnt[MAXN-1][i]);
    } while(ok);
	//out
    cin >> t;
    while(t--){
        cin >> x >> y;
        x += NIC; y += NIC;
        if(x < 0 || x >= MAXN || y < 0 || y >= MAXN)
            res = 0;
        else
            res = cnt[x][y];
        cout << res << endl;
    }
	return 0;
}