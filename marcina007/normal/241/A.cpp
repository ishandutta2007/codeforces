#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <complex>
#include <stack>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef long long unsigned llu;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<string> VS;
template<class C> inline void mini(C& a, C b) {a=min(a,b);}
template<class C> inline void maxi(C& a, C b) {a=max(a,b);}
#define INF ((lli)1E9)
#define MAXN 1007
int m,k,d[MAXN],s[MAXN],res,naj,nak,bak;


int main(){ 
	std::ios_base::sync_with_stdio(0);
	//in
	cin >> m >> k;
	FOR(i,1,m) cin >> d[i];
	FOR(i,1,m) cin >> s[i];
	//sol
	FOR(i,1,m) {
		bak += s[i];
		maxi(naj, s[i]);
		while(bak < d[i]) {
			res += k;
			bak += naj;
		}
		bak -= d[i];
		res += d[i];
	}
	//out
	cout << res << endl;
  return 0;
}