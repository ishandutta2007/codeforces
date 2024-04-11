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
const int MAXM=100000;

int n,m;
int head[MAXN][10],nxt[2*MAXM],to[2*MAXM];

int q[MAXN],qhead,qtail; bool qsame[MAXN];

int prv[MAXN],pcst[MAXN];

int nret,ret[MAXN]; char retcst[MAXN+1];

int dfree[MAXN],nxtfree[MAXN];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,10) head[i][j]=-1;
	REP(i,m) {
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		nxt[2*i+0]=head[a][c]; head[a][c]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b][c]; head[b][c]=2*i+1; to[2*i+1]=a;
	}

	REP(i,n) nxtfree[i]=-1;
	qhead=qtail=0; q[qhead++]=n-1; dfree[n-1]=0; nxtfree[n-1]=-2;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=head[at][0];x!=-1;x=nxt[x]) if(nxtfree[to[x]]==-1) {
			nxtfree[to[x]]=at; dfree[to[x]]=dfree[at]+1; q[qhead++]=to[x];
		}
	}

	REP(i,n) prv[i]=-1;
	qhead=qtail=0; q[qhead]=0; qsame[qhead]=false; ++qhead; prv[0]=-2;
	while(qtail<qhead) {
		int ohead=qhead;
		REP(j,10) {
			bool anyj=false;
			FOR(i,qtail,ohead) {
				if(!qsame[i]) anyj=false;
				int at=q[i]; bool anyi=false;
				for(int x=head[at][j];x!=-1;x=nxt[x]) if(prv[to[x]]==-1) {
					prv[to[x]]=at; pcst[to[x]]=j; q[qhead]=to[x]; qsame[qhead]=anyi||anyj; ++qhead; anyi=anyj=true;
				}
			}
		}
		qtail=ohead;
	}

	qtail=0; while(nxtfree[q[qtail]]==-1) ++qtail;
	int mid=q[qtail];
	for(int i=qtail+1;i<qhead&&qsame[i];++i) if(dfree[q[i]]<dfree[mid]) mid=q[i];

	nret=0;
	for(int at=mid;at!=0;at=prv[at]) { retcst[nret]='0'+pcst[at]; ret[nret]=at; ++nret; }
	if(nret==0) retcst[nret]='0',retcst[nret+1]='\0'; else retcst[nret]='\0'; ret[nret]=0; ++nret; reverse(ret,ret+nret);
	for(int at=mid;at!=n-1;at=nxtfree[at]) ret[nret++]=nxtfree[at];
	printf("%s\n",retcst);
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}