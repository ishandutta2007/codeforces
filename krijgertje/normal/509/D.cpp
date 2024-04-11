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

int nrow,ncol;
int mink;
int val[100][100];
int a[100],b[100],k;

void run() {
	scanf("%d%d",&nrow,&ncol);
	REP(i,nrow) REP(j,ncol) scanf("%d",&val[i][j]);

	//nrow=10,ncol=10,k=10; REP(i,nrow) a[i]=rand()%10; REP(j,ncol) b[j]=rand()%10; REP(i,nrow) REP(j,ncol) val[i][j]=(a[i]+b[j])%k;
	//REP(i,nrow) printf(" %2d",a[i]); puts("");
	//REP(j,ncol) printf(" %2d",b[j]); puts("");
	//REP(i,nrow) { REP(j,ncol) printf("%2d ",val[i][j]); puts(""); } puts("");

	mink=1; REP(i,nrow) REP(j,ncol) if(val[i][j]>=mink) mink=val[i][j]+1;
	REP(i,nrow) a[i]=0; REP(j,ncol) b[j]=0;
	REP(j,ncol) {
		int l=val[0][j]; FOR(i,1,nrow) if(val[i][j]<l) l=val[i][j];
		b[j]+=l; REP(i,nrow) val[i][j]-=l;
	}
	{
		int h=val[0][0]; FOR(j,1,ncol) if(val[0][j]>h) h=val[0][j];
		REP(j,ncol) { int d=h-val[0][j]; b[j]-=d; REP(i,nrow) val[i][j]+=d; }
	}
	REP(i,nrow) {
		int l=val[i][0]; FOR(j,1,ncol) if(val[i][j]<l) l=val[i][j];
		a[i]+=l; REP(j,ncol) val[i][j]-=l;
	}
	k=-1;
	REP(i,nrow) REP(j,ncol) if(val[i][j]!=0) {
		if(k==-1) k=val[i][j];
		if(val[i][j]!=k) { printf("NO\n"); return; }
	}
	if(k==-1) {
		k=mink;
	} else if(k<mink) {
		printf("NO\n"); return;
	}
	REP(i,nrow) a[i]=((ll)a[i]%k+k)%k;
	REP(j,ncol) b[j]=((ll)b[j]%k+k)%k;

	printf("YES\n");
	printf("%d\n",k);
	REP(i,nrow) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
	REP(j,ncol) { if(j!=0) printf(" "); printf("%d",b[j]); } puts("");
	//REP(i,nrow) { REP(j,ncol) printf("%2d ",val[i][j]); puts(""); } puts("");
}

int main() {
	run();
	return 0;
}