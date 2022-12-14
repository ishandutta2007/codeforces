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
#define MAXN 100007

LL pot(LL a,int n){
	if(!n) return 1;
	return n%2 ? (pot(a,n-1)*a)%MOD : pot((a*a)%MOD,n/2);
}

int n,x,licz[MAXN],sum[MAXN];
VI dziel[MAXN];
LL res,act;

int main(){
	ios_base::sync_with_stdio(false);
	//in
	cin >> n;
	REP(i,n) {
		cin >> x;
		licz[x]++;
	}
	//sol
	FORD(i,MAXN-2,1)
		sum[i] = sum[i+1] + licz[i];
	FOR(i,1,MAXN-1)
		for(int j=i; j<MAXN; j+=i)
			dziel[j].PB(i);
	FOR(i,1,MAXN-1) {
		act = 1;
		int last = MAXN-1;
		int liczer = SZ(dziel[i]);
		reverse(ALL(dziel[i]));
		FORE(j,dziel[i]) {
			int ile = sum[*j] - sum[last];
			last = *j;
			LL y = pot(liczer, ile);
			if(liczer == SZ(dziel[i])) {
				y += (MOD - pot(liczer-1, ile));
				y %= MOD;
			}
//			if(i<10) cout << i << " " << *j << " " << act << "  liczer  " << liczer << " " << y << "   " << ile << endl;
			act *= y;
			act %= MOD;
			liczer--;
		}
		res += act;
		res %= MOD;
	}
	//out
	cout << res << endl;
	return 0;
}