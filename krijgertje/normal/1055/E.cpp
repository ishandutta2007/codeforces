#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXA=1500;
const int MAXSEG=1500;

int na,nseg,nchoose,wantorder;
int a[MAXA];
int l[MAXSEG],r[MAXSEG];

int nxt[MAXA];
int sum[MAXA+1];
int dp[MAXSEG+1][MAXA+1];

void upd(int &a,int b) { a=max(a,b); }
bool can(int x) {
	sum[0]=0; REP(i,na) sum[i+1]=sum[i]+(a[i]<=x?1:0);
	REPE(i,nchoose) REPE(j,na) dp[i][j]=0;
	REPE(i,nchoose) REP(j,na) {
		// do not choose a segment that includes a[j]
		upd(dp[i][j+1],dp[i][j]);
		// choose some segment that includes a[j]
		if(i+1<=nchoose&&nxt[j]!=-1) upd(dp[i+1][nxt[j]],dp[i][j]+sum[nxt[j]]-sum[j]);
	}
	//printf("can(%d):\n",x); REPE(i,nchoose) REPE(j,na) printf("(%d,%d)=%d\n",i,j,dp[i][j]);
	REPE(i,nchoose) if(dp[i][na]>=wantorder) return true;
	//printf("no\n");
	return false;
}

int val[MAXA],nval;
int solve() {
	REP(j,na) nxt[j]=-1;
	REP(i,nseg) FORE(j,l[i],r[i]) nxt[j]=max(nxt[j],r[i]+1);

	nval=0; REP(i,na) val[nval++]=a[i]; sort(val,val+nval); nval=unique(val,val+nval)-val;
	int l=-1,h=nval;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(val[m])) h=m; else l=m;
	}
	return h==nval?-1:val[h];
}

void run() {
	scanf("%d%d%d%d",&na,&nseg,&nchoose,&wantorder);
	REP(i,na) scanf("%d",&a[i]);
	REP(i,nseg) scanf("%d%d",&l[i],&r[i]),--l[i],--r[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}