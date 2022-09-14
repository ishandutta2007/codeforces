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



int nskill,n,have;
int init[100000];

int fstassign[100000];
int nxtassign[100000];
int orgassign[100000];

int fstadd[100000];
int nxtadd[100000];
int orgadd[100000];

int fstmult[100000];
int nxtmult[100000];
ll orgmult[100000];
ll orgdiv[100000];

bool use[100000];
int nret;
int ret[100000];

int m;
typedef struct V { ll num,den; int idx; } V;
bool operator<(const V &x,const V &y) {
	ll a=x.num,b=y.den,c=y.num,d=x.den;
	ll ah=a>>30,al=a-(ah<<30),bh=b>>30,bl=b-(bh<<30);
	ll ch=c>>30,cl=c-(ch<<30),dh=d>>30,dl=d-(dh<<30);
	ll p=ah*bh-ch*dh;
	ll q=ah*bl+al*bh-ch*dl-cl*dh;
	ll r=al*bl-cl*dl;
	ll rh=r>>30,rl=r-(rh<<30); if(rl<0) --rh,rl+=1<<30; q+=rh;
	ll qh=q>>30,ql=q-(qh<<30); if(ql<0) --qh,ql+=1<<30; p+=qh;
	return p>0||p==0&&(ql>0||ql==0&&rl>0);
}
V v[100000];

void run() {
	scanf("%d%d%d",&nskill,&n,&have);
	REP(i,nskill) scanf("%d",&init[i]);
	REP(i,nskill) fstassign[i]=fstadd[i]=fstmult[i]=-1;
	REP(i,n) {
		int type,skill,val; scanf("%d%d%d",&type,&skill,&val); --skill;
		if(type==1) { nxtassign[i]=fstassign[skill]; fstassign[skill]=i; orgassign[i]=val; }
		if(type==2) { nxtadd[i]=fstadd[skill]; fstadd[skill]=i; orgadd[i]=val; }
		if(type==3) { nxtmult[i]=fstmult[skill]; fstmult[skill]=i; orgmult[i]=val; orgdiv[i]=1; }
	}
	//printf("processing assign\n");
	REP(skill,nskill) {
		int i=-1; for(int x=fstassign[skill];x!=-1;x=nxtassign[x]) if(orgassign[x]>init[skill]&&(i==-1||orgassign[x]>orgassign[i])) i=x;
		if(i!=-1) { nxtadd[i]=fstadd[skill]; fstadd[skill]=i; orgadd[i]=orgassign[i]-init[skill]; }
	}
	//printf("processing add\n");
	REP(skill,nskill) {
		m=0; for(int x=fstadd[skill];x!=-1;x=nxtadd[x]) v[m].num=orgadd[x],v[m].den=1,v[m].idx=x,++m;
		sort(v,v+m);
		ll cur=init[skill]; REP(x,m) { int i=v[x].idx; nxtmult[i]=fstmult[skill]; fstmult[skill]=i; orgmult[i]=cur+orgadd[i]; orgdiv[i]=cur; cur+=orgadd[i]; }
	}
	//printf("processing mult\n");
	//REP(skill,nskill) for(int x=fstmult[skill];x!=-1;x=nxtmult[x]) printf("%d: %lld/%lld (%d)\n",skill,orgmult[x],orgdiv[x],x);
	REP(i,n) use[i]=false;
	{
		m=0; REP(skill,nskill) for(int x=fstmult[skill];x!=-1;x=nxtmult[x]) v[m].num=orgmult[x],v[m].den=orgdiv[x],v[m].idx=x,++m;
		sort(v,v+m);
		int nuse=min(have,m);
		REP(i,nuse) use[v[i].idx]=true;
	}
	//printf("processing ret\n");
	nret=0;
	REP(skill,nskill) for(int x=fstassign[skill];x!=-1;x=nxtassign[x]) if(use[x]) ret[nret++]=x,use[x]=false;
	REP(skill,nskill) for(int x=fstadd[skill];x!=-1;x=nxtadd[x]) if(use[x]) ret[nret++]=x,use[x]=false;
	REP(skill,nskill) for(int x=fstmult[skill];x!=-1;x=nxtmult[x]) if(use[x]) ret[nret++]=x,use[x]=false;
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}