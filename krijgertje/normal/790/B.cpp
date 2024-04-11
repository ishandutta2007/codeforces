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
const int MAXM=MAXN-1;
const int MAXK=5;

int n,k;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];

typedef struct R { ll sumroot,sumpair; int cnt; int remroot[MAXK]; } R;

R dfs(int at,int par) {
	R ret; ret.sumroot=0; ret.sumpair=0; ret.cnt=1; REP(i,k) ret.remroot[i]=0; ret.remroot[0]=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		R cur=dfs(to,at);
		REP(i,k) REP(j,k) ret.sumpair+=(ll)ret.remroot[i]*cur.remroot[j]*((i+j+1+k-1)/k);
		ret.sumpair+=cur.sumpair+cur.cnt*ret.sumroot+ret.cnt*cur.sumroot;
		ret.sumroot+=cur.sumroot+cur.remroot[k-1];
		ret.cnt+=cur.cnt;
		REP(i,k) ret.remroot[(i+1)%k]+=cur.remroot[i];
		//printf("\t%d after %d: sumroot=%lld sumpair=%lld cnt=%d",at+1,to+1,ret.sumroot,ret.sumpair,ret.cnt); REP(i,k) printf(" rem%d=%d",i,ret.remroot[i]); puts("");
	}
	//printf("%d: sumroot=%lld sumpair=%lld cnt=%d",at+1,ret.sumroot,ret.sumpair,ret.cnt); REP(i,k) printf(" rem%d=%d",i,ret.remroot[i]); puts("");
	return ret;
}

void run() {
	scanf("%d%d",&n,&k); REP(i,n) ghead[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	//n=MAXN,k=MAXK; REP(i,n) ghead[i]=-1; REP(i,n-1) { int a=0,b=i+1; gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b; gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a; }

	R ret=dfs(0,-1);
	printf("%lld\n",ret.sumpair);
}

int main() {
	run();
	return 0;
}