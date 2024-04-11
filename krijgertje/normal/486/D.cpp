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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MOD=1000000007;

int maxdist,n;
int val[2000];
int fst[2000];
int nxt[4000];
int to[4000];

int go(int root,int at,int par) {
	int ret=1;
	for(int x=fst[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		if(val[to[x]]>val[root]||val[to[x]]==val[root]&&to[x]<root) continue;
		if(val[to[x]]<val[root]-maxdist) continue;
		int cur=go(root,to[x],at)+1;
		ret=(ll)ret*cur%MOD;
	}
	//printf("going(%d,%d,%d) = %d\n",root,at,par,ret);
	return ret;
}

void run() {
	scanf("%d%d",&maxdist,&n);
	REP(i,n) scanf("%d",&val[i]);
	REP(i,n) fst[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b);  --a,--b;
		nxt[2*i+0]=fst[a]; to[2*i+0]=b; fst[a]=2*i+0;
		nxt[2*i+1]=fst[b]; to[2*i+1]=a; fst[b]=2*i+1;
	}
	int ret=0;
	REP(i,n) { ret+=go(i,i,-1); if(ret>=MOD) ret-=MOD; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}