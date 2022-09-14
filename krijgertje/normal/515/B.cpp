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

const int MAXNA=100;
const int MAXNB=100;

typedef struct Val {
	int idx,t; bool need;
} Val;
bool operator<(const Val &p,const Val &q) {
	if(p.idx!=q.idx) return p.idx<q.idx;
	if(p.t!=q.t) return p.t<q.t;
	if(p.need!=q.need) return !p.need;
	return false;
}

int nval;
Val val[MAXNA+MAXNB];

// ret=x*a+y*b;
int egcd(int a,int b,int &x,int &y) {
	if(b==0) { x=1,y=0; return a; }
	int g=egcd(b,a%b,x,y);
	swap(x,y); y-=x*(a/b); return g;
}

// xa=c mod b -> xa+y*b=c
int solve(int a,int c,int b) {
	int x,y,g;
	g=egcd(a,b,x,y);
	assert(c%g==0);
	x%=b; if(x<0) x+=b;
	return (ll)x*(c/g)%b;
}

ll calc(int A,int B,int g,int z,int* a,int* b,int* fsta,int *nxta,int* fstb,int* nxtb) {
	ll ret=0;
	nval=0;
	for(int x=fsta[z];x!=-1;x=nxta[x]) { val[nval].t=a[x]; val[nval].idx=solve(B/g,(a[x]-z)/g,A/g); val[nval].need=false; ++nval; }
	for(int x=fstb[z];x!=-1;x=nxtb[x]) { val[nval].t=b[x]; val[nval].idx=solve(B/g,(b[x]-z)/g,A/g); val[nval].need=true; ++nval; }
	sort(val,val+nval);
	{ int nnval=0; REP(i,nval) if(nnval==0||val[nnval-1].idx!=val[i].idx) val[nnval++]=val[i]; nval=nnval; }
//	REP(i,nval) printf("%d: %d %c\n",val[i].idx,val[i].t,val[i].need?'!':'.');

	REP(i,nval) {
		int l=val[i].idx+(val[i].need?0:1),h=i+1<nval?val[i+1].idx-1:val[0].idx-1+A/g;
		if(l>h) continue;
		ll cur=val[i].t+(ll)(h-val[i].idx)*B;
		if(cur>ret) ret=cur;
	}
	//printf("->%lld\n",ret);
	return ret;
}

int A,B,na,nb,g;
int a[MAXNA],b[MAXNB];

int fsta[MAXNA+MAXNB],fstb[MAXNA+MAXNB];
int nxta[MAXNA],nxtb[MAXNB];

ll calc(int z) {
	//printf("%d:",z); for(int x=fsta[z];x!=-1;x=nxta[x]) printf(" %d",x); printf(" |"); for(int x=fstb[z];x!=-1;x=nxtb[x]) printf(" %d",x); puts("");
	if(fsta[z]==-1&&fstb[z]==-1) return -1;
	ll reta=calc(A,B,g,z,a,b,fsta,nxta,fstb,nxtb);
	ll retb=calc(B,A,g,z,b,a,fstb,nxtb,fsta,nxta);
	return max(reta,retb);
}

void run() {
	scanf("%d%d",&A,&B); scanf("%d",&na); REP(i,na) scanf("%d",&a[i]); scanf("%d",&nb); REP(i,nb) scanf("%d",&b[i]);
	g=gcd(A,B);
	if(g>na+nb) { printf("No\n"); return; }
	REP(i,g) fsta[i]=fstb[i]=-1;
	REP(i,na) { int cur=a[i]%g; nxta[i]=fsta[cur]; fsta[cur]=i; }
	REP(i,nb) { int cur=b[i]%g; nxtb[i]=fstb[cur]; fstb[cur]=i; }

	ll ret=0;
	REP(i,g) {
		ll cur=calc(i);
		if(cur==-1) { printf("No\n"); return; }
		if(cur>ret) ret=cur;
	}
	printf("Yes\n");	
}

int main() {
	run();
	return 0;
}