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

const int MAXN=400000;
const int MAXQ=200000;
const int MAXVAL=300;
const int MAXS=4*MAXN;
const int MOD=1000000007;
int pw(int x,ll n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int n,nq;
int a[MAXN];
int qkind[MAXQ],ql[MAXQ],qr[MAXQ],qval[MAXQ],qans[MAXQ];

int pmn[MAXVAL+1];
int p[MAXVAL+1],np;

int b[MAXN];

int sval[MAXS];
int slazy[MAXS];

void sapply(int x,int l,int r,int by) {
	slazy[x]=(ll)slazy[x]*by%MOD;
	sval[x]=(ll)sval[x]*pw(by,r-l+1)%MOD;
}
void spush(int x,int l,int m,int r) {
	if(slazy[x]!=1) sapply(2*x+1,l,m,slazy[x]),sapply(2*x+2,m+1,r,slazy[x]),slazy[x]=1;
}
void spull(int x,int l,int r) {
	sval[x]=(ll)sval[2*x+1]*sval[2*x+2]%MOD*pw(slazy[x],r-l+1)%MOD;
}
void sinit(int x,int l,int r) {
	slazy[x]=1;
	if(l==r) {
		sval[x]=b[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x,l,r);
	}
}
void smod(int x,int l,int r,int L,int R,int BY) {
	if(L<=l&&r<=R) {
		sapply(x,l,r,BY);
	} else {
		int m=l+(r-l)/2; spush(x,l,m,r);
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		spull(x,l,r);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2; spush(x,l,m,r);
		int ret=1;
		if(L<=m) ret=(ll)ret*sget(2*x+1,l,m,L,R)%MOD;
		if(m+1<=R) ret=(ll)ret*sget(2*x+2,m+1,r,L,R)%MOD;
		return ret;
	}
}

ll c[MAXS];

ll sval2[MAXS],slazy2[MAXS];
void sapply2(int x,ll mask) { 
	sval2[x]|=mask; slazy2[x]|=mask;
}
void spush2(int x) {
	if(slazy2[x]!=0) sapply2(2*x+1,slazy2[x]),sapply2(2*x+2,slazy2[x]),slazy2[x]=0;
}
void spull2(int x) {
	sval2[x]=sval2[2*x+1]|sval2[2*x+2]|slazy2[x];
}
void sinit2(int x,int l,int r) {
	slazy2[x]=0;
	if(l==r) {
		sval2[x]=c[l];
	} else {
		int m=l+(r-l)/2;
		sinit2(2*x+1,l,m);
		sinit2(2*x+2,m+1,r);
		spull2(x);
	}
}
void smod2(int x,int l,int r,int L,int R,ll MASK) {
	if(L<=l&&r<=R) {
		sapply2(x,MASK);
	} else {
		int m=l+(r-l)/2; spush2(x);
		if(L<=m) smod2(2*x+1,l,m,L,R,MASK);
		if(m+1<=R) smod2(2*x+2,m+1,r,L,R,MASK);
		spull2(x);
	}
}
ll sget2(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval2[x];
	} else {
		int m=l+(r-l)/2; spush2(x);
		ll ret=0;
		if(L<=m) ret|=sget2(2*x+1,l,m,L,R);
		if(m+1<=R) ret|=sget2(2*x+2,m+1,r,L,R);
		return ret;
	}
}

int inv[MAXVAL+1];

void solve() {
	inv[1]=1; FORE(i,2,MAXVAL) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	REPE(i,MAXVAL) pmn[i]=-1;
	FORE(i,2,MAXVAL) if(pmn[i]==-1) for(int j=i;j<=MAXVAL;j+=i) if(pmn[j]==-1) pmn[j]=i;
	np=0; REPE(i,MAXVAL) if(pmn[i]==i) p[np++]=i;
	//printf("p (%d):",np); REP(i,np) printf(" %d",p[i]); puts("");


	REP(i,n) b[i]=a[i];
	sinit(0,0,n-1);
	REP(i,nq) {
		if(qkind[i]==0) smod(0,0,n-1,ql[i],qr[i],qval[i]);
		if(qkind[i]==1) qans[i]=sget(0,0,n-1,ql[i],qr[i]);
	}


	REP(i,n) { c[i]=0; REP(j,np) if(a[i]%p[j]==0) c[i]|=1LL<<j; }
	sinit2(0,0,n-1);
	REP(i,nq) {
		if(qkind[i]==0) { ll mask=0; REP(j,np) if(qval[i]%p[j]==0) mask|=1LL<<j; smod2(0,0,n-1,ql[i],qr[i],mask); }
		if(qkind[i]==1) { ll mask=sget2(0,0,n-1,ql[i],qr[i]); REP(j,np) if(mask&(1LL<<j)) qans[i]=(ll)qans[i]*inv[p[j]]%MOD*(p[j]-1)%MOD; }
	}


	/*REP(i,nq) qans[i]=1;
	REP(i,np) {
		REP(j,n) { int cnt=0,x=a[j]; while(x%p[i]==0) ++cnt,x/=p[i]; b[j]=cnt; }
		//bool any=false; REP(j,n) if(b[j]!=0) any=true; if(any) { printf("%d:",p[i]); REP(j,n) printf(" %d",b[j]); puts(""); }
		sinit(0,0,n-1);
		REP(j,nq) {
			if(qkind[j]==0) {
				int cnt=0,x=qval[j]; while(x%p[i]==0) ++cnt,x/=p[i]; 
				if(cnt!=0) { 
					//printf("%d: modifying %d..%d by %d\n",p[i],ql[j],qr[j],cnt);
					smod(0,0,n-1,ql[j],qr[j],cnt);
				}
			}
			if(qkind[j]==1) { 
				ll sum=sget(0,0,n-1,ql[j],qr[j]);
				if(sum!=0) { 
					int mlt=(ll)pw(p[i],sum-1)*(p[i]+MOD-1)%MOD;
					//printf("%d: getting %d..%d = %lld -> %d\n",p[i],ql[j],qr[j],sum,mlt);
					qans[j]=(ll)qans[j]*mlt%MOD; 
				} 
			}
		}
	}*/
}

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,nq) { char s[20]; scanf("%s",s); fflush(stdout); if(strcmp(s,"MULTIPLY")==0) { qkind[i]=0; scanf("%d%d%d",&ql[i],&qr[i],&qval[i]); --ql[i],--qr[i]; } if(strcmp(s,"TOTIENT")==0) { qkind[i]=1; scanf("%d%d",&ql[i],&qr[i]); --ql[i],--qr[i]; } }
	
	solve();
	REP(i,nq) if(qkind[i]==1) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}