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

const int MAXN=3000;
const int MAXM=MAXN*(MAXN-1)/2;

int n,m;
int fst[MAXN],nxt[2*MAXM],to[2*MAXM];
int z[2][2],bound[2];

int d[MAXN][MAXN];
int q[MAXN],qhead,qtail;

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) fst[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=fst[a]; fst[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=fst[b]; fst[b]=2*i+1; to[2*i+1]=a;
	}
	REP(i,2) { scanf("%d%d%d",&z[i][0],&z[i][1],&bound[i]); --z[i][0],--z[i][1]; }

	REP(i,n) {
		REP(j,n) d[i][j]=INT_MAX;
		qhead=qtail=0; d[i][i]=0; q[qhead++]=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=fst[at];x!=-1;x=nxt[x]) if(d[i][to[x]]==INT_MAX) { d[i][to[x]]=d[i][at]+1; q[qhead++]=to[x]; }
		}
	}

	if(d[z[0][0]][z[0][1]]>bound[0]||d[z[1][0]][z[1][1]]>bound[1]) { printf("-1\n"); return; }
	int ret=m-d[z[0][0]][z[0][1]]-d[z[1][0]][z[1][1]];
	REP(i,n) FOR(j,i+1,n) REP(k0,2) REP(k1,2) {
		int p1=d[z[0][k0]][i],p2=d[j][z[0][1-k0]];
		int q1=d[z[1][k1]][i],q2=d[j][z[1][1-k1]];
		if(p1+d[i][j]+p2>bound[0]||q1+d[i][j]+q2>bound[1]) continue;
		int cur=m-p1-p2-q1-q2-d[i][j]; if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}