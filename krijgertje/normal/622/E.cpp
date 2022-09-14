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
int head[MAXN],nxt[2*MAXM],to[2*MAXM];

int cur[MAXN],ncur;
void dfs(int at,int par,int d) {
	bool leaf=true;
	for(int x=head[at];x!=-1;x=nxt[x])  {
		if(to[x]==par) continue;
		leaf=false; dfs(to[x],at,d+1);
	}
	if(leaf) cur[ncur++]=d;
}

void run() {
	scanf("%d",&n);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	//REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }
	int ret=0;
	for(int x=head[0];x!=-1;x=nxt[x]) {
		ncur=0;
		dfs(to[x],0,1);
		sort(cur,cur+ncur);
		//printf("%d:",to[x]); REP(i,ncur) printf(" %d",cur[i]); puts("");
		FOR(i,1,ncur) if(cur[i]<=cur[i-1]) cur[i]=cur[i-1]+1;
		if(cur[ncur-1]>ret) ret=cur[ncur-1];
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}