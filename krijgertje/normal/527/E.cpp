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


const int MAXN=100000;
const int MAXM=200000;
const int MAXM2=MAXM+MAXN/2+1;

int n,m;
int fst[MAXN],deg[MAXN];
int nxt[2*MAXM2],to[2*MAXM2];

int cur[MAXN];
bool used[MAXM2];
int path[MAXM2],npath;
int stck[MAXM2],nstck;

int ret[MAXM2];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1,deg[i]=0;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b; ++deg[a];
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a; ++deg[b];
	}

	{
		int lst=-1;
		REP(i,n) if(deg[i]%2==1) {
			if(lst==-1) { lst=i; continue; }
			int a=lst,b=i;
			nxt[2*m+0]=fst[a]; fst[a]=2*m+0; to[2*m+0]=b; ++deg[a];
			nxt[2*m+1]=fst[b]; fst[b]=2*m+1; to[2*m+1]=a; ++deg[b];
			++m; lst=-1;
		}
		assert(lst==-1);
		if(m%2==1) {
			int a=0,b=0;
			nxt[2*m+0]=fst[a]; fst[a]=2*m+0; to[2*m+0]=b; ++deg[a];
			nxt[2*m+1]=fst[b]; fst[b]=2*m+1; to[2*m+1]=a; ++deg[b];
			++m;
		}
	}
	//REP(i,n) { printf("%d:",i); for(int x=fst[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }
	//REP(i,m) printf("%d: %d-%d\n",i,to[2*i+1],to[2*i+0]);

	REP(i,n) cur[i]=fst[i];
	REP(i,m) used[i]=false;
	npath=0;
	nstck=0; stck[nstck++]=fst[0]; used[fst[0]/2]=true;
	while(nstck>0) {
		int at=to[stck[nstck-1]];
		//printf("stck:"); REP(i,nstck) printf(" %d",stck[i]); puts("");
		while(cur[at]!=-1&&used[cur[at]/2]) cur[at]=nxt[cur[at]];
		if(cur[at]!=-1) {
			stck[nstck++]=cur[at];
			used[cur[at]/2]=true;
		} else {
			path[npath++]=stck[nstck-1];
			--nstck;
		}
	}
	assert(npath==m);
	//printf("path:"); REP(i,npath) printf(" %d",path[i]); puts("");
	REP(i,npath) ret[path[i]/2]=(path[i]%2)^(i%2);
	//REP(i,m) printf("%d: %d-%d (%d)\n",i,to[2*i+1],to[2*i+0],ret[i]);
	printf("%d\n",m);
	REP(i,m) printf("%d %d\n",to[2*i+ret[i]]+1,to[2*i+1-ret[i]]+1);
}

int main() {
	run();
	return 0;
}