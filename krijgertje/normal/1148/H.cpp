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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXQ=200000;
const int MAXK=MAXQ;
const int MAXS=4*(MAXK+1);
struct Seg { int lx,hx,ly,hy; ll psum; Seg() {} Seg(int lx,int hx,int ly,int hy,ll psum):lx(lx),hx(hx),ly(ly),hy(hy),psum(psum) {} };

int nq;
int qval[MAXQ],ql[MAXQ],qr[MAXQ],qk[MAXQ]; ll qans[MAXQ];


int sval[MAXS];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=-1;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}
void sset(int x,int l,int r,int IDX,int VAL) {
	if(l==r) {
		sval[x]=VAL;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) sset(2*x+1,l,m,IDX,VAL); else sset(2*x+2,m+1,r,IDX,VAL);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}
int sgetlower(int x,int l,int r,int VAL) {
	assert(sval[x]<VAL);
	if(l==r) {
		return l;
	} else {
		int m=l+(r-l)/2;
		return sval[2*x+1]<VAL?sgetlower(2*x+1,l,m,VAL):sgetlower(2*x+2,m+1,r,VAL);
	}
}


int lst[MAXK+1];
vector<int> arr;
vector<Seg> seg[MAXK+1];

void addseg(int k,int lx,int hx,int ly,int hy) {
	//printf("\taddseg(%d,%d..%d,%d..%d)\n",k,lx,hx,ly,hy);
	assert(hy==INT_MAX);
	if(SZ(seg[k])==0) { seg[k].PB(Seg(lx,hx,ly,hy,0)); return; }
	Seg &lastseg=seg[k][SZ(seg[k])-1];
	if(lastseg.hy!=INT_MAX) {
		assert(ly>=lastseg.hy);
		ll nsum=lastseg.psum+(ll)(lastseg.hx-lastseg.lx)*(lastseg.hy-lastseg.ly);
		seg[k].PB(Seg(lx,hx,ly,hy,nsum));
	} else if(lastseg.ly!=ly) {
		assert(ly>lastseg.ly);
		assert(lastseg.hx==lx);
		lastseg.hy=ly; lx=lastseg.lx;
		ll nsum=lastseg.psum+(ll)(lastseg.hx-lastseg.lx)*(lastseg.hy-lastseg.ly);
		seg[k].PB(Seg(lx,hx,ly,hy,nsum));
	} else {
		if(lastseg.lx==hx) lastseg.lx=lx;
		else if(lastseg.hx==lx) lastseg.hx=hx;
		else assert(false);
	}
}

void append(int k) {
	//printf("append %d\n",k);
	int t=SZ(arr); arr.PB(k); lst[k]=t; sset(0,0,MAXK,k,t);
	if(SZ(seg[k])!=0&&seg[k][SZ(seg[k])-1].hy==INT_MAX) {
		Seg lastseg=seg[k][SZ(seg[k])-1];
		//printf("\tlastseg=%d..%d %d..%d\n",lastseg.lx,lastseg.hx,lastseg.ly,lastseg.hy);
		seg[k][SZ(seg[k])-1].hy=t;
		int x=lastseg.hx;
		while(x>lastseg.lx) {
			int kk=sgetlower(0,0,MAXK,x-1);
			int nx=max(lastseg.lx,lst[kk]+1);
			//printf("\tx=%d -> kk=%d -> nx=%d\n",x,kk,nx);
			assert(nx<x);
			addseg(kk,nx,x,t,INT_MAX);
			x=nx;
		}
	}
	addseg(k!=0?0:1,t,t+1,t,INT_MAX);
	//REPE(k,MAXK) if(SZ(seg[k])>1) { printf("\t%d:",k); REPSZ(i,seg[k]) if(seg[k][i].lx<seg[k][i].hx&&seg[k][i].ly<seg[k][i].hy) printf(" [%d..%d)*[%d..%d)=%lld",seg[k][i].lx,seg[k][i].hx,seg[k][i].ly,seg[k][i].hy,seg[k][i].psum); puts(""); }
}

