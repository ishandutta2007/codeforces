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
const int MAXP=11;
const int MAXDV=6720;

int n; ll want;
ll a[MAXN];

ll p[MAXP]; int pcnt[MAXP]; int np;

void factorize(ll x) {
	np=0;
	for(int i=2;(ll)i*i<=x;++i) if(x%i==0) {
		p[np]=i; pcnt[np]=0; while(x%i==0) x/=i,pcnt[np]++; ++np;
	}
	if(x!=1) p[np]=x,pcnt[np]=1,++np;
}

/*
int pp[]={2,3,5,7,11,13,17,19,23,29,31,37};
int mxways;
void dfs(int at,ll prod,int ways) {
	if(ways>mxways) mxways=ways,printf("%lld = %d\n",prod,ways);
	for(int cnt=1;;++cnt) {
		prod*=pp[at];
		if(prod>1e12) break;
		dfs(at+1,prod,ways*(cnt+1));
	}
}
//dfs(0,1,1);
963761198400 = 6720
*/

int ndv;
int cur[MAXP];
int ap[MAXN][MAXP];
int dvp[MAXDV][MAXP];
int calcdv() { int ret=0,mult=1; REP(i,np) ret+=mult*cur[i],mult*=pcnt[i]+1; return ret; }
void initdvp(int at) { if(at>=np) { int j=calcdv(); REP(k,np) dvp[j][k]=cur[k]; } else { for(cur[at]=0;cur[at]<=pcnt[at];++cur[at]) initdvp(at+1); } }

int mncnt[MAXN+1][MAXDV];
ll mnsum[MAXN+1][MAXDV];
int pj[MAXN+1][MAXDV];

int ret[MAXN],nret;

void run() {
	scanf("%d%lld",&n,&want);
	REP(i,n) scanf("%lld",&a[i]);
	
	factorize(want);
	ndv=1; REP(i,np) ndv*=pcnt[i]+1;
	//REP(i,np) printf("%lld^%d ",p[i],pcnt[i]); printf("-> %d\n",ndv);

	REP(i,n) REP(k,np) { ap[i][k]=0; ll x=a[i]; while(x%p[k]==0) x/=p[k],++ap[i][k]; }
	initdvp(0);
	//REP(i,n) { REP(k,np) printf("%d ",ap[i][k]); puts(""); } puts("");
	//REP(j,ndv) { REP(k,np) printf("%d ",dvp[j][k]); puts(""); } puts("");
	
	memset(mncnt,-1,sizeof(mncnt)); mncnt[0][0]=0; mnsum[0][0]=0; pj[0][0]=-1;
	REP(i,n) {
		REP(j,ndv) mncnt[i+1][j]=mncnt[i][j],mnsum[i+1][j]=mnsum[i][j],pj[i+1][j]=j;
		REP(j,ndv) if(mncnt[i][j]!=-1) {
			REP(k,np) cur[k]=min(pcnt[k],ap[i][k]+dvp[j][k]);
			int nj=calcdv(),ncnt=mncnt[i][j]+1; ll nsum=mnsum[i][j]+a[i];
			//printf("%d %d -> %d %d (%d,%lld)\n",i,j,i+1,nj,ncnt,nsum);
			if(mncnt[i+1][nj]==-1||ncnt<mncnt[i+1][nj]||ncnt==mncnt[i+1][nj]&&nsum<mnsum[i+1][nj]) mncnt[i+1][nj]=ncnt,mnsum[i+1][nj]=nsum,pj[i+1][nj]=j;
		}
	}

	//printf("%d %lld\n",mncnt[n][ndv-1],mnsum[n][ndv-1]);

	if(mncnt[n][ndv-1]==-1) { printf("-1\n"); return; }

	nret=0;
	for(int i=n,j=ndv-1;i>0;j=pj[i][j],--i) {
		//printf("%d %d\n",i,j);
		if(j!=pj[i][j]) ret[nret++]=i-1;
	}
	if(nret==0) { int y=0; FOR(i,1,n) if(a[i]<a[y]) y=i; ret[nret++]=y; }
	printf("%d\n",nret);
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
		

}

int main() {
	run();
	return 0;
}