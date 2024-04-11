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

const int MAXN=100;
const int MAXM=MAXN-1;

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gcost[MAXM];

int dfs(int at,int par) {
	int ret=0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		ret=max(ret,dfs(to,at)+gcost[x>>1]);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); gcost[i]=c;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a;
	}
	int ret=dfs(0,-1); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}