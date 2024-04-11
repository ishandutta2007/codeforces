#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
const int MAXN=41;

int n;
P p[MAXN];

P solve() {
	REP(skip,n) {
		int xmn=INT_MAX,xmx=INT_MIN,ymn=INT_MAX,ymx=INT_MIN;
		REP(i,n) if(i!=skip) xmn=min(xmn,p[i].x),xmx=max(xmx,p[i].x),ymn=min(ymn,p[i].y),ymx=max(ymx,p[i].y);
		if(xmn>=xmx||ymn>=ymx||xmx-xmn!=ymx-ymn) continue;
		bool ok=true;
		REP(i,n) {
			bool have=(p[i].x==xmn||p[i].x==xmx||p[i].y==ymn||p[i].y==ymx)&&(xmn<=p[i].x&&p[i].x<=xmx&&ymn<=p[i].y&&p[i].y<=ymx);
			bool want=i!=skip;
			if(have!=want) { 
				//printf("(%d,%d) -> x=[%d..%d] y=[%d..%d] -> err = (%d,%d) have=%d want=%d\n",p[skip].x,p[skip].y,xmn,xmx,ymn,ymx,p[i].x,p[i].y,have?1:0,want?1:0);
				ok=false; break;
			}
		}
		if(!ok) continue;
		//printf("(%d,%d) -> x=[%d..%d] y=[%d..%d]\n",p[skip].x,p[skip].y,xmn,xmx,ymn,ymx);
		return p[skip];
	}
	assert(false); return P();
}

void run() {
	scanf("%d",&n); n=4*n+1;
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	P ans=solve();
	printf("%d %d\n",ans.x,ans.y);
}

int main() {
	run();
	return 0;
}