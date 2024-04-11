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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

int n;
int start[100000];
int cap[100000];
int gain[100000];

ll calcstart(int i,int t) {
	ll ret;
	if(gain[i]!=0&&t>=(cap[i]-start[i]+gain[i]-1)/gain[i]) {
		ret=cap[i];
	} else {
		ret=start[i]+t*gain[i];
	}
//	printf("calcstart(%d,%d)=%lld\n",i,t,ret);
	return ret;
}

int last[1<<18];
int fst[1<<18];
int cnt[1<<18];
int nitem;
int tcap[1768928];
ll capsum[1768928];
ll gainsum[1768928];

ll calc(int x,int t) {
	int l=fst[x]-1,h=fst[x]+cnt[x]; // (l,h]
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(tcap[m]>t) h=m; else l=m;
	}
	// [fst[x]..h-1] is at capacity, [h..fst[x]+cnt[x]-1] is not at capacity
	ll ret=0;
	ret+=h!=fst[x]?capsum[h-1]:0;
	ret+=(gainsum[fst[x]+cnt[x]-1]-(h!=fst[x]?gainsum[h-1]:0))*t;
//	printf("calc(%d,%d)=%lld [%d] {%lld,%lld*%d}\n",x,t,ret,h-fst[x],h!=fst[x]?capsum[h-1]:0,gainsum[fst[x]+cnt[x]-1]-(h!=fst[x]?gainsum[h-1]:0),t);
	return ret;
}

void init(int x,int l,int r) {
	if(l==r) {
		last[x]=-1; fst[x]=nitem; cnt[x]=0; int i=l;
		tcap[nitem]=gain[i]==0?INT_MAX:(cap[i]+gain[i]-1)/gain[i]; capsum[nitem]=cap[i]; gainsum[nitem]=gain[i]; ++nitem; ++cnt[x];
	} else {
		int m=l+(r-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,r);
		last[x]=-1; fst[x]=nitem; cnt[x]=0;
		int i=0,j=0,in=cnt[2*x+1],jn=cnt[2*x+2],si=fst[2*x+1],sj=fst[2*x+2];
		while(i<in||j<jn) {
			if(i<in&(j>=jn||tcap[si+i]<=tcap[sj+j])) {
				tcap[nitem]=tcap[si+i]; capsum[nitem]=capsum[si+i]+(j==0?0:capsum[sj+j-1]); gainsum[nitem]=gainsum[si+i]+(j==0?0:gainsum[sj+j-1]); ++nitem; ++cnt[x]; ++i;
			} else {
				tcap[nitem]=tcap[sj+j]; capsum[nitem]=capsum[sj+j]+(i==0?0:capsum[si+i-1]); gainsum[nitem]=gainsum[sj+j]+(i==0?0:gainsum[si+i-1]); ++nitem; ++cnt[x]; ++j;
			}
		}
	}
//	printf("%d=[%d..%d]\n",x,l,r); 
//	printf("tcap:"); REP(i,cnt[x]) printf(" %4d",tcap[fst[x]+i]); puts("");
//	printf("csum:"); REP(i,cnt[x]) printf(" %4lld",capsum[fst[x]+i]); puts("");
//	printf("gsum:"); REP(i,cnt[x]) printf(" %4lld",gainsum[fst[x]+i]); puts("");
}

ll go(int x,int l,int r,int t,int L,int R) {
	if(L<l) L=l; if (R>r) R=r; if(L>R) return 0;
//	printf("go(%d,%d,%d,%d,%d,%d) [%d]\n",x,l,r,t,L,R,last[x]);
	if(L==l&&R==r) {
		if(last[x]>=0) {
			ll ret=calc(x,t-last[x]);
			last[x]=t;
			return ret;
		} else if(l==r) {
			ll ret=calcstart(l,t);
			last[x]=t;
			return ret;
		} else {
			int m=l+(r-l)/2;
			ll ret=go(2*x+1,l,m,t,L,R)+go(2*x+2,m+1,r,t,L,R);
			last[x]=t;
			return ret;
		}
	} else {
		int m=l+(r-l)/2;
		if(last[x]!=-1) last[2*x+1]=last[2*x+2]=last[x],last[x]=-1;
		ll ret=go(2*x+1,l,m,t,L,R)+go(2*x+2,m+1,r,t,L,R);
		return ret;
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&start[i],&cap[i],&gain[i]);
	init(0,0,n-1);
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int t,l,r; scanf("%d%d%d",&t,&l,&r); --l,--r;
		ll cur=go(0,0,n-1,t,l,r);
		cout<<cur<<endl;
	}
}


int main() {
	run();
	return 0;
}