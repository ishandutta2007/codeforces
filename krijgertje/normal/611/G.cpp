#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500000;
const int MOD=1000000007;
typedef struct P { int x,y; } P;
ll operator^(const P &a,const P &b) { return (ll)a.x*b.y-(ll)a.y*b.x; }

int n;
P p[2*MAXN+1];
ll val[2*MAXN];
ll sum[MAXN+1];
ll sumsum[2*MAXN+2];
ll xsum[2*MAXN+1];
ll ysum[2*MAXN+1];

// CCW: (b-a)^(c-a) = (bx-ax)*(cy-ay)-(cx-ax)*(by-ay)
// CCW: ax*by-bx*ay+bx*cy-cx*by+cx*ay-ax*cy = a^b+b^c+c^a
// a^b+b^c+c^d+d^e+e^f+f^g+g^a
ll area(int a,int b) { ll add=0; if(b>=n) add+=sum[n],b-=n; return sum[b]-sum[a]+(p[a]^p[b])+add; }
// area(a,b)+area(a,b+1)+...+area(a,a+c) = sum[b]-sum[a]+a^b+sum[b+1]-sum[a]+a^(b+1)+...+sum[a+c]-sum[a]+a^c = sum[b]+...+sum[c]-(c-b+1)*sum[a]+a^b+a^(b+1)+...+a^c
// = sumsum[c+1]-sumsum[b]-(c-b+1)*sum[a]+a.x*(ysum[c+1]-ysum[b])-a.y*(xsum[c+1]-xsum[b])
ll sumarea(int a,int b,int c) { ll ret=sumsum[c+1]-sumsum[b]-sum[a]%MOD*(c-b+1)%MOD+p[a].x%MOD*(ysum[c+1]-ysum[b])%MOD-p[a].y%MOD*(xsum[c+1]-xsum[b])%MOD; ret%=MOD; if(ret<0) ret+=MOD; /*printf("sumarea(%d,%d,%d)=%lld\n",a,b,c,ret);*/ return ret; }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	REPE(i,n) p[i+n]=p[i];
	REP(i,2*n) val[i]=p[i+1]^p[i];
	sum[0]=0; REP(i,n) sum[i+1]=sum[i]+val[i];
	sumsum[0]=0; REPE(i,2*n) if((sumsum[i+1]=sumsum[i]+sum[i>=n?i-n:i]%MOD+(i>=n?sum[n]%MOD:0))>=MOD) sumsum[i+1]-=MOD;
	xsum[0]=0; REP(i,2*n) if((xsum[i+1]=xsum[i]+(p[i].x%MOD+MOD)%MOD)>=MOD) xsum[i+1]-=MOD;
	ysum[0]=0; REP(i,2*n) if((ysum[i+1]=ysum[i]+(p[i].y%MOD+MOD)%MOD)>=MOD) ysum[i+1]-=MOD;
	//REP(i,n) FOR(j,i+1,i+n) printf("(%d,%d)-(%d,%d): %lld\n",p[i].x,p[i].y,p[j].x,p[j].y,area(i,j));
	//REPE(i,2*n) printf("%d: %lld %lld %lld %lld\n",i,i>n?sum[i-n]%MOD+sum[n]%MOD:sum[i]%MOD,sumsum[i]%MOD,xsum[i],ysum[i]);

	ll totarea=area(0,n-1);
	//printf("%lld\n",totarea/2);
	ll ret=0;
	for(int a=0,b=0;a<n;++a) {
		while(area(a,b)<(totarea+1)/2) ++b;
		//ret+=2*area(a,b)-totarea+2*area(a,b+1)-totarea+...+2*area(a,a+n-2)-totarea
		//ret+=totarea-2*area(a,a+2)+totarea-2*area(a,a+3)+...+totarea-2*area(a,b-1)
		//ll cur=(2*sumarea(a,b,a+n-2)-totarea%MOD*(a+n-2-b+1))%MOD;
		ll cur=(totarea%MOD*(b-1-a-2+1)%MOD-2*sumarea(a,a+2,b-1))%MOD;
		//while(cur<0) cur+=MOD; while(cur>=MOD) cur-=MOD;
		//printf("%d-%d %lld/%lld -> %lld %lld\n",a,b,area(a,b-1),area(a,b),cur,cur*((MOD+1)/2)%MOD);
		ret+=cur;
	}
	ret%=MOD; if(ret<0) ret+=MOD;
	//ret=ret*((MOD+1)/2)%MOD;
	printf("%d\n",(int)ret);
}


int main() {
	run();
	return 0;
}