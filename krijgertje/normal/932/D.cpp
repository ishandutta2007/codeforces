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

const int MAXQ=400000;
const int MAXN=1+MAXQ;
const int MAXLG=18;

int nq;
int n;
int dep[MAXN];
int up[MAXN][MAXLG+1]; // go (1<<i) steps up
ll sum[MAXN][MAXLG+1]; // sum of nodes [x,y) where y is (1<<i) steps up

int getrealpar(int at,int need) {
	if(sum[at][0]>=need) return at;
	for(int k=MAXLG;k>=0;--k) if(dep[at]-(1<<k)>=0&&sum[up[at][k]][0]<need) at=up[at][k];
	if(dep[at]==0) return -1;
	return up[at][0];
}

int solve(int at,ll lim) {
	int ret=0;
	for(int k=MAXLG;k>=0;--k) if(dep[at]-(1<<k)>=0&&sum[at][k]<=lim) ret+=1<<k,lim-=sum[at][k],at=up[at][k];
	if(sum[at][0]<=lim) ++ret;
	return ret;
}

void run() {
	scanf("%d",&nq);
	n=1; dep[0]=0; up[0][0]=0; REP(k,MAXLG) up[0][k+1]=up[up[0][k]][k]; sum[0][0]=0; REP(k,MAXLG) sum[0][k+1]=sum[0][k]+sum[up[0][k]][k];

	int last=0;
	REP(qi,nq) {
		int kind; ll p,q; scanf("%d%lld%lld",&kind,&p,&q); p^=last; q^=last;
		//printf("q%d: %d %lld %lld\n",qi,kind,p,q);
		if(kind==1) {
			assert(1<=p&&p<=n); int par=p-1; assert(0<=q&&q<=1000000000); int w=q;
			par=getrealpar(par,w);
			//printf("node %d: parent=%d\n",n+1,par+1);
			dep[n]=par==-1?0:dep[par]+1; up[n][0]=par==-1?n:par; REP(k,MAXLG) up[n][k+1]=up[up[n][k]][k]; sum[n][0]=w; REP(k,MAXLG) sum[n][k+1]=sum[n][k]+sum[up[n][k]][k]; ++n;
		}
		if(kind==2) {
			assert(1<=p&&p<=n); int at=p-1; assert(0<=q&&q<=1000000000000000LL); ll lim=q;
			int ans=solve(at,lim);
			printf("%d\n",ans);
			last=ans;
		}
	}
}

int main() {
	run();
	return 0;
}