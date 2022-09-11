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
const int MAXS=4*MAXN;

int n,nq;
int a[MAXN];

double ssum[MAXS],slazymlt[MAXS],slazyadd[MAXS];

void sapply(int x,double mlt,double add,int cnt) {
	ssum[x]=ssum[x]*mlt+add*cnt;
	slazymlt[x]*=mlt;
	slazyadd[x]*=mlt; slazyadd[x]+=add;
}
void spush(int x,int cnt1,int cnt2) {
	if(slazymlt[x]!=1||slazyadd[x]!=0) sapply(2*x+1,slazymlt[x],slazyadd[x],cnt1),sapply(2*x+2,slazymlt[x],slazyadd[x],cnt2),slazymlt[x]=1,slazyadd[x]=0;
}
void spull(int x) {
	ssum[x]=ssum[2*x+1]+ssum[2*x+2];
}
void sinit(int x,int l,int r) {
	slazymlt[x]=1,slazyadd[x]=0;
	if(l==r) {
		ssum[x]=a[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
}
double sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return ssum[x];
	} else {
		int m=l+(r-l)/2; double ret=0;
		spush(x,m-l+1,r-m);
		if(L<=m) ret+=sget(2*x+1,l,m,L,R);
		if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R);
		spull(x);
		return ret;
	}
}
void smod(int x,int l,int r,int L,int R,double mlt,double add) {
	//printf("smod(%d,%d..%d,%d..%d,*%lf,+%lf)\n",x,l,r,L,R,mlt,add);
	if(L<=l&&r<=R) {
		sapply(x,mlt,add,r-l+1);
	} else {
		int m=l+(r-l)/2;
		spush(x,m-l+1,r-m);
		if(L<=m) smod(2*x+1,l,m,L,R,mlt,add);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,mlt,add);
		spull(x);
	}
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]);

	sinit(0,0,n-1);
	REP(qi,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int l1,r1,l2,r2; scanf("%d%d%d%d",&l1,&r1,&l2,&r2); --l1,--r1,--l2,--r2;
			double sum1=sget(0,0,n-1,l1,r1),sum2=sget(0,0,n-1,l2,r2);
			int cnt1=r1-l1+1,cnt2=r2-l2+1;
			//printf("%d..%d=%lf (%d) / %d..%d=%lf (%d)\n",l1,r1,sum1,cnt1,l2,r2,sum2,cnt2);
			smod(0,0,n-1,l1,r1,1.0*(cnt1-1)/cnt1,sum2/cnt1/cnt2);
			smod(0,0,n-1,l2,r2,1.0*(cnt2-1)/cnt2,sum1/cnt1/cnt2);
		}
		if(kind==2) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			double sum=sget(0,0,n-1,l,r);
			printf("%.15lf\n",sum);
		}
	}
}

int main() {
	run();
	return 0;
}