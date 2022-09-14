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
const int MAXM=MAXN-1;

int n,m;
int head[MAXN],deg[MAXN],nxt[2*MAXM],to[2*MAXM];

bool I[2*MAXM],T[2*MAXM];
int q[MAXM],qhead,qtail;


void run() {
	scanf("%d",&n); m=n-1;
	REP(i,n) head[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b; ++deg[a];
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a; ++deg[b];
	}
	//REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }

	REP(i,2*m) I[i]=T[i]=false;
	qhead=qtail=0;
	REP(i,n) if(deg[i]==1) { int x=head[i]; I[x^1]=true; q[qhead++]=x; }
	while(qtail<qhead) {
		int x=q[qtail++];
		if(deg[to[x]]!=2) continue;
		for(int y=head[to[x]];y!=-1;y=nxt[y]) if(y!=(x^1)) { I[y^1]=true; q[qhead++]=y; }
	}
	REP(i,n) if(deg[i]==3) {
		int cnt=0; for(int x=head[i];x!=-1;x=nxt[x]) if(I[x]) ++cnt;
		for(int x=head[i];x!=-1;x=nxt[x]) if(cnt-(I[x]?1:0)==2) T[x^1]=true;
	}
	//REP(x,2*m) if(I[x]) printf("I%d->%d\n",to[x^1],to[x]);
	//REP(x,2*m) if(T[x]) printf("T%d->%d\n",to[x^1],to[x]);
	bool ok=true; REP(i,n) { int cnt=0; for(int x=head[i];x!=-1;x=nxt[x]) if(!I[x]&&!T[x]) ++cnt; if(cnt>=3) ok=false; }
	printf("%s\n",ok?"Yes":"No");
}


int main() {
	run();
	return 0;
}