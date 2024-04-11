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

const int MAXN=10000;
const int MAXM=MAXN-1+(MAXN-1)/2;

int gn,gm;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gc[MAXM];
int gcomp[MAXM]; bool gbeen[MAXM];

int cn;
int chead[MAXN],cnxt[MAXM];

int id[MAXN],minid[MAXN],nid;
int stck[MAXM],nstck;

int mark[MAXM],curmark;
int par[MAXM],rnk[MAXM],hascyc[MAXM];
int grp[MAXM],ngrp;

void dfs(int at) {
	id[at]=minid[at]=nid++;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		if(gbeen[x>>1]) continue; else gbeen[x>>1]=true;
		int to=gto[x];
		stck[nstck++]=x;
		if(id[to]==-1) {
			dfs(to);
			if(minid[to]<minid[at]) minid[at]=minid[to];
		} else {
			if(id[to]<minid[at]) minid[at]=id[to];
		}
		if(minid[to]>=id[at]) {
			while(gcomp[x>>1]==-1) gcomp[stck[--nstck]>>1]=cn;
			++cn;
		}
	}
}

int find(int a) { if(par[a]==a) return a; return par[a]=find(par[a]); }
void unite(int a,int b) {
	a=find(a),b=find(b); if(a==b) { printf("%d=%d\n",a,b); return; }
	if(rnk[b]>rnk[a]) swap(a,b);
	par[b]=a; if(hascyc[b]) hascyc[a]=true; if(rnk[a]==rnk[b]) ++rnk[a];
}


void run() {
	scanf("%d%d",&gn,&gm);
	REP(i,gn) ghead[i]=-1;
	REP(i,gm) {
		int a,b; scanf("%d%d%d",&a,&b,&gc[i]); --a,--b,--gc[i];
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}

	cn=nid=nstck=0; REP(i,gn) id[i]=-1; REP(i,gm) gcomp[i]=-1,gbeen[i]=false;
	dfs(0);
	//REP(i,gm) printf("%d-%d = %d [%d]\n",gto[2*i+1],gto[2*i+0],gcomp[i],gc[i]);

	REP(i,cn) chead[i]=-1; REP(i,gm) cnxt[i]=chead[gcomp[i]],chead[gcomp[i]]=i;
	//REP(i,cn) { printf("%d:",i); for(int x=chead[i];x!=-1;x=cnxt[x]) printf(" %d",gc[x]); puts(""); }

	curmark=0; REP(i,gm) mark[i]=-1,hascyc[i]=false,par[i]=i,rnk[i]=0;
	REP(i,cn) {
		if(chead[i]!=-1&&cnxt[chead[i]]==-1) { hascyc[find(gc[chead[i]])]=true; continue; }
		ngrp=0;
		//printf("%d:",i);
		for(int x=chead[i];x!=-1;x=cnxt[x]) {
			int cur=find(gc[x]);
			//printf(" %d",cur);
			if(mark[cur]!=curmark) grp[ngrp++]=cur,mark[cur]=curmark; else hascyc[cur]=true;
		}
		//puts("");
		FOR(j,1,ngrp) unite(grp[0],grp[j]);
		++curmark;
	}
	int ret=0;
	REP(i,gm) if(find(i)!=i||hascyc[i]) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}