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
int head[MAXN],nxt[2*MAXM],to[2*MAXM];
bool done[MAXN];

bool dfs(int at,int par) {
	bool ret=false; done[at]=true;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		if(done[to[x]]) { ret=true; continue; }
		bool cur=dfs(to[x],at);
		if(cur) ret=true;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) head[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}

	int ret=0;
	REP(i,n) done[i]=false;
	REP(i,n) if(!done[i]&&!dfs(i,-1)) ++ret;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}