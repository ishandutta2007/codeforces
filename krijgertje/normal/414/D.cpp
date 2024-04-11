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

int nnode,nwater,ncoin;

int fst[100000];
int nxt[200000];
int to[200000];

int q[100000],qh,qt;
int d[100000];

int exist[100000];
int have[100000];

void run() {
	scanf("%d%d%d",&nnode,&nwater,&ncoin);
	memset(fst,-1,sizeof(fst));
	REP(i,nnode-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		to[2*i+0]=b; nxt[2*i+0]=fst[a]; fst[a]=2*i+0;
		to[2*i+1]=a; nxt[2*i+1]=fst[b]; fst[b]=2*i+1;
	}

	memset(d,-1,sizeof(d));
	memset(exist,0,sizeof(exist));
	qh=qt=0; q[qh++]=0; d[0]=0; exist[0]++;
	while(qt<qh) {
		int at=q[qt++];
		for(int x=fst[at];x!=-1;x=nxt[x]) {
			if(d[to[x]]!=-1) continue;
			d[to[x]]=d[at]+1; exist[d[to[x]]]++; q[qh++]=to[x];
		}
	}

	ll cost=0; have[0]=0; int used=0; int at=1; int ret=0;
	for(int i=1;exist[i]>0;++i) {
		cost+=used;
		have[i]=exist[i];
		used+=have[i];
		while(used>nwater) {
			int cur=min(used-nwater,have[at]);
			have[at]-=cur;
			used-=cur;
			cost-=(ll)cur*(i-at);
			while(have[at]==0) ++at;
		}
		while(cost>ncoin) {
			ll cur=min((cost-ncoin+i-at-1)/(i-at),(ll)have[at]);
			have[at]-=cur;
			used-=cur;
			cost-=(ll)cur*(i-at);
			while(have[at]==0) ++at;
		}
		if(used>ret) ret=used;
	}
	printf("%d\n",ret);
	
}

int main() {
	run();
	return 0;
}