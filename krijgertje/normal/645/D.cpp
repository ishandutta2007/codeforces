

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
const int MAXM=100000;

int n,m;
int deg[MAXN];
int head[MAXN],nxt[MAXM],to[MAXM];
int q[MAXN],qhead,qtail;

int pos[MAXN],npos;


void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) head[i]=-1,deg[i]=0;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; nxt[i]=head[a]; head[a]=i; to[i]=b; ++deg[b]; }

	npos=0; qhead=qtail=0; REP(i,n) if(deg[i]==0) q[qhead++]=i;
	while(qtail<qhead) {
		if(qtail+1!=qhead) { printf("-1\n"); return; }
		int at=q[qtail++]; pos[at]=npos++;
		for(int x=head[at];x!=-1;x=nxt[x]) if(--deg[to[x]]==0) q[qhead++]=to[x];
	}
	if(npos!=n) { printf("-1\n"); return; }
	//REP(i,n) printf("%d: %d\n",i,pos[i]);
	int ret=0; 
	REP(at,n) for(int x=head[at];x!=-1;x=nxt[x]) if(pos[to[x]]==pos[at]+1&&x+1>ret) ret=x+1;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}