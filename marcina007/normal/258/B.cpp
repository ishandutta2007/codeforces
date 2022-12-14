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


string M;
LL dp[13][13][2],ile[13],res;

void go(int p, int s, LL act) {
//	cout << p << "  " << s << " " << act << endl;
	if(p == 7){
		if(s <= 0) return;
		res += act;
		res %= MOD;
		return;
	}
	REP(i,13) if(ile[i]) {
		ile[i]--;
		int ss = s;
		if(p == 0)
			ss += i;
		else
			ss -= i;
		go(p+1, ss, (act*(ile[i]+1)) % MOD);
		ile[i]++;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	//in
	cin >> M;
	//sol
	dp[0][0][0] = 1;
	FOR(i,0,SZ(M)-1) REP(j,12) REP(ok,2) REP(l,10) if(ok || l <= M[i]-'0'){
		LL& x = dp[i+1][j+(l==4)+(l==7)][ok || (l < M[i]-'0')];
		x += dp[i][j][ok];
		x %= MOD;
	}
	REP(i,12) ile[i] = (dp[SZ(M)][i][0] + dp[SZ(M)][i][1]) % MOD;
	ile[0] += MOD - 1;
	ile[0] %= MOD;
//	REP(i,12) cout << i << " " << ile[i] << endl;
	go(0,0,1);
	//out
	cout << res << endl;
	return 0;
}