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
const int MAXM=MAXN-1;

int n;
int ahead[MAXN],anxt[2*MAXM],ato[2*MAXM],adeg[MAXN]; bool arem[MAXM];
int bhead[MAXN],btail[MAXN],bnxt[2*MAXM],bto[2*MAXM];
pair<int,int> blst[MAXM];

int ret[MAXM][4],nret;
int q[MAXN],qhead,qtail;
int par[MAXN];

int find(int x) { if(par[x]==x) return x; return par[x]=find(par[x]); }
bool bhave(int u,int v) {
	if(u>v) swap(u,v);
	return binary_search(blst,blst+n-1,MP(u,v));
}
int afirst(int u) {
	u=find(u);
	for(int x=ahead[u];x!=-1;ahead[u]=x=anxt[x]) {
		if(arem[x>>1]) continue;
		if(find(ato[x])==u) continue;
		return x;
	}
	return -1;
}
int bfirst(int u) {
	u=find(u);
	for(int x=bhead[u];x!=-1;bhead[u]=x=bnxt[x]) {
		if(find(bto[x])==u) continue;
		return x;
	}
	return btail[u]=-1;
}
void merge(int u,int v) {
	assert(adeg[u]==0&&afirst(u)==-1); assert(par[u]==u); assert(par[v]==v);
	par[u]=v;
	if(btail[v]==-1) bhead[v]=bhead[u]; else bnxt[btail[v]]=bhead[u]; if(btail[u]!=-1) btail[v]=btail[u];
}


void run() {
	scanf("%d",&n);
	REP(i,n) ahead[i]=bhead[i]=btail[i]=-1,adeg[i]=0,par[i]=i;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b; arem[i]=false;
		anxt[2*i+0]=ahead[a]; ahead[a]=2*i+0; ato[2*i+0]=b; ++adeg[a];
		anxt[2*i+1]=ahead[b]; ahead[b]=2*i+1; ato[2*i+1]=a; ++adeg[b];
	}
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b; if(a>b) swap(a,b); blst[i]=MP(a,b);
		bnxt[2*i+0]=bhead[a]; bhead[a]=2*i+0; bto[2*i+0]=b; if(bnxt[2*i+0]==-1) btail[a]=2*i+0;
		bnxt[2*i+1]=bhead[b]; bhead[b]=2*i+1; bto[2*i+1]=a; if(bnxt[2*i+1]==-1) btail[b]=2*i+1;
	}
	sort(blst,blst+n-1);

	nret=0;
	qhead=qtail=0; REP(i,n) if(adeg[i]==1) q[qhead++]=i;
	while(qtail<qhead) {
		int a=q[qtail++]; if(adeg[a]!=1) continue; int x=afirst(a); assert(x!=-1); int b=ato[x];
		arem[x>>1]=true; if(--adeg[a]==1) q[qhead++]=a; if(--adeg[b]==1) q[qhead++]=b;
		if(bhave(ato[x^1],ato[x])) {
			merge(a,b);
		} else {
			int c=a,y=bfirst(c); assert(y!=-1); int d=find(bto[y]);
			merge(c,d);
			ret[nret][0]=ato[x^1],ret[nret][1]=ato[x],ret[nret][2]=bto[y^1],ret[nret][3]=bto[y],++nret;
		}
	}

	printf("%d\n",nret); REP(i,nret) printf("%d %d %d %d\n",ret[i][0]+1,ret[i][1]+1,ret[i][2]+1,ret[i][3]+1);
}

int main() {
	run();
	return 0;
}