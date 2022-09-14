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

const int N=1<<20;
int ldelta[N],rdelta[N];
ll sum[N],lsum[N],rsum[N],lrsum[N];
bool debug=false;

vector<int> allx;
vector<int> nleft,nrght;

void init(int x,int l,int r) {
	ldelta[x]=rdelta[x]=0;
	if(l==r) {
		sum[x]=allx[l+1]-allx[l];
		lsum[x]=nleft[l]*sum[x];
		rsum[x]=nrght[l]*sum[x];
		lrsum[x]=(ll)nleft[l]*nrght[l]*sum[x];
	} else {
		int n=r-l+1,nn=(n+1)/2;
		init(2*x+1,l,l+nn-1);
		init(2*x+2,l+nn,r);
		sum[x]=sum[2*x+1]+sum[2*x+2];
		lsum[x]=lsum[2*x+1]+lsum[2*x+2];
		rsum[x]=rsum[2*x+1]+rsum[2*x+2];
		lrsum[x]=lrsum[2*x+1]+lrsum[2*x+2];
	}
}

inline void propagate(int x,int l,int r) {
	if(ldelta[x]==0&&rdelta[x]==0) return;
	//printf("\t\tpropagating %d..%d (%d,%d)\n",allx[l],allx[r+1],ldelta[x],rdelta[x]);
	lrsum[x]+=ldelta[x]*rsum[x]+rdelta[x]*lsum[x]+(ll)ldelta[x]*rdelta[x]*sum[x];
	lsum[x]+=ldelta[x]*sum[x]; rsum[x]+=rdelta[x]*sum[x];
	ldelta[2*x+1]+=ldelta[x]; ldelta[2*x+2]+=ldelta[x]; ldelta[x]=0;
	rdelta[2*x+1]+=rdelta[x]; rdelta[2*x+2]+=rdelta[x]; rdelta[x]=0;
}

ll getlr(int x,int l,int r,int L,int R) {
	if(L<l) L=l; if(R>r) R=r; if(L>R) return 0;
	if(L==l&&R==r) {
		return lrsum[x]+ldelta[x]*rsum[x]+rdelta[x]*lsum[x]+(ll)ldelta[x]*rdelta[x]*sum[x];
	} else {
		propagate(x,l,r);
		int n=r-l+1,nn=(n+1)/2;
		ll a=getlr(2*x+1,l,l+nn-1,L,R);
		ll b=getlr(2*x+2,l+nn,r,L,R);
		return a+b;
	}
}

ll getl(int x,int l,int r,int L,int R) {
	if(L<l) L=l; if(R>r) R=r; if(L>R) return 0;
	if(L==l&&R==r) {
		//if(debug) printf("\tgetl: %d..%d -> %lld\n",allx[l],allx[r+1],lsum[x]+ldelta[x]*sum[x]);
		return lsum[x]+ldelta[x]*sum[x];
	} else {
		propagate(x,l,r);
		int n=r-l+1,nn=(n+1)/2;
		ll a=getl(2*x+1,l,l+nn-1,L,R);
		ll b=getl(2*x+2,l+nn,r,L,R);
		return a+b;
	}
}

ll getr(int x,int l,int r,int L,int R) {
	if(L<l) L=l; if(R>r) R=r; if(L>R) return 0;
	if(L==l&&R==r) {
		return rsum[x]+rdelta[x]*sum[x];
	} else {
		propagate(x,l,r);
		int n=r-l+1,nn=(n+1)/2;
		ll a=getr(2*x+1,l,l+nn-1,L,R);
		ll b=getr(2*x+2,l+nn,r,L,R);
		return a+b;
	}
}

ll get(int x,int l,int r,int L,int R) {
	if(L<l) L=l; if(R>r) R=r; if(L>R) return 0;
	if(L==l&&R==r) {
		return sum[x];
	} else {
		propagate(x,l,r);
		int n=r-l+1,nn=(n+1)/2;
		ll a=get(2*x+1,l,l+nn-1,L,R);
		ll b=get(2*x+2,l+nn,r,L,R);
		return a+b;
	}
}

