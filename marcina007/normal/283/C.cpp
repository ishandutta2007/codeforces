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
#define MAXN 307
#define MOD ((LL)(1E9+7))

int n,q,a[MAXN],G[MAXN],in[MAXN],m;
VI coin;
LL t,dp[100007];

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n >> q >> t;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,q) {
        int b,c;
        cin >> b >> c;
        G[b] = c;
        in[c] = 1;
    }
	//sol
    FOR(i,1,n) if(in[i] == 0) {
        VI act;
        for(int j=i; j; j=G[j])
            act.PB(a[j]);
        int mnoz = SZ(act)-1, sum = 0;
        m += SZ(act);
        FORE(j,act) {
            t -= (*j) * mnoz;
            mnoz--;
            sum += *j;
            coin.PB(sum);
        }
    }
//    cout << m << "  " << t << endl;
//    FORE(i,coin) cout << *i << endl;
    if(n != m || t < 0) {cout << 0 << endl; return 0;}
    //dp
    dp[0] = 1;
    FORE(j,coin) FOR(i,0,t){
        if(i+(*j) <= t) {
            dp[i+*j] += dp[i];
            dp[i+*j] %= MOD;
        }
    }
	//out
    cout << dp[t] << endl;
	return 0;
}