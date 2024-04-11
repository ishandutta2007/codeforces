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
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],deg[MAXN];

double ret[MAXM];

void dfs(int at,int par,double t) {
	int step=1;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		double cur=t+2.0*step/deg[at]+1.0;
		while(cur>=2.0) cur-=2.0;
		ret[x>>1]=x%2==0?cur:cur<1?cur+1:cur-1;
		dfs(to,at,cur);
		++step;
	}
}

void run() {
	scanf("%d",&n); REP(i,n) ghead[i]=-1,deg[i]=0;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++deg[a];
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++deg[b];
	}

	dfs(0,-1,0.0);
	printf("%d\n",n-1);
	REP(i,n-1) {
		int a=gto[2*i+1],b=gto[2*i+0]; double res=ret[i]; if(res>=1.0) swap(a,b),res-=1.0;
		printf("1 %d %d %d %.18lf\n",i+1,a+1,b+1,res);
	}
}

int main() {
	run();
	return 0;
}