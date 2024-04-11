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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }


int h,w,l,r,MOD;

int n,p[100];
int d[100001];

int ly,hy;
ll cnt,sum;

void go(int at,int step,int by) {
	if(at<n) {
		go(at+1,step,+by);
		go(at+1,step*p[at],-by);
	} else {
		int a=(ly+step-1)/step;
		int b=hy/step;
		if(a>b) return;

//		ll ocnt=cnt,osum=sum;
//		FORE(y,a,b) { cnt+=by; sum+=y*step*by; }
//		swap(cnt,ocnt); swap(sum,osum);
		cnt+=(b-a+1)*by;
		sum+=(ll)(a+b)*step*(b-a+1)/2*by;
//		if(cnt!=ocnt||sum!=osum) { printf("%d (%d): %lld vs %lld en %lld vs %lld [%d,%d]\n",step,by,cnt,ocnt,sum,osum,a,b); exit(0); }
	}
}

void run() {
	memset(d,-1,sizeof(d));
	FORE(i,2,100000) if(d[i]==-1) {
		d[i]=i;
		if((ll)i*i<=100000) for(int j=i*i;j<=100000;j+=i) if(d[j]==-1) d[j]=i;
	}

	scanf("%d%d%d%d%d",&h,&w,&l,&r,&MOD);
	ll ret=0;
	if(l<=1&&1<=r) ret+=(ll)(h+1)*w; // (0,1)
	if(l<=1&&1<=r) ret+=(ll)h*(w+1); // (1,0)
//	printf("base=%lld\n",ret);
	FORE(dx,1,h) {
		ll ly2=(ll)l*l-(ll)dx*dx;
		if(ly2<=0) ly=1; else { ly=(int)sqrt(ly2); if((ll)ly*ly<ly2) ++ly; }
		ll hy2=(ll)r*r-(ll)dx*dx;
		if(hy2<0) hy=0; else hy=(int)sqrt(hy2);
		hy=min(hy,w);

		cnt=0,sum=0;
//		FORE(dy,ly,hy) if(gcd(dx,dy)==1) { ++cnt; sum+=dy; }
		n=0; for(int z=dx;z!=1;) { p[n]=d[z]; while(z%p[n]==0) z/=p[n]; ++n; }
		go(0,1,+1);

		
		ret+=2LL*(h-dx+1)*cnt*(w+1)%MOD;
		ret-=2LL*(h-dx+1)*sum%MOD;
		ret%=MOD; if(ret<0) ret+=MOD;

//		printf("%d: 2*%d*(%lld*%d-%lld) [%d..%d]\n",dx,h-dx+1,cnt,w+1,sum,ly,hy);
//		printf("\t"); REP(i,n) printf("%d ",p[i]); puts("");
	}
	ret%=MOD; if(ret<0) ret+=MOD;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}