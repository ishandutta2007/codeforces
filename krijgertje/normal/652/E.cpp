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

const int MAXN=300000;
const int MAXM=300000;

int n,m,s,t;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM]; bool gart[MAXM];
int id[MAXN],minid[MAXN],c[MAXN],nid,stck[MAXN],nstck;
int cn,cm;
int chead[MAXN],cnxt[2*MAXM],cto[2*MAXM]; bool cart[MAXM],ccart[MAXN];

void tarjan(int at,int par) {
	id[at]=minid[at]=nid++; stck[nstck++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		if(id[to]==-1) {
			tarjan(to,at);
			if(minid[to]<minid[at]) minid[at]=minid[to];

		} else {
			if(id[to]<minid[at]) minid[at]=id[to];
		}
	}
	if(minid[at]>=id[at]) { while(c[at]==-1) c[stck[--nstck]]=cn; cn++; }
}
bool ret;
bool dfs(int at,int par) {
	if(at==c[t]) { if(ccart[at]) ret=true; return true; }
	for(int x=chead[at];x!=-1;x=cnxt[x]) {
		int to=cto[x]; if(to==par) continue;
		bool cur=dfs(to,at);
		//printf("\t\t%d->%d: %c\n",at,to,cur?'V':'.');
		if(cur) { if(ccart[at]||cart[x>>1]) ret=true; return true; }
	}
	return false;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; gart[i]=c!=0;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	scanf("%d%d",&s,&t); --s,--t;
	nid=cn=cm=nstck=0; memset(id,-1,sizeof(id)); memset(c,-1,sizeof(c)); tarjan(0,-1);
	REP(i,cn) chead[i]=-1,ccart[i]=false;
	REP(i,m) {
		int a=c[gto[2*i+1]],b=c[gto[2*i+0]]; //printf("%d-%d [%c]\n",a,b,gart[i]?'V':'.');
		if(a==b) { ccart[a]|=gart[i]; continue; }
		cnxt[2*cm+0]=chead[a]; chead[a]=2*cm+0; cto[2*cm+0]=b;
		cnxt[2*cm+1]=chead[b]; chead[b]=2*cm+1; cto[2*cm+1]=a;
		cart[cm++]=gart[i];
	}
	//REP(i,n) printf("%d: %d [%c]\n",i,c[i],ccart[i]?'V':'.');
	ret=false; dfs(c[s],-1); printf("%s\n",ret?"YES":"NO");
}

int main() {
	run();
	return 0;
}