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

const int MOD=1000000007;

int n,m;
int cost[100000];
int fst[100000];
int nxt[300000];
int to[300000];

int comp[100000],ncomp;

int id[100000],minid[100000],nid;
int stck[100000],stcki[100000],nstck;
int visit[100000],nvisit; bool visiting[100000];

int compcost[100000],compways[100000];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&cost[i]);
	scanf("%d",&m); memset(fst,-1,sizeof(fst));
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		to[i]=b; nxt[i]=fst[a]; fst[a]=i;
	}

	memset(comp,-1,sizeof(comp)); ncomp=0;
	memset(id,-1,sizeof(id));
	memset(visiting,false,sizeof(visiting));
	REP(i,n) if(comp[i]==-1) {
		nid=0; nstck=0; nvisit=0;
		id[i]=minid[i]=nid++;
		visit[nvisit++]=i; visiting[i]=true;
		stck[nstck]=i; stcki[nstck]=fst[i]; ++nstck;
		while(nstck>0) {
//			REP(j,nstck) printf("[%d->%d]",stck[j],stcki[j]==-1?-1:to[stcki[j]]); puts("");
			int at=stck[nstck-1],x=stcki[nstck-1];
			if(x!=-1) {
				if(id[to[x]]==-1) {
					id[to[x]]=minid[to[x]]=nid++;
					visit[nvisit++]=to[x]; visiting[to[x]]=true;
					stck[nstck]=to[x]; stcki[nstck]=fst[to[x]]; ++nstck;
				} else if(visiting[to[x]]) {
					if(minid[to[x]]<minid[at]) minid[at]=minid[to[x]];
					stcki[nstck-1]=nxt[x];
				} else {
					stcki[nstck-1]=nxt[x];
				}
			} else {
				if(id[at]==minid[at]) {
					while(true) {
						int j=visit[--nvisit];
						visiting[j]=false;
						comp[j]=ncomp;
						if(j==at) break;
					}
					++ncomp;
				}
				--nstck;
			}
		}
	}
//	REP(i,n) printf("%d: %d\n",i,comp[i]);
	
	memset(compways,0,sizeof(compways));
	REP(i,n) {
		if(compways[comp[i]]==0||cost[i]<compcost[comp[i]]) { compcost[comp[i]]=cost[i]; compways[comp[i]]=0; }
		if(cost[i]==compcost[comp[i]]) ++compways[comp[i]];
	}
	ll totcost=0,totways=1;
	REP(i,ncomp) { totcost+=compcost[i]; totways=totways*compways[i]%MOD; }
	cout<<totcost<<" "<<totways<<endl;
}

int main() {
	run();
	return 0;
}