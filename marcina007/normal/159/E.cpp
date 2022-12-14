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
typedef vector<lli> VI;

#define MAXN 100007
#define INF ((lli)(1E16))
lli n,c[MAXN],s[MAXN];
map<lli, VI> klocki;
lli naj[MAXN], wyb[MAXN];
lli res=-INF, wyba, wybb; 

int main(){ 
	//in
	scanf("%I64d",&n);
	FOR(i,1,n) scanf("%I64d%I64d",&c[i],&s[i]);
	//sol
	REP(i,MAXN) naj[i] = -INF;
	FOR(i,1,n) klocki[c[i]].PB(s[i]);
	FORE(q,klocki){
		VI v = q->Y;
		sort(ALL(v));
		reverse(ALL(v));
		FOR(i,1,v.size()-1)
			v[i] += v[i-1];

		for(int i=0;i<v.size();i++) {
			if(v[i] + naj[i] > res) {
				res = v[i] + naj[i];
				wyba = q->X;
				wybb = wyb[i];
			}
			if(i+1 < v.size() && v[i+1] + naj[i] > res) {
				res = v[i+1] + naj[i];
				wyba = q->X;
				wybb = wyb[i];
			}
			if(v[i] + naj[i+1] > res) {
				res = v[i] + naj[i+1];
				wybb = q->X;
				wyba = wyb[i+1];
			}
		}
		for(int i=0;i<v.size();i++) {
			if(v[i] > naj[i]){
				naj[i]=v[i];
				wyb[i]=q->X;
			}
		}
	}
	//cout << wyba << " " << wybb << " = " << res << endl;
	//
	vector<P> A,B;
	FOR(i,1,n) if(c[i] == wyba) A.PB(P(s[i], i));
	FOR(i,1,n) if(c[i] == wybb) B.PB(P(s[i], i));
	sort(ALL(A)); sort(ALL(B));
	VI tower;
	int a = A.size() - 1, b = B.size() - 1;
	while(a >= 0){
		tower.PB(A[a--].Y);
		if(b<0) break;
		tower.PB(B[b--].Y);
	}
	//out
	cout << res << endl;
	cout << tower.size() << endl;
	REP(i,tower.size())
		printf("%I64d ", tower[i]);
	printf("\n");
    return 0;
}