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

const int MAXN=500;
const int MAXM=2*MAXN*MAXN;
const int MAXLG=60;

int n,m;
int ghead[MAXN],gnxt[MAXM],gto[MAXM],gtype[MAXM];

ull can[MAXLG+1][2][MAXN][(MAXN+63)/64];

bool now[MAXN];
bool tmp[MAXN];

inline bool test(int z,int t,int i,int j) { return ((can[z][t][i][j/64]>>(j%64))&1)!=0; }

void run() {
	scanf("%d%d",&n,&m); REP(i,n) ghead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d%d",&a,&b,&gtype[i]); --a,--b;
		gnxt[i]=ghead[a]; ghead[a]=i; gto[i]=b;
	}
	//n=MAXN; m=2*MAXN; REP(i,n) ghead[i]=-1; REP(i,m) { int a=rand()%n,b=rand()%n,t=rand()%2; gnxt[i]=ghead[a]; ghead[a]=i; gto[i]=b; gtype[i]=t; }
	memset(can,false,sizeof(can));
	REP(at,n) for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x],t=gtype[x]; can[0][t][at][to/64]|=1ULL<<(to%64); }
	REP(z,MAXLG) {
		REP(t,2) REP(i,n) REP(k,n) if(test(z,t,i,k)) REP(jj,(n+63)/64) can[z+1][t][i][jj]|=can[z][1-t][k][jj];
	}

	REP(to,n) if(test(MAXLG,0,0,to)) { printf("-1\n"); return; }
	memset(now,false,sizeof(now)); now[0]=true;
	ll ret=0;
	for(int k=MAXLG,t=0;k>=0;--k) {
		memset(tmp,false,sizeof(tmp));
		bool any=false; REP(at,n) REP(to,n) if(now[at]&&test(k,t,at,to)) { any=true; tmp[to]=true; }
		if(!any) continue;
		ret+=1LL<<k; t=1-t; REP(i,n) now[i]=tmp[i];
	}
	printf("%lld\n",ret>1000000000000000000LL?-1:ret);
}

int main() {
	run();
	return 0;
}