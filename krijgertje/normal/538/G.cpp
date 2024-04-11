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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=2000000;
const int MAXPOS=200000;
const int MAXN=MAXPOS+2;

typedef struct P { ll x,y,p,q; } P;
bool operator<(const P &a,const P &b) { return a.q<b.q; }

int npos,len;
ll x[MAXPOS],y[MAXPOS],t[MAXPOS];

int n;
P p[MAXN];
void createp(ll ct,ll cx,ll cy) { ll cp=ct/len,cq=ct%len; p[n].x=cx,p[n].y=cy,p[n].p=cp,p[n].q=cq; ++n; }

ll bound[4];

ll divdown(ll a,ll b) {
	if(b<0) a=-a,b=-b;
	return a>=0?a/b:(a-b+1)/b;
}
void createcond(int type,ll mult,ll lim) {
	ll cbound=divdown(lim,mult);
	if(cbound<bound[type]) {
		bound[type]=cbound;
		//if(type==0) printf("(%cdx%cdy)%lld<=%lld\n",type/2==0?'+':'-',type%2==0?'+':'-',mult,lim);
	}
}


char ret[MAXLEN+1];

void run() {
	scanf("%d%d",&npos,&len); REP(i,npos) scanf("%I64d%I64d%I64d",&t[i],&x[i],&y[i]);// REP(i,npos) cin>>t[i]>>x[i]>>y[i];
	
	n=0; createp(0,0,0); createp(0,0,0); p[n-1].p=-1,p[n-1].q=len; REP(i,npos) createp(t[i],x[i],y[i]); sort(p,p+n);
	//printf("at %lld*len+%lld: (%lld,%lld)\n",p[0].p,p[0].q,p[0].x,p[0].y);

	REP(i,4) bound[i]=LLONG_MAX;
	REP(i,n-1) {
		ll dx=p[i+1].x-p[i].x,dy=p[i+1].y-p[i].y,dp=p[i+1].p-p[i].p,dq=p[i+1].q-p[i].q;
		// 0=dx+dy<=b/a, 1=dx-dy<=b/a, 2=-dx+dy<=b/a, 3=-dx-dy<=b/a
		//printf("at %lld*len+%lld: (%lld,%lld)\n",p[i+1].p,p[i+1].q,p[i+1].x,p[i+1].y);
		if(dp==0) continue;
		createcond(dp>0?3:0,abs(dp),dq-dx-dy);
		createcond(dp>0?1:2,abs(dp),dq+dx-dy);
		createcond(dp>0?2:1,abs(dp),dq-dx+dy);
		createcond(dp>0?0:3,abs(dp),dq+dx+dy);
	}
	//REP(type,4) printf("%cdx%cdy<=%lld\n",type/2==0?'+':'-',type%2==0?'+':'-',bound[type]);
	//printf("%lld<=dx+dy<=%lld\n%lld<=dx-dy<=%lld\n",-bound[3],bound[0],-bound[2],bound[1]);

	for(ll ds=-bound[3];ds<=bound[0]&&ds<=-bound[3]+3;++ds) for(ll dt=-bound[2];dt<=bound[1]&&dt<=-bound[2]+3;++dt) {
		if((ds+dt)%2!=0) continue;
		ll DX=(ds+dt)/2,DY=(ds-dt)/2; bool ok=true; int at=0;
		//printf("testing %lld,%lld\n",DX,DY);
		REP(i,n-1) {
			ll dx=p[i+1].x-p[i].x,dy=p[i+1].y-p[i].y,dp=p[i+1].p-p[i].p,dq=p[i+1].q-p[i].q;
			ll cx=dx-dp*DX,cy=dy-dp*DY;
			ll acx=abs(cx),acy=abs(cy);
			if(acx+acy>dq) { ok=false; break; }
			if((acx+acy)%2!=dq%2) { ok=false; break; }
			REP(j,acx) ret[at++]=cx<0?'L':'R';
			REP(j,acy) ret[at++]=cy<0?'D':'U';
			REP(j,dq-acx-acy) ret[at++]=j%2==0?'L':'R';
		}
		if(!ok) continue;
		ret[at++]='\0';
		//printf("ok %d\n",at);
		printf("%s\n",ret); return;
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}