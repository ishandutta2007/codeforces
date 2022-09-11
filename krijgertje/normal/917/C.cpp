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

const int MAXQ=25;
const int MAXSZ=8;
const int MAXID=70;
const int MAXLG=30;

int have,sz,n,nq;
pair<int,int> q[MAXQ];
int cost[MAXSZ+1];

int id[1<<MAXSZ],nid;
int idmask[MAXID];

ll zero[MAXID][MAXID];
ll one[MAXID][MAXID];
ll many[MAXLG+1][MAXID][MAXID];


ll cur[MAXID];
ll nxt[MAXID];

void advance(int steps) {
	//printf("advancing %d\n",steps);
	REPE(z,MAXLG) if(steps&(1<<z)) {
		//printf("\tz=%d:",z); REP(i,nid) printf(" %lld",cur[i]==LONG_MAX?-1:cur[i]); puts("");
		REP(j,nid) nxt[j]=LLONG_MAX;
		REP(i,nid) REP(j,nid) if(cur[i]!=LLONG_MAX&&many[z][i][j]!=LLONG_MAX) nxt[j]=min(nxt[j],cur[i]+many[z][i][j]);
		REP(j,nid) cur[j]=nxt[j];
	}
	//REP(i,nid) printf(" %lld",cur[i]==LONG_MAX?-1:cur[i]); puts("");
}

ll czero[MAXID][MAXID];
ll cone[MAXID][MAXID];
ll specialcost[MAXSZ+1];

void advancespecial() {
	//printf("advancespecial:"); REPE(k,sz) printf(" %lld",specialcost[k]); puts("");
	REP(i,nid) REP(j,nid) czero[i][j]=i==j?0:LLONG_MAX;
	for(int i=nid-1;i>=0;--i) {
		int mask=idmask[i];
		int a=0; while((mask&(1<<a))==0) ++a;
		FOR(b,a+1,sz) if((mask&(1<<b))==0) {
			int j=id[mask^(1<<a)^(1<<b)]; assert(j!=-1);
			REP(k,nid) if(czero[j][k]!=LLONG_MAX) czero[i][k]=min(czero[i][k],cost[b-a]+czero[j][k]+specialcost[b+1]);
		}
	}
	REP(i,nid) REP(j,nid) cone[i][j]=LLONG_MAX;
	REP(i,nid) {
		int mask=idmask[i];
		int a=0; while((mask&(1<<a))==0) ++a;
		//use
		{
			int b=sz;
			int j=id[(mask^(1<<a)^(1<<b))>>1]; assert(j!=-1);
			REP(k,nid) if(czero[j][k]!=LLONG_MAX) cone[i][k]=min(cone[i][k],cost[b-a]+czero[j][k]+specialcost[sz]);
		}
		//skip
		if(a!=0) {
			int j=id[mask>>1]; assert(j!=-1);
			cone[i][j]=0;
		}
	}
	REP(j,nid) nxt[j]=LLONG_MAX;
	REP(i,nid) REP(j,nid) if(cur[i]!=LLONG_MAX&&cone[i][j]!=LLONG_MAX) nxt[j]=min(nxt[j],cur[i]+cone[i][j]);
	REP(j,nid) cur[j]=nxt[j];
}

void run() {
	scanf("%d%d%d%d",&have,&sz,&n,&nq); FORE(i,1,sz) scanf("%d",&cost[i]); REP(i,nq) scanf("%d%d",&q[i].first,&q[i].second);

	memset(id,-1,sizeof(id)); nid=0;
	REP(i,1<<sz) {
		int cnt=0; REP(j,sz) if(i&(1<<j)) ++cnt; if(cnt==have) idmask[nid]=i,id[i]=nid,++nid;
	}
	//printf("nid=%d\n",nid);

	REP(i,nid) REP(j,nid) zero[i][j]=i==j?0:LLONG_MAX;
	for(int i=nid-1;i>=0;--i) {
		int mask=idmask[i];
		int a=0; while((mask&(1<<a))==0) ++a;
		FOR(b,a+1,sz) if((mask&(1<<b))==0) {
			int j=id[mask^(1<<a)^(1<<b)]; assert(j!=-1);
			REP(k,nid) if(zero[j][k]!=LLONG_MAX) zero[i][k]=min(zero[i][k],cost[b-a]+zero[j][k]);
		}
	}
	//printf("zero:\n"); REP(i,nid) { REP(j,sz) printf("%d",(idmask[i]>>j)&1); printf(":"); REP(j,nid) printf(" %lld",zero[i][j]==LLONG_MAX?-1:zero[i][j]); puts(""); }

	REP(i,nid) REP(j,nid) one[i][j]=LLONG_MAX;
	REP(i,nid) {
		int mask=idmask[i];
		int a=0; while((mask&(1<<a))==0) ++a;
		//use
		{
			int b=sz;
			int j=id[(mask^(1<<a)^(1<<b))>>1]; assert(j!=-1);
			REP(k,nid) if(zero[j][k]!=LLONG_MAX) one[i][k]=min(one[i][k],cost[b-a]+zero[j][k]);
		}
		//skip
		if(a!=0) {
			int j=id[mask>>1]; assert(j!=-1);
			one[i][j]=0;
		}
	}
	//printf("one:\n"); REP(i,nid) { REP(j,sz) printf("%d",(idmask[i]>>j)&1); printf(":"); REP(j,nid) printf(" %lld",one[i][j]==LLONG_MAX?-1:one[i][j]); puts(""); }

	REP(i,nid) REP(j,nid) many[0][i][j]=one[i][j];
	FORE(z,1,MAXLG) {
		REP(i,nid) REP(j,nid) many[z][i][j]=LLONG_MAX;
		REP(i,nid) REP(j,nid) REP(k,nid) if(many[z-1][i][k]!=LLONG_MAX&&many[z-1][k][j]!=LLONG_MAX) many[z][i][j]=min(many[z][i][j],many[z-1][i][k]+many[z-1][k][j]);
		//if(z<=4) { printf("many%d:\n",z); REP(i,nid) { REP(j,sz) printf("%d",(idmask[i]>>j)&1); printf(":"); REP(j,nid) printf(" %lld",many[z][i][j]==LLONG_MAX?-1:many[z][i][j]); puts(""); } }
	}

	int sid=id[((1<<have)-1)<<(sz-have)]; assert(sid!=-1);
	//printf("sid: "); REP(j,sz) printf("%d",(idmask[sid]>>j)&1); puts("");
	int cx=have;
	REP(i,nid) cur[i]=LLONG_MAX; cur[sid]=0;

	sort(q,q+nq);

	REP(i,nq) {
		int nx=q[i].first,dx=nx-cx; assert(dx>=1);
		advance(dx-1); cx=nx-1;
		REP(j,sz) {
			if(nx+j>n||i+1<nq&&q[i+1].first==nx+j) break;
			REPE(k,sz) specialcost[k]=0;
			REPE(k,i) if(q[k].first>=nx+j-sz) specialcost[q[k].first-(nx+j-sz)]=q[k].second;
			advancespecial(); cx=nx+j;
		}
	}
	{
		int nx=n,dx=nx-cx;
		advance(dx); cx=nx;
	}
	printf("%lld\n",cur[sid]);
}

int main() {
	run();
	return 0;
}