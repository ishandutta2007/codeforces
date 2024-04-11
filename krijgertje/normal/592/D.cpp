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

const int MAXN=123456;
const int MAXM=MAXN-1;

int n,nspec;
int head[MAXN],nxt[2*MAXM],to[2*MAXM]; bool isspec[MAXN];

bool better(pair<int,int> a,pair<int,int> b) { return a.first>b.first||a.first==b.first&&a.second!=-1&&a.second<b.second; }

int maxdlen,mindhead,tsum;
pair<int,int> dfs(int at,int par) {
	pair<int,int> mx=MP(0,-1),mx2=MP(0,-1);
	if(isspec[at]) mx=MP(0,at);
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		pair<int,int> cur=dfs(to[x],at);
		if(better(cur,mx)) mx2=mx,mx=cur; else if(better(cur,mx2)) mx2=cur;
	}
	if(mx.second!=-1&&mx2.second!=-1) {
		pair<int,int> cur=MP(mx.first+mx2.first,min(mx.second,mx2.second));
		if(better(cur,MP(maxdlen,mindhead))) maxdlen=cur.first,mindhead=cur.second;
	}
	if(mx.second!=-1&&par!=-1) ++tsum,++mx.first;
	//printf("\t%d -> (%d,%d) (%d,%d)\n",at,mx.first,mx.second,mx2.first,mx2.second);
	return mx;
}


void run() {
	scanf("%d%d",&n,&nspec);
	REP(i,n) head[i]=-1,isspec[i]=false;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	//REP(i,n) { printf("%d:",i); for(int x=head[i];x!=-1;x=nxt[x]) printf(" %d",to[x]); puts(""); }
	REP(i,nspec) { int a; scanf("%d",&a); --a; isspec[a]=true; }
	int root=0; while(!isspec[root]) ++root;
	maxdlen=0,mindhead=root,tsum=0;
	dfs(root,-1);	
	//printf("res: maxdlen=%d, mindhead=%d, tsum=%d\n",maxdlen,mindhead,tsum);
	printf("%d\n%d\n",mindhead+1,2*tsum-maxdlen);
}

int main() {
	run();
	return 0;
}