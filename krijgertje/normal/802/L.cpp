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
const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,k;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM],gcost[MAXM],deg[MAXN];

int pup[MAXN];
double pupd[MAXN];

int Ex[MAXN];
double Exd[MAXN];

void dfs(int at,int par) {
	int sum=0; double sumd=0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs(to,at);
		sumd+=pupd[to];
		sum=(sum+pup[to])%MOD;
	}
	if(par!=-1) {
		if(deg[at]!=1) {
			int den=(deg[at]+MOD-sum)%MOD;
			pup[at]=pw(den,MOD-2);
			pupd[at]=1.0/(deg[at]-sumd);
			//printf("pup %d: %d (%.9lf) [deg=%d sum=%d den=%d sumd=%.9lf]\n",at,pup[at],pupd[at],deg[at],sum,den,sumd);
		} else {
			pup[at]=0;
			pupd[at]=0;
		}
	}
}

int ret;
double retd;

void dfs2(int at,int par) {
	int sum=0; double sumd=0;
	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		sum=(sum+pup[to])%MOD;
		sumd+=pupd[to];
	}
	Ex[at]=(ll)deg[at]*pw((deg[at]+MOD-sum)%MOD,MOD-2)%MOD;
	Exd[at]=deg[at]/(deg[at]-sumd);
	if(par!=-1) {
		Ex[at]=(ll)Ex[at]*Ex[par]%MOD*pw(deg[par],MOD-2)%MOD;
		Exd[at]*=Exd[par]/deg[par];
	}
	//printf("Ex %d: %d (%.9lf) [sum=%d]\n",at,Ex[at],Exd[at],sum);


	for(int x=ghead[at];x!=-1;x=gnxt[x]) {
		int to=gto[x]; if(to==par) continue;
		dfs2(to,at);
		int c=gcost[x>>1];
		ret=(ret+(ll)Ex[at]*pw(deg[at],MOD-2)%MOD*c)%MOD;
		if(deg[to]!=1) ret=(ret+(ll)Ex[to]*pw(deg[to],MOD-2)%MOD*c)%MOD;
		retd+=Exd[at]/deg[at]*c;
		if(deg[to]!=1) retd+=Exd[to]/deg[to]*c;
	}
}


void run() {
	scanf("%d",&n);
	REP(i,n) ghead[i]=-1,deg[i]=0;
	REP(i,n-1) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c); gcost[i]=c;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++deg[a];
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++deg[b];
	}
	dfs(0,-1);
	ret=0; retd=0;
	dfs2(0,-1);
	printf("%d\n",ret);
	//printf("%.9lf\n",retd);
}

int main() {
	run();
	return 0;
}