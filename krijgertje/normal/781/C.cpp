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

const int MAXN=200000;
const int MAXM=200000;

int n,m,nclone;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

int ret[2*MAXN],nret;
bool been[MAXN];
void dfs(int at) {
	//printf("dfs(%d)\n",at);
	assert(!been[at]); been[at]=true; ret[nret++]=at;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(been[to]) continue;
		dfs(to);
		ret[nret++]=at;
	}
}

void run() {
	scanf("%d%d%d",&n,&m,&nclone); REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	memset(been,false,sizeof(been)); nret=0; dfs(0);
	int each=(2*n+nclone-1)/nclone;
	REP(i,nclone) {
		int l=i*each,h=min(nret,(i+1)*each);
		if(l<h) { printf("%d",h-l); FOR(j,l,h) printf(" %d",ret[j]+1); puts(""); } else printf("%d %d\n",1,1);
	}
}

int main() {
	run();
	return 0;
}