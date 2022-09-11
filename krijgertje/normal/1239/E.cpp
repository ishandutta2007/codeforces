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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXW=25;
const int MAXN=2*MAXW;
const int MAXA=50000;
const int MAXLIM=(MAXW-1)*MAXA;

int w,n;
int a[MAXN];
int ansfield[2][MAXW];

int act[MAXW][MAXLIM+1];

int kind[MAXN];
int b[MAXN],nb;
int c[MAXN],nc;

int solve() {
	sort(a,a+n);
	int x=a[0],y=a[1];
	int sum=0; FOR(i,2,n) sum+=a[i];
	int lim=sum/2;
	REPE(i,w-1) REPE(j,lim) act[i][j]=-1; act[0][0]=0;
	FOR(k,2,n) for(int i=w-2;i>=0;--i) REPE(j,lim) if(act[i][j]!=-1&&act[i+1][j+a[k]]==-1) act[i+1][j+a[k]]=k;
	//REPE(i,w-1) REPE(j,lim) if(act[i][j]!=-1) printf("(%d,%d):%d\n",i,j,act[i][j]);
	REP(i,n) kind[i]=-1;
	kind[0]=kind[1]=0;
	{
		int i=w-1,j=lim; while(j>=0&&act[i][j]==-1) --j; assert(j>=0);
		while(i>=1) { assert(act[i][j]!=-1); int k=act[i][j]; assert(kind[k]==-1); kind[k]=1; --i,j-=a[k]; }
	}
	REP(i,n) if(kind[i]==-1) kind[i]=2;
	nb=nc=0; REP(i,n) if(kind[i]==1) b[nb++]=a[i]; else if(kind[i]==2) c[nc++]=a[i];
	sort(b,b+nb); sort(c,c+nc); reverse(c,c+nc); assert(nb==w-1); assert(nc==w-1);
	ansfield[0][0]=a[0]; REP(i,nb) ansfield[0][i+1]=b[i];
	REP(i,nc) ansfield[1][i]=c[i]; ansfield[1][w-1]=a[1];
	int ret=a[0]+a[1]; REP(i,nc) ret+=c[i]; return ret;
}

void run() {
	scanf("%d",&w); n=2*w;
	REP(i,n) scanf("%d",&a[i]);
	int ans=solve();
	//printf("%d\n",ans);
	REP(x,2) { REP(y,w) { if(y!=0) printf(" "); printf("%d",ansfield[x][y]); } puts(""); }

}

int main() {
	run();
	return 0;
}