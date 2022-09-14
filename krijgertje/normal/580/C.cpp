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

int n,maxcat;

int cat[MAXN];

int head[MAXN];
int nxt[2*MAXM];
int to[2*MAXM];

int go(int at,int par,int cur) {
	if(cat[at]) ++cur; else cur=0;
	if(cur>maxcat) return 0;
	int ret=0; bool leaf=true;
	for(int x=head[at];x!=-1;x=nxt[x]) if(to[x]!=par) leaf=false,ret+=go(to[x],at,cur);
	if(leaf) ++ret;
	return ret;
}

void run() {
	scanf("%d%d",&n,&maxcat);
	REP(i,n) scanf("%d",&cat[i]);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}

	printf("%d\n",go(0,-1,0));
}

int main() {
	run();
	return 0;
}