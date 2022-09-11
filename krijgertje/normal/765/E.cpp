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

int n;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int deg[MAXN],dead[MAXN];
vector<int> todo[MAXN];

int q[MAXN],qhead,qtail;

int solve() {
	qhead=qtail=0;
	REP(i,n) if(deg[i]==1) q[qhead++]=i;
	int nedge=n-1;
	int root=-1;
	while(qtail<qhead) {
		int at=q[qtail++];
		//printf("at=%d\n",at+1);
		int par=-1; for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(dead[to]) continue; assert(par==-1); par=to; }
		//printf("par=%d\n",par+1);
		if(par==-1) {
			if(root!=-1) return -1;
			root=at; continue;
		} else {
			int ntodo;
			if(SZ(todo[at])==0) {
				ntodo=1;
			} else {
				int fst=todo[at][0]; bool now=true;
				REPSZ(i,todo[at]) if(todo[at][i]!=fst) now=false;
				if(!now) { if(root!=-1) return -1; root=at; continue; }
				nedge-=(SZ(todo[at])-1)*fst;
				ntodo=fst+1;
			}
			dead[at]=true; todo[par].PB(ntodo); if(--deg[par]==1) q[qhead++]=par;		
		}
	}
	if(root!=-1&&SZ(todo[root])>=3) {
		sort(todo[root].begin(),todo[root].end());
		int mn=todo[root][0],mx=todo[root].back(),cnt=SZ(todo[root]);
		if(mn==mx) {
			nedge-=(cnt-2)*mn;
		} else {
			int mncnt=0,mxcnt=0; REPSZ(i,todo[root]) if(todo[root][i]==mn) ++mncnt; else if(todo[root][i]==mx) ++mxcnt; else return -1;
			nedge-=(mncnt-1)*mn; nedge-=(mxcnt-1)*mx;
		}
	}
	while(nedge%2==0) nedge/=2; return nedge;
}

void run() {
	scanf("%d",&n);
	REP(i,n) ghead[i]=-1,deg[i]=0,dead[i]=false,todo[i].clear();
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a],ghead[a]=2*i+0,gto[2*i+0]=b,++deg[a];
		gnxt[2*i+1]=ghead[b],ghead[b]=2*i+1,gto[2*i+1]=a,++deg[b];
	}
	printf("%d\n",solve());
}
int main() {
	run();
	return 0;
}