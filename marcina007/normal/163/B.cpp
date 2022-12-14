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
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef pair<P, int> PP;
#define TYP long double

#define MAXN 100007
int k,n,h,m[MAXN],v[MAXN],res[MAXN];
vector<PP> V;

bool test(TYP q){
	int act = 1;
	REP(i,n) {
		if(act <= q * ((TYP)v[V[i].Y]))
			act++;
		if(act == k+1){

			act = 1;
			REP(i,n) {
			if(act <= q * ((TYP)v[V[i].Y]))
				res[act++] = V[i].Y;
			if(act == k+1)
				return true;
			}
		}
	}
//	cout << "!!!" << act << endl;
	return false;
}

int main(){ 
	//in
	scanf("%d%d%d",&n,&k,&h);
	FOR(i,1,n) scanf("%d",&m[i]);
	FOR(i,1,n) scanf("%d",&v[i]);
	//sol
	FOR(i,1,n) V.PB(PP(P(m[i], v[i]), i));
	sort(ALL(V));
	TYP l = 0.0, r = 1E10;
	REP(q,100){
//		cout << l << "-" << r << "  " << q << endl;
		TYP q = (l+r)/2;
		if(test(q))
			r = q;
		else
			l = q;
	}
	//out
	FOR(i,1,k)
		printf("%d ", res[i]);
	printf("\n");
    return 0;
}