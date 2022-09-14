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

const int MAXN=200000;

typedef struct R {
	int len; ll sum;
	ll mnoddpref,mnoddsuff;
	ll mxevnpref,mxevnsuff;
} R;

R merge(const R &a,const R &b) {
	if(a.len==0) return b; else if(b.len==0) return a;
	R c;
	c.len=a.len+b.len;
	c.sum=a.len%2==0?a.sum+b.sum:a.sum-b.sum;
	c.mnoddpref=min(a.mnoddpref,a.len%2==0?a.sum+b.mnoddpref:a.sum-b.mxevnpref);
	c.mxevnpref=max(a.mxevnpref,a.len%2==0?a.sum+b.mxevnpref:a.sum-b.mnoddpref);
	c.mnoddsuff=min(b.mnoddsuff,b.len%2==0?(b.len%2==0?-b.sum:b.sum)+a.mnoddsuff:(b.len%2==0?-b.sum:b.sum)-a.mxevnsuff);
	c.mxevnsuff=max(b.mxevnsuff,b.len%2==0?(b.len%2==0?-b.sum:b.sum)+a.mxevnsuff:(b.len%2==0?-b.sum:b.sum)-a.mnoddsuff);
	//printf("(%d,%lld:%lld,%lld:%lld,%lld)+(%d,%lld:%lld,%lld:%lld,%lld)=(%d,%lld:%lld,%lld:%lld,%lld)\n",a.len,a.sum,a.mnoddpref,a.mxevnpref,a.mnoddsuff,a.mxevnsuff,b.len,b.sum,b.mnoddpref,b.mxevnpref,b.mnoddsuff,b.mxevnsuff,c.len,c.sum,c.mnoddpref,c.mxevnpref,c.mnoddsuff,c.mxevnsuff);
	return c;
}

int n,nq;
int a[MAXN];
R seg[2*MAXN]; int slazy[2*MAXN];
void sinit() {
	REP(i,n) { int idx=n+i; seg[idx].len=1,seg[idx].sum=a[i],seg[idx].mnoddpref=a[i],seg[idx].mnoddsuff=a[i],seg[idx].mxevnpref=0,seg[idx].mxevnsuff=0; }
	for(int idx=n-1;idx>=1;--idx) seg[idx]=merge(seg[idx<<1],seg[idx<<1|1]);
	memset(slazy,0,sizeof(slazy));
}
void smod(int idx,int by) {
	//printf("smod(%d,%d)\n",idx,by);
	R &a=seg[idx];
	if(a.len%2==1) a.sum+=by;
	a.mnoddpref+=by; a.mnoddsuff+=by;
	slazy[idx]+=by;
}
void _spush(int idx) {
	if(slazy[idx]==0) return;
	smod(idx<<1,slazy[idx]); smod(idx<<1|1,slazy[idx]); slazy[idx]=0;
}
void spush(int idx) { int h=0; while(idx>>h) ++h; for(--h;h>0;--h) _spush(idx>>h); }
void sbuild(int idx) { for(idx>>=1;idx;idx>>=1) { _spush(idx); seg[idx]=merge(seg[idx<<1],seg[idx<<1|1]); } }
void sinc(int l,int r,int by) {
	int lidx=l+n,ridx=r+n+1;
	for(;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) smod(lidx++,by);
		if(ridx&1) smod(--ridx,by);
	}
	sbuild(l+n),sbuild(r+n);
}
R sget(int l,int r) {
	int lidx=l+n,ridx=r+n+1;
	spush(lidx),spush(ridx-1);
	R lret; lret.len=0,lret.sum=0,lret.mnoddpref=lret.mnoddpref=LLONG_MAX,lret.mxevnpref=lret.mxevnsuff=LLONG_MIN;
	R rret; rret.len=0,rret.sum=0,rret.mnoddpref=rret.mnoddpref=LLONG_MAX,rret.mxevnpref=rret.mxevnsuff=LLONG_MIN;
	for(;lidx<ridx;lidx>>=1,ridx>>=1) {
		if(lidx&1) lret=merge(lret,seg[lidx++]);
		if(ridx&1) rret=merge(seg[--ridx],rret);
	}
	return merge(lret,rret);
}

// alternating prefix sum of odd length >=1
// alternating prefix sum of evn length <=0
// alternating sum = 0 (evn length) or 1 (odd length)
bool ok(const R &a) {
	bool ok1=a.mnoddpref>=1&&a.mxevnpref<=0&&a.sum==a.len%2;
	bool ok2=a.mnoddsuff>=1&&a.mxevnsuff<=0&&a.sum==a.len%2;
	if(ok1!=ok2) printf("tst len=%d, sum=%lld, mnop=%lld, mxep=%lld, mnos=%lld, mxes=%lld -> %d%d\n",a.len,a.sum,a.mnoddpref,a.mxevnpref,a.mnoddsuff,a.mxevnsuff,ok1?1:0,ok2?1:0);
	return ok1||ok2;
}

void chk() {
	int l=2,r=99;
	int sum=0; ll mnodd=LLONG_MAX,mxevn=0; FORE(i,l,r) sum+=(i-l)%2==0?+a[i]:-a[i],mnodd=min(mnodd,(i-l)%2==0?sum:mnodd),mxevn=max(mxevn,(i-l)%2==1?sum:mxevn);
	R res=sget(l,r); printf("%lld %lld vs %lld %lld\n",res.mnoddpref,res.mxevnpref,mnodd,mxevn);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	sinit();
	scanf("%d",&nq);
	REP(qi,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int l,r,k; scanf("%d%d%d",&l,&r,&k);
			sinc(l,r,k);
//			FORE(i,l,r) a[i]+=k;
		}
		if(type==2) {
			int l,r; scanf("%d%d",&l,&r);
			R res=sget(l,r);
			printf("%d\n",ok(res)?1:0);
		}
		//chk();
	}
}

int main() {
	run();
	return 0;
}