void update(int x,int l,int r,int at,int by) {
	if(r<at) {
		rdelta[x]+=by;
	} else if(l>=at) {
		ldelta[x]+=by;
	} else {
		int n=r-l+1,nn=(n+1)/2;
		propagate(x,l,r);
		update(2*x+1,l,l+nn-1,at,by);
		update(2*x+2,l+nn,r,at,by);
		bool olddebug=debug; debug=false;
		sum[x]=get(2*x+1,l,l+nn-1,l,l+nn-1)+get(2*x+2,l+nn,r,l+nn,r);
		lsum[x]=getl(2*x+1,l,l+nn-1,l,l+nn-1)+getl(2*x+2,l+nn,r,l+nn,r);
		rsum[x]=getr(2*x+1,l,l+nn-1,l,l+nn-1)+getr(2*x+2,l+nn,r,l+nn,r);
		lrsum[x]=getlr(2*x+1,l,l+nn-1,l,l+nn-1)+getlr(2*x+2,l+nn,r,l+nn,r);
		debug=olddebug;
	}
}

int treesum[N+1];
int gettree(int x) { int ret=0; while(x>0) { ret+=treesum[x]; x-=x&-x; } return ret; }
void updatetree(int x,int by) { while(x<N) { treesum[x]+=by; x+=x&-x; } }

void run(int casenr) {
	int n; scanf("%d",&n);
	vector<int> x(n); REP(i,n) scanf("%d",&x[i]);
	int nq; scanf("%d",&nq);
	vector<int> qt(nq),qa(nq),qb(nq); REP(i,nq) scanf("%d%d%d",&qt[i],&qa[i],&qb[i]);
/*	REP(q,nq) {
		if(qt[q]==1) {
			x[qa[q]-1]+=qb[q];
		} else {
			vector<int> y; REP(i,n) if(x[i]>=qa[q]&&x[i]<=qb[q]) y.PB(x[i]); sort(y.begin(),y.end());
			ll cur=0; FORSZ(i,1,y) cur+=i*(SZ(y)-i)*(y[i]-y[i-1]); cout<<cur<<endl;
		}
	} */
	
	allx=x;
	REP(q,nq) if(qt[q]==1) { x[qa[q]-1]+=qb[q]; allx.PB(x[qa[q]-1]); }
	REP(q,nq) if(qt[q]==1) x[qa[q]-1]-=qb[q];
	REP(q,nq) if(qt[q]==2) { allx.PB(qa[q]); allx.PB(qb[q]); }
	sort(allx.begin(),allx.end()); allx.erase(unique(allx.begin(),allx.end()),allx.end());
	map<int,int> x2xid; REPSZ(i,allx) x2xid[allx[i]]=i;
	int m=SZ(allx)-1;
	
	nleft=nrght=vector<int>(m,0);
	REP(i,n) { int id=x2xid[x[i]]; if(id<m) ++nleft[id]; updatetree(id+1,+1); }
	FOR(i,1,m) nleft[i]+=nleft[i-1];
	REP(i,m) nrght[i]=n-nleft[i];
	
//	REP(i,m) printf("%d: %d..%d [%d,%d]\n",i,allx[i],allx[i+1],nleft[i],nrght[i]);
	
	init(0,0,m-1);
	REP(q,nq) {
		if(qt[q]==1) {
			int i=qa[q]-1;
			update(0,0,m-1,x2xid[x[i]],-1);
			updatetree(x2xid[x[i]]+1,-1);
			x[i]+=qb[q];
			updatetree(x2xid[x[i]]+1,+1);
			update(0,0,m-1,x2xid[x[i]],+1);
		} else {
			int i=x2xid[qa[q]],j=x2xid[qb[q]]-1;
			int curleft=i==0?0:gettree(i+1-1);
			int currght=n-gettree(j+1+1);
//			REP(j,n) if(x[j]<qa[q]) ++curleft; else if(x[j]>qb[q]) ++currght;
			debug=q==5;
			ll cur=get(0,0,m-1,i,j);
			ll curl=getl(0,0,m-1,i,j);
			ll curr=getr(0,0,m-1,i,j);
			ll curlr=getlr(0,0,m-1,i,j);
			ll now=0;
			now+=curlr;
			now-=(curl-curleft*cur)*currght;
			now-=(curr-currght*cur)*curleft;
			now-=cur*curleft*currght;
//			printf("\t[%d..%d]: %lld %lld %lld %lld [%d,%d]-> %lld\n",i,j,cur,curl,curr,curlr,curleft,currght,now);
			cout<<now<<endl;		
		}
	}
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}