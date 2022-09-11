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

const int MAXN=200000;
const int MOD=998244353;

int n,mxval;
int a[MAXN];

int b[MAXN],nb;

int dpsame[MAXN+1][2];
int dpdiff[MAXN+1][2];

int calc() {
	//printf("b:"); REP(i,nb) printf(" %d",b[i]); puts("");
	int ret=1;
	for(int l=0,r=l;l<nb;l=r) {
		while(r<nb&&b[l]==b[r]) ++r;
		int val=b[l],cnt=r-l;
		if(val!=-1) { if(cnt>=2) return 0; else continue; }
		if(l==0&&r==nb) { REP(i,cnt) ret=(ll)ret*(mxval-(i==0?0:1))%MOD; }
		else if(l==0||r==nb) { REP(i,cnt) ret=(ll)ret*(mxval-1)%MOD; }
		else { int cur=b[l-1]==b[r]?dpsame[cnt][0]:dpdiff[cnt][0]; ret=(ll)ret*cur%MOD; }
	}
	return ret;
}

void inc(int &a,ll b) { a=(a+b)%MOD; }
int solve() {
	memset(dpsame,0,sizeof(dpsame)); dpsame[0][1]=1; FORE(i,1,n) { inc(dpsame[i][0],(ll)(mxval-2)*dpsame[i-1][0]+(ll)(mxval-1)*dpsame[i-1][1]); inc(dpsame[i][1],dpsame[i-1][0]); }
	memset(dpdiff,0,sizeof(dpdiff)); dpdiff[0][0]=1; FORE(i,1,n) { inc(dpdiff[i][0],(ll)(mxval-2)*dpdiff[i-1][0]+(ll)(mxval-1)*dpdiff[i-1][1]); inc(dpdiff[i][1],dpdiff[i-1][0]); }

	int ret=1;
	REP(off,2) {
		nb=0; REP(i,n) if(i%2==off) b[nb++]=a[i];
		ret=(ll)ret*calc()%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&mxval);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int bfrec(int at) {
	if(at>=n) return 1;
	bool unknown=a[at]==-1; int l=unknown?1:a[at],r=unknown?mxval:a[at];
	int ret=0; FORE(v,l,r) { a[at]=v; if(at>=2&&a[at]==a[at-2]) continue; ret+=bfrec(at+1); } if(unknown) a[at]=-1; return ret;
}

int bfsolve() {
	return bfrec(0);
}

void stress() {
	REP(rep,1000) {
		n=rand()%16+1; mxval=rand()%4+2;
		for(int i=1;i<n;i+=2) a[i]=100+i;
		REP(i,n) a[i]=rand()%2==0?-1:rand()%mxval+1;
		int have=solve();
		int want=bfsolve();
		if(have==want) { printf("."); continue; }
		printf("rep=%d have=%d want=%d\n",rep,have,want);
		printf("%d %d\n",n,mxval);
		printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}