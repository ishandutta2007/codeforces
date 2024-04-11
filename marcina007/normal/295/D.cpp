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
const LL MOD=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 2007

LL n,m,dp[MAXN][MAXN],res;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m;
    m--;
    if(m<=0) {cout << 0 << endl; return 0;}
	//sol
    FOR(p,1,MAXN-1) {
        LL sum = 0, pref = 0;
        FOR(l,1,MAXN-1) {
            pref += dp[p-1][l]; pref %= MOD;
            sum += pref; sum %= MOD;
            dp[p][l] = sum + 1; dp[p][l] %= MOD;
        }
    }
//    cout << dp[1][1] << " " << dp[2][1] << endl;
    FOR(r,1,n) FOR(s,1,m) {
        res += ((dp[r][s] * dp[n-r+1][s]) % MOD) * (m-s+1);
        res %= MOD;
        if(r<n) {
            res -= ((dp[r][s] * dp[n-r][s]) % MOD) * (m-s+1);
            res %= MOD;
        }
    }
	//out
    res %= MOD;
    if(res<0) res += MOD;
    cout << res << endl;
	return 0;
}