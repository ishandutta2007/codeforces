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
const int MAXQ=100000;
const int MAXVAL=100000;
const int BSZ=400;
const int MAXLOW=1000;
typedef struct Q { int l,r,lb,id; } Q;
bool operator<(const Q &a,const Q &b) { if(a.lb!=b.lb) return a.lb<b.lb; return a.r<b.r; }

int n,nq;
int x[MAXN];
Q q[MAXQ];
ll ret[MAXQ];

int cnt[MAXVAL+1];
int freq[MAXN+1];
void mod(int idx,int by) {
	//printf("modding %d by %d\n",x[idx],by);
	--freq[cnt[x[idx]]];
	cnt[x[idx]]+=by;
	++freq[cnt[x[idx]]];
}
int a[MAXN],acnt[MAXN],na;
int b[MAXN],bcnt[MAXN],nb;
int c[MAXN],nc;
ll calc() {
	int sum=0; na=nb=0; FORE(i,1,MAXLOW) if(freq[i]>0) a[na]=i,acnt[na]=freq[i],++na,sum+=freq[i];
	int ta=na; REP(i,nc) if(cnt[c[i]]>MAXLOW) a[na]=cnt[c[i]],acnt[na]=1,++na,++sum; sort(a+ta,a+na);
	int ai=0,bi=0,cur=0; ll ret=0;
	//printf("calc(%d)\n",sum);
	while(sum>=2) {
		//printf("\tlft=%d %d<%d %d<%d (%d)\n",sum,ai,na,bi,nb,cur);
		int nxt,nxtcnt;
		if(bi>=nb||ai<na&&a[ai]<b[bi]) nxt=a[ai],nxtcnt=acnt[ai],++ai; else nxt=b[bi],nxtcnt=bcnt[bi],++bi;
		//printf("\t\t->%d %d\n",nxt,nxtcnt);
		if(cur!=0) b[nb]=cur+nxt,bcnt[nb]=1,++nb,ret+=cur+nxt,--nxtcnt,cur=0,--sum;
		if(nxtcnt>=2) b[nb]=2*nxt,bcnt[nb]=nxtcnt/2,ret+=(ll)2*bcnt[nb]*nxt,++nb,sum-=nxtcnt/2,nxtcnt%=2;
		if(nxtcnt>=1) cur=nxt;
	}
	//printf("=%d\n",ret);
	return ret;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&q[i].l,&q[i].r),--q[i].l,q[i].lb=q[i].l/BSZ,q[i].id=i;
	sort(q,q+nq);

	nc=0; memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[x[i]]; REPE(i,MAXVAL) if(cnt[i]>MAXLOW) c[nc++]=i;
	
	for(int at=0,to=at;at<nq;at=to) {
		while(to<nq&&q[at].lb==q[to].lb) ++to;
		memset(cnt,0,sizeof(cnt)); memset(freq,0,sizeof(freq));
		int l=q[at].l,r=q[at].l;
		FOR(i,at,to) {
			while(q[i].l<l) mod(--l,+1);
			while(q[i].r>r) mod(r++,+1);
			while(q[i].l>l) mod(l++,-1);
			while(q[i].r<r) mod(--r,-1);
			ret[q[i].id]=calc();
		}
	}
	REP(i,nq) printf("%lld\n",ret[i]);
}

int main() {
	run();
	return 0;
}