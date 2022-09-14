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

const int MOD=1000000009;
const int C1=276601605,C2=723398404,B1=691504013,B2=308495997; // F(n)=C1*B1^n+C2*B2^n

int B1pow[300001],B2pow[300001];
int B1gsum[300001],B2gsum[300001];


int mpow(int x,int n) {
	if(n==0) return 1;
	if(n%2==1) return (ll)mpow(x,n-1)*x%MOD;
	return mpow((ll)x*x%MOD,n/2);
}

int gsum(int x,int n) {
	//S=(x^(n+1)-1)/(x-1);
	int ret=(ll)(mpow(x,n)-1)*mpow(x-1,MOD-2)%MOD;
//	printf("\tgsum(%d,%d)=%d\n",x,n,ret);
	return ret;
}


int val[1<<20],lazy1[1<<20],lazy2[1<<20];

void push(int x,int l,int m,int r) {
	if(lazy1[x]==0&&lazy2[x]==0) return;
	int l1a=lazy1[x],l1b=(ll)lazy1[x]*B1pow[m+1-l]%MOD;
	int l2a=lazy2[x],l2b=(ll)lazy2[x]*B2pow[m+1-l]%MOD;
	lazy1[2*x+1]=(lazy1[2*x+1]+l1a)%MOD;
	lazy1[2*x+2]=(lazy1[2*x+2]+l1b)%MOD;
	lazy2[2*x+1]=(lazy2[2*x+1]+l2a)%MOD;
	lazy2[2*x+2]=(lazy2[2*x+2]+l2b)%MOD;
	val[2*x+1]=(val[2*x+1]+(ll)l1a*B1gsum[m+1-l]+(ll)l2a*B2gsum[m+1-l])%MOD;
	val[2*x+2]=(val[2*x+2]+(ll)l1b*B1gsum[r-m]+(ll)l2b*B2gsum[r-m])%MOD;
	lazy1[x]=lazy2[x]=0;
//	printf("pushed [%d..%d/%d..%d] -> %d (%d,%d) / %d (%d,%d)\n",l,m,m+1,r,val[2*x+1],lazy1[2*x+1],lazy2[2*x+1],val[2*x+2],lazy1[2*x+2],lazy2[2*x+2]);
}


int n;
void inc(int x,int l,int r,int L,int R,int c1,int c2) { // val[ll+i]+=c1*B1^i+c2*B2^i
	if(L<l) { c1=(ll)c1*B1pow[l-L]%MOD; c2=(ll)c2*B2pow[l-L]%MOD; L=l; } if(R>r) R=r; if(L>R) return;
	if(L==l&&r==R) {
		lazy1[x]=(lazy1[x]+c1)%MOD; lazy2[x]=(lazy2[x]+c2)%MOD;
		val[x]=(val[x]+(ll)c1*B1gsum[r-l+1]+(ll)c2*B2gsum[r-l+1])%MOD;
	} else {
		int m=l+(r-l)/2;
		push(x,l,m,r);
		if(L<=m) inc(2*x+1,l,m,L,R,c1,c2);
		if(R>=m+1) inc(2*x+2,m+1,r,L,R,c1,c2);
		val[x]=val[2*x+1]+val[2*x+2]; if(val[x]>=MOD) val[x]-=MOD;
	}
//	printf("%d = [%d..%d] -> %d (%d,%d)\n",x,l,r,val[x],lazy1[x],lazy2[x]);
}

int get(int x,int l,int r,int L,int R) {
	if(L<l) L=l; if(R>r) R=r; if(L>R) return 0;
	if(L==l&&r==R) {
		return val[x];
	} else {
		int m=l+(r-l)/2;
		push(x,l,m,r);
		if(R<m+1) return get(2*x+1,l,m,L,R);
		if(L>m) return get(2*x+2,m+1,r,L,R);
		int ret=get(2*x+1,l,m,L,R)+get(2*x+2,m+1,r,L,R); if(ret>=MOD) ret-=MOD; return ret;
	}
}

int nq;


void run() {
	scanf("%d%d",&n,&nq);

	B1pow[0]=1; FORE(i,1,n) B1pow[i]=(ll)B1pow[i-1]*B1%MOD;
	B2pow[0]=1; FORE(i,1,n) B2pow[i]=(ll)B2pow[i-1]*B2%MOD;
	B1gsum[0]=0; FORE(i,1,n) B1gsum[i]=((ll)B1gsum[i-1]*B1+1)%MOD;
	B2gsum[0]=0; FORE(i,1,n) B2gsum[i]=((ll)B2gsum[i-1]*B2+1)%MOD;

	REP(i,n) { int x; scanf("%d",&x); inc(0,0,n-1,i,i,x,0); }

	REP(i,nq) {
		int type,l,r; scanf("%d%d%d",&type,&l,&r); --l,--r;
		if(type==1) {
			inc(0,0,n-1,l,r,(ll)C1*B1%MOD,(ll)C2*B2%MOD);
		}
		if(type==2) {
			int res=get(0,0,n-1,l,r);
			printf("%d\n",res);
		}
	}
}

int main() {
	run();
	return 0;
}