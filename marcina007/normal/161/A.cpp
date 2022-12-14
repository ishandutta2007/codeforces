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

#define MAXN 100007
int n,m,x,y,a[MAXN],b[MAXN];
vector<P> V;
set<P> M;
vector<P> res;


int main(){ 
	//in
	scanf("%d%d%d%d",&n,&m,&x,&y);
	FOR(i,1,n){
		scanf("%d",&a[i]);
		V.PB(P(a[i]-x,-i));
		V.PB(P(a[i]+y,MAXN + i));
	}
	FOR(i,1,m){
		scanf("%d",&b[i]);
		V.PB(P(b[i],i));
	}
	//sol
	sort(ALL(V));
	FORE(i,V){
		if(i->Y < 0) M.insert(P(a[-i->Y],-i->Y));
		else if(i->Y > MAXN){
			set<P>::iterator q = M.find(P(a[i->Y-MAXN], i->Y-MAXN));
			if(q != M.end())
				M.erase(q);
		} else {
			if(!M.empty()) {
				res.PB(P(M.begin()->Y, i->Y));
				M.erase(M.begin());
			}
		}
	}
	//out
	printf("%d\n", res.size());
	FORE(i,res) printf("%d %d\n", i->X, i->Y);
    return 0;
}