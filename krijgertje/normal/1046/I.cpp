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

const int MAXN=100000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };
P operator-(const P &a,const P &b) { return P(a.x-b.x,a.y-b.y); }
P operator+(const P &a,const P &b) { return P(a.x+b.x,a.y+b.y); }
ll dst2(const P &d) { return (ll)d.x*d.x+(ll)d.y*d.y; }
ll dst2(const P &a,const P &b) { return dst2(b-a); }


int n;
int d1,d2;
P a[MAXN],b[MAXN];

bool can(const P &before,const P &delta,int want) { // norm(before+t*delta)<=want for 0<=t<=1
	if(dst2(before)<=want*want||dst2(before+delta)<=want*want) return true;
	// (before.x+t*delta.x)*(before.x+t*delta.x)+(before.y+t*delta.y)*(before.y+t*delta.y)<=want*want
	ll A=(ll)delta.x*delta.x+(ll)delta.y*delta.y;
	ll B=(ll)2*before.x*delta.x+(ll)2*before.y*delta.y;
	ll C=(ll)before.x*before.x+(ll)before.y*before.y;
	// f(t)=A*t*t+B*t+C<=want*want -> min(f(t)) -> 2*t*A+B=0 -> t=-B/(2*A) -> f(t)=C-B*B/(4*A)
	//printf("\there (%lld*t^2+%lld*t+%lld<=%lld)\n",A,B,C,(ll)want*want);
	return A>0&&0<=-B&&-B<=2*A&&4*A*C-B*B<=4*A*want*want;
}


// state: 1=said hello since last time we were further apart than d2
int solve() {
	int state=dst2(a[0],b[0])<=d1*d1?1:0; int ret=state;
	FOR(i,1,n) {
		P before=b[i-1]-a[i-1],after=b[i]-a[i],delta=after-before;
		//printf("sqrt((%d+t*%d)^2+(%d+t*%d)^2)\n",before.x,delta.x,before.y,delta.y);
		if(state==0&&can(before,delta,d1)) ++ret,state=1;//,printf("hello!\n");
		if(state==1&&dst2(after)>d2*d2) state=0;//,printf("far\n");
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%d%d",&d1,&d2);
	REP(i,n) scanf("%d%d%d%d",&a[i].x,&a[i].y,&b[i].x,&b[i].y);

	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}