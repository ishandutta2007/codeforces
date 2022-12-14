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
typedef long long int LL;
typedef long long unsigned llu;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<string> VS;
template<class C> inline void mini(C& a, C b) {a=min(a,b);}
template<class C> inline void maxi(C& a, C b) {a=max(a,b);}
#define INF ((lli)1E9)
#define MAXN 100000
#define EPS 1E-9

int h1, h2, n;
int what[2][MAXN+7];
int v[MAXN],res,a[MAXN],b[MAXN];
char c[MAXN];
ld pocz[MAXN];

int main(){ 
	std::ios_base::sync_with_stdio(0);
	//in
	cin >> h1 >> h2 >> n;
	FOR(i,1,n)
		cin >> v[i] >> c[i] >> a[i] >> b[i];
	//sol
	FOR(odb,0,300) REP(q,2){
		ld pion = ((LL)odb)*100.0 + (q ? 100-h1 : h1) + ((q+odb)%2 ? 100-h2 : h2);
		ld poz = MAXN;
		ld wsp = poz / pion;
		ld skok = 200.0 * wsp;
		int ile=0;
//	cout << odb << " " << q << "        " << skok << endl;
		int act = 0;
		if(q) {
			pocz[1] = (100-h1) * wsp;
			pocz[0] = pocz[1] + 100.0 * wsp;
		} else{
			pocz[0] = h1 * wsp;
			pocz[1] = pocz[0] + 100.0 * wsp;
		}
		FOR(i,1,n) {
			int sc = (c[i] == 'T');
			ld aa = a[i] - pocz[sc] - EPS;
			ld bb = b[i] - pocz[sc] + EPS;
			if(bb < 0) continue;
			LL a3 = (LL)floor(aa / skok);
			LL b3 = (LL)floor(bb / skok);
			a3 = max(a3, -1LL);
	//		cout << i << " " << a[i] << " " << b[i] << " " << c[i] << "     " << a3 << "  "<< b3 << "    " << a3 << " " << b3 << "  price " << v[i] << endl;
			if(b3 > a3+1) {act=0; break;}
			if(b3 == a3 + 1) act += v[i], ile++;
		}
//		if(act > res) {
//			cout << act << ": " << q << " " << odb << endl;
//		}
		if(ile == odb+1) maxi(res, act);
	}
	//out
	cout << res << endl;
  return 0;
}