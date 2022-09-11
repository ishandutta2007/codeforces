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

const int MAXN=100000;
const int MAXSEG=300;
const int MAXS=4*MAXN;

int n,nseg;
int a[MAXN];
int l[MAXSEG],r[MAXSEG];

int ansval;
int ans[MAXSEG],nans;

vector<int> byr[MAXN];
int b[MAXN];
int lst[MAXSEG],nlst;

int slazy[MAXS];
int sval[MAXS];

void sinit(int x,int l,int r) {
	slazy[x]=0;
	if(l==r) {
		sval[x]=b[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=slazy[x]+min(sval[2*x+1],sval[2*x+2]);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sval[x]+=BY;
		slazy[x]+=BY;
	} else {
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		sval[x]=slazy[x]+min(sval[2*x+1],sval[2*x+2]);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2;
		int ret=INT_MAX;
		if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
		assert(ret!=INT_MAX);
		return slazy[x]+ret;
	}
}

void solveminfirst() {
	sinit(0,0,n-1); nlst=0; int anscnt=-1;
	REP(i,n) {
		if(i!=0) {
			int lo=sget(0,0,n-1,0,i-1),hi=b[i];
			int cur=hi-lo; if(cur>ansval) { ansval=cur; anscnt=nlst; }
		}
		REPSZ(j,byr[i]) {
			int idx=byr[i][j];
			lst[nlst++]=idx;
			smod(0,0,n-1,l[idx],r[idx],-1);
		}
	}
	if(anscnt!=-1) { nans=anscnt; REP(i,nans) ans[i]=lst[i]; }
}

int solve() {
	REP(i,n) byr[i].clear(); REP(i,nseg) byr[r[i]].PB(i);
	ansval=0; nans=0;
	REP(i,n) b[i]=a[i];
	REP(rep,2) {
		REP(i,n) byr[i].clear(); REP(i,nseg) byr[r[i]].PB(i);
		solveminfirst();
		reverse(b,b+n);
		REP(i,nseg) { swap(l[i],r[i]); l[i]=n-l[i]-1; r[i]=n-r[i]-1; }
	}
	return ansval;
}

void run() {
	scanf("%d%d",&n,&nseg);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nseg) scanf("%d%d",&l[i],&r[i]),--l[i],--r[i];
	printf("%d\n",solve());
	printf("%d\n",nans);
	REP(i,nans) { if(i!=0) printf(" "); printf("%d",ans[i]+1); } puts("");
}

bool verify(int have) {
	return true;
}

int bfsolve() {
	int ret=0; REP(i,1<<nseg) { REP(j,n) b[j]=a[j]; REP(j,nseg) if(i&(1<<j)) FORE(k,l[j],r[j]) --b[k]; int mn=b[0],mx=b[0]; REP(j,n) mn=min(mn,b[j]),mx=max(mx,b[j]); ret=max(ret,mx-mn); } return ret;
}

void stress() {
	REP(rep,1000) {
		n=10; REP(i,n) a[i]=rand()%10;
		nseg=10; REP(i,nseg) { l[i]=rand()%n,r[i]=rand()%n; if(l[i]>r[i]) swap(l[i],r[i]); }
		int have=solve();
		int want=bfsolve();
		bool ok=verify(have);
		if(ok&&have==want) { printf("."); continue; }
		printf("err have=%d want=%d\n",have,want);
		printf("%d %d\n",n,nseg);
		REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
		REP(i,nseg) printf("%d %d\n",l[i]+1,r[i]+1);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}