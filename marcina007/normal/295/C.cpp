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
#define MAXN 57

int n,k,a[MAXN],dp[507][MAXN][MAXN],small,big,res;
bool is;
int dw[MAXN][MAXN];


int main(){
REP(n,MAXN){
    dw[n][0]=1;
    FOR(k,1,n) dw[n][k]=(dw[n-1][k-1]+dw[n-1][k])%INF;
}
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> k;
    REP(i,n) cin >> a[i];
    k /= 50;
    REP(i,n) (a[i] == 100 ? big : small)++;
	//sol
    dp[0][0][0] = 1;
    REP(f,500) {
        REP(s,small+1) REP(b,big+1) if(dp[f][s][b]) {
            if(s == small && b == big) {
                cout << f << endl << dp[f][s][b] << endl;
                return 0;
            }
            int sogr = (f&1 ? s : small-s);
            int bogr = (f&1 ? b : big-b);
            REP(ss,sogr+1) REP(bb,bogr+1)
                if(ss + bb > 0 && ss+2*bb <= k) {
                    int news = s + ss * (f&1 ? -1 : 1);
                    int newb = b + bb * (f&1 ? -1 : 1);
                    LL ile = dp[f][s][b];
                    ile *= dw[sogr][ss]; ile %= INF;
                    ile *= dw[bogr][bb]; ile %= INF;
//                    cout << dw[sogr][ss] << endl;
                    dp[f+1][news][newb] += ile;
                    dp[f+1][news][newb] %= INF;
                }
        }
    }
	//out
    cout << -1 << endl << 0 << endl;
	return 0;
}