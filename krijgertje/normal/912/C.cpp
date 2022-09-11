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

typedef struct E { 
	ll t; int idx; ll val;
	E(ll t,int idx,ll val):t(t),idx(idx),val(val) {}
} E;
bool operator<(const E &a,const E &b) { if(a.t!=b.t) return a.t>b.t; return a.val>b.val; } // reversed for pq

int n,nq;
int a,b,damage; // a+b*t

int mx[MAXN],init[MAXN],gain[MAXN];



ll pt[MAXN],pval[MAXN],pmark[MAXN];
priority_queue<E> pq;


void run() {
	scanf("%d%d",&n,&nq); scanf("%d%d%d",&a,&b,&damage); REP(i,n) scanf("%d%d%d",&mx[i],&init[i],&gain[i]);
	pq=priority_queue<E>(); REP(i,nq) { int t,idx,val; scanf("%d%d%d",&t,&idx,&val); --idx; pq.push(E(t,idx,val)); }
	
	int cnt=0;
	REP(i,n) pt[i]=0,pval[i]=init[i],pmark[i]=-1;
	REP(i,n) if(pval[i]<=damage) ++cnt;
	REP(i,n) if(gain[i]!=0&&pval[i]<=damage&&mx[i]>damage) pq.push(E(pt[i]+(damage-pval[i])/gain[i]+1,i,pmark[i]));
	ll tt=0,ret=0;
	while(!pq.empty()) {
		E e=pq.top(); pq.pop(); ll t=e.t; int idx=e.idx; ll val=e.val;
		if(val<0&&pmark[idx]!=val) continue;
		//printf("%lld: idx=%d val=%lld [pt=%lld,pval=%lld->%lld/%lld]\n",t,idx,val,pt[idx],pval[idx],min((ll)mx[idx],pval[idx]+(t-pt[idx]-1)*gain[idx]),min((ll)mx[idx],pval[idx]+(t-pt[idx])*gain[idx]));
		if(t!=tt) {
			ret=max(ret,cnt*(a+b*(t-1)));
			tt=t;
		}
		if(val<0) {
			assert(pval[idx]+(t-pt[idx]-1)*gain[idx]<=damage);
			pval[idx]=min((ll)mx[idx],pval[idx]+(t-pt[idx])*gain[idx]);
			pt[idx]=t;
			assert(pval[idx]>damage);
			--cnt;
		} else {
			assert(pval[idx]<=damage&&min((ll)mx[idx],pval[idx]+(t-pt[idx])*gain[idx])<=damage||pval[idx]>damage&&min((ll)mx[idx],pval[idx]+(t-pt[idx])*gain[idx])>damage);
			if(pval[idx]<=damage) --cnt;
			--pmark[idx];
			pval[idx]=val;
			pt[idx]=t;
			if(pval[idx]<=damage) ++cnt;
			if(gain[idx]!=0&&pval[idx]<=damage&&mx[idx]>damage) pq.push(E(pt[idx]+(damage-pval[idx])/gain[idx]+1,idx,pmark[idx]));
		}
	}
	if(cnt>0&&b!=0) { printf("-1\n"); return; }
	if(cnt>0&&b==0) ret=max(ret,(ll)cnt*a);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}