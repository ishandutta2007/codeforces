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

const int MAXN=1000;
const int MAXM=100000;

int n,m;
int fst[MAXN],nxt[2*MAXM],to[2*MAXM];

int col[MAXN],id[MAXN];
int q[MAXN],qhead,qtail;
int d[MAXN][MAXN];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}

	int ret=0;
	REP(i,n) col[i]=id[i]=-1;
	REP(s,n) if(id[s]==-1) {
		qhead=qtail=0; col[s]=0; id[s]=qhead; q[qhead++]=s;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=fst[at];x!=-1;x=nxt[x]) {
				if(id[to[x]]==-1) {
					col[to[x]]=1-col[at]; id[to[x]]=qhead; q[qhead++]=to[x];
				} else {
					if(col[to[x]]!=1-col[at]) { printf("-1\n"); return; }
				}
			}
		}
		int ncur=qhead;
		REP(i,ncur) REP(j,ncur) d[i][j]=i==j?0:INT_MAX;
		REP(i,ncur) for(int x=fst[q[i]];x!=-1;x=nxt[x]) { int j=id[to[x]]; if(d[i][j]>1) d[i][j]=1; }
		REP(k,ncur) REP(i,ncur) REP(j,ncur) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX&&d[i][k]+d[k][j]<d[i][j]) d[i][j]=d[i][k]+d[k][j];
		//printf("%d\n",ncur); REP(i,ncur) { REP(j,ncur) printf("%3d",d[i][j]); puts(""); }
		int now=0; REP(i,ncur) REP(j,ncur) if(d[i][j]>now) now=d[i][j]; ret+=now;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}