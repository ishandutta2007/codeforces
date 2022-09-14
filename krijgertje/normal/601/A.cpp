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

const int MAXN=400;

int n,m;
int type[MAXN][MAXN];

int d[MAXN];
int q[MAXN],qhead,qtail;


void run() {
	scanf("%d%d",&n,&m);
	memset(type,0,sizeof(type)); REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; type[a][b]=type[b][a]=1; }
	//REP(i,n) { REP(j,n) printf("%d",type[i][j]); puts(""); }

	int use=1-type[0][n-1];
	memset(d,-1,sizeof(d)); qhead=qtail=0;
	q[qhead++]=0; d[0]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		//printf("%d = %d [%d]\n",at,d[at],use);
		REP(to,n) if(type[at][to]==use&&d[to]==-1) { q[qhead++]=to; d[to]=d[at]+1; }
	}
	printf("%d\n",d[n-1]);
}


int main() {
	run();
	return 0;
}