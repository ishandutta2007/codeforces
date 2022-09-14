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

const int MAXN=5000;
const int MAXM=5000;

int ng,mg;
int ghead[MAXN],gnxt[MAXM],gto[MAXM];

int nc,nt;
int c[MAXN],t[MAXN],tmn[MAXN];
int stck[MAXN],nstck;
bool cleaf[MAXN];
int chead[MAXN],cnxt[MAXN];

int d[MAXN];
int q[MAXN],qhead,qtail;

void tarjan(int at,int par) {
	//printf("tarjan(%d,%d)\n",at,par);
	t[at]=tmn[at]=nt++,stck[nstck++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		if(t[to]==-1) {
			tarjan(to,at);
			if(tmn[to]<tmn[at]) tmn[at]=tmn[to];
		} else if(c[to]==-1) {
			if(t[to]<tmn[at]) tmn[at]=t[to];
		}
	}
	if(tmn[at]>=t[at]) {
		while(c[at]==-1) c[stck[--nstck]]=nc; ++nc;
	}
	//printf("end tarjan(%d,%d) [%d,%d]\n",at,par,t[at],tmn[at]);
}


int mincyc(int s) {
	for(int x=chead[c[s]];x!=-1;x=cnxt[x]) d[x]=INT_MAX;
	qhead=qtail=0; q[qhead++]=s; d[s]=0;
	//printf("mincyc(%d)\n",s);
	while(qtail<qhead) {
		int at=q[qtail++]; assert(c[at]==c[s]);
		//printf("\tat=%d, d=%d\n",at,d[at]);
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x];
			//printf("\t\tto=%d, d=%d\n",to,d[to]);
			if(to==s) return d[at]+1;
			if(d[at]+1<d[to]) d[to]=d[at]+1,q[qhead++]=to;
		}
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d",&ng,&mg);
	REP(i,ng) ghead[i]=-1;
	REP(i,mg) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[i]=ghead[a]; ghead[a]=i; gto[i]=b;
	}
	REP(i,ng) t[i]=c[i]=-1; nc=0,nt=0,nstck=0;
	REP(i,ng) if(t[i]==-1) tarjan(i,-1);
	//printf("nc=%d\n",nc); REP(i,ng) printf(" %d=%d",i,c[i]); puts("");
	REP(i,nc) cleaf[i]=true;
	REP(i,ng) for(int x=ghead[i];x!=-1;x=gnxt[x]) if(c[i]!=c[gto[x]]) cleaf[c[i]]=false;
	REP(i,nc) chead[i]=-1;
	REP(i,ng) cnxt[i]=chead[c[i]],chead[c[i]]=i;
	int ret=ng;
	REP(i,nc) if(cleaf[i]) {
		if(cnxt[chead[i]]==-1) continue;
		int cur=INT_MAX;
		for(int x=chead[i];x!=-1;x=cnxt[x]) { int now=mincyc(x); if(now<cur) cur=now; }
		ret+=998*cur+1; //printf("cur=%d\n",cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}