ll calcstupid(int l,int r,int k) {
	ll ret=0;
	FORE(cl,l,r) FORE(cr,cl,r) {
		ll mask=0; FORE(i,cl,cr) mask|=1LL<<arr[i];
		int cur=0; while((mask&(1LL<<cur))!=0) ++cur; if(cur==k) ++ret;
	}
	//printf("calc(%d,%d,%d)=%lld\n",l,r,k,ret);
	return ret;
}

ll calc(int l,int r,int k) {
	//int a=0; while(a<SZ(seg[k])&&seg[k][a].hx<=l) ++a; // first seg with hx>l
	int a; { int lo=-1,hi=SZ(seg[k]); while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(seg[k][mi].hx>l) hi=mi; else lo=mi; } a=hi; }
	//int b=0; while(b<SZ(seg[k])&&seg[k][b].lx<l) ++b; // first seg with lx>=l
	int b; { int lo=-1,hi=SZ(seg[k]); while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(seg[k][mi].lx>=l) hi=mi; else lo=mi; } b=hi; }
	//int c=0; while(c<SZ(seg[k])&&seg[k][c].ly<=r) ++c; // first seg with ly>r
	int c; { int lo=-1,hi=SZ(seg[k]); while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(seg[k][mi].ly>r) hi=mi; else lo=mi; } c=hi; }
	b=min(b,c);
	// [0..a) contributes nothing
	// [a..b) contributes [l..hx)
	// [b..c) contributes [lx..hx)
	ll ret=0;
	if(a<c) {
		if(c-1>=0) {
			Seg s=seg[k][c-1];
			ret+=s.psum;
			ret+=(ll)(min(s.hy,r+1)-max(s.ly,l))*(s.hx-max(s.lx,l));
			b=min(b,c-1);
		}
		if(a<SZ(seg[k])) {
			Seg s=seg[k][a];
			ret-=s.psum;
		}
		if(a<b) {
			Seg sl=seg[k][a],sr=seg[k][b-1]; assert(sl.lx==sr.lx);
			ret-=(ll)(sr.hy-sl.ly)*(l-sl.lx);
		}
	}
	/*ll chk=calcstupid(l,r,k);
	if(ret!=chk) {
		printf("!");
		REPE(kk,MAXK) if(SZ(seg[kk])>0) { printf("\t%d:",kk); REPSZ(i,seg[kk]) printf(" [%d..%d]*[%d..%d]=%lld",seg[kk][i].lx,seg[kk][i].hx-1,seg[kk][i].ly,seg[kk][i].hy==INT_MAX?seg[kk][i].hy:seg[kk][i].hy-1,seg[kk][i].psum); puts(""); }
		printf("calc(%d,%d,%d): have=%lld want=%lld [a=%d,b=%d,c=%d]\n",l,r,k,ret,chk,a,b,c);
		exit(0);
	}*/
	return ret;
}

void solve() {
	//printf("SOLVING\n");
	arr.clear();
	REPE(k,MAXK) { lst[k]=-1; seg[k].clear(); }
	sinit(0,0,MAXK);
	ll lastans=0;
	REP(i,nq) {
		int val=(qval[i]+lastans)%(nq+1);
		int l=(ql[i]+lastans)%(i+1);
		int r=(qr[i]+lastans)%(i+1);
		if(l>r) swap(l,r);
		int k=(qk[i]+lastans)%(nq+1);
		append(val);
		lastans=qans[i]=calc(l,r,k);
	}
}

void run() {
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d%d%d",&qval[i],&ql[i],&qr[i],&qk[i]);
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

void stress() {
	REP(rep,10000) {
		nq=rand()%60+1;
		REP(i,nq) qval[i]=rand()%10,ql[i]=rand()%1000,qr[i]=rand()%1000,qk[i]=rand()%1000;
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}