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

const int MAXN=100000;
const int MAXS=4*MAXN;
const int MAXBITS=20;
struct SVal { int orval; ll inside; int l,r; int pre[MAXBITS],suf[MAXBITS]; int npre,nsuf; };

int n,nq,want;
int v[MAXN];

SVal sval[MAXS];


SVal create(int idx) {
	SVal ret;
	ret.orval=v[idx]; ret.l=ret.r=idx;
	ret.npre=0; ret.pre[ret.npre++]=idx;
	ret.nsuf=0; ret.suf[ret.nsuf++]=idx;
	ret.inside=v[idx]<want?1:0;
	return ret;
}
SVal combine(const SVal &a,const SVal &b) {
	SVal ret;
	ret.orval=a.orval|b.orval; ret.l=a.l; ret.r=b.r;
	ret.npre=0; int preor=0;
	REP(i,a.npre) if(ret.npre==0||(preor|v[a.pre[i]])!=preor) ret.pre[ret.npre++]=a.pre[i],preor|=v[a.pre[i]];
	REP(i,b.npre) if(ret.npre==0||(preor|v[b.pre[i]])!=preor) ret.pre[ret.npre++]=b.pre[i],preor|=v[b.pre[i]];
	ret.nsuf=0; int sufor=0;
	REP(i,b.nsuf) if(ret.nsuf==0||(sufor|v[b.suf[i]])!=sufor) ret.suf[ret.nsuf++]=b.suf[i],sufor|=v[b.suf[i]];
	REP(i,a.nsuf) if(ret.nsuf==0||(sufor|v[a.suf[i]])!=sufor) ret.suf[ret.nsuf++]=a.suf[i],sufor|=v[a.suf[i]];
	ret.inside=a.inside+b.inside;
	int lst[MAXBITS],nlst=b.npre; REP(i,nlst) lst[i]=v[b.pre[i]]; REP(i,nlst-1) lst[i+1]|=lst[i];
	int at=nlst-1,curor=0;
	REP(i,a.nsuf) {
		curor|=v[a.suf[i]];
		while(at>=0&&(curor|lst[at])>=want) --at;
		if(at>=0) {
			//printf("+%d*%d [%d,%d -> %d,%d -> %d|%d=%d]\n",a.suf[i]-(i==a.nsuf-1?a.l:a.suf[i+1]-1)+1,(at==nlst-1?b.r:b.pre[at+1]-1)-b.l+1,i,at,a.suf[i],b.pre[at],curor,lst[at],curor|lst[at]);
			ret.inside+=(ll)(a.suf[i]-(i==a.nsuf-1?a.l:a.suf[i+1]+1)+1)*((at==nlst-1?b.r:b.pre[at+1]-1)-b.l+1);
		}
	}
	assert(ret.npre>=1&&ret.pre[0]==ret.l&&ret.nsuf>=1&&ret.suf[0]==ret.r);
	return ret;
}

void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=create(l);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		sval[x]=combine(sval[2*x+1],sval[2*x+2]);
	}
	//printf("%d..%d=%lld\n",l,r,sval[x].inside);
}
void supd(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=create(l);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) supd(2*x+1,l,m,IDX);
		if(IDX>=m+1) supd(2*x+2,m+1,r,IDX);
		sval[x]=combine(sval[2*x+1],sval[2*x+2]);
	}
}
SVal sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2;
		if(R<=m) return sget(2*x+1,l,m,L,R);
		if(L>=m+1) return sget(2*x+2,m+1,r,L,R);
		return combine(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
	}
}



void run() {
	scanf("%d%d%d",&n,&nq,&want);
	REP(i,n) scanf("%d",&v[i]);

	sinit(0,0,n-1);
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int idx,nval; scanf("%d%d",&idx,&nval); --idx;
			v[idx]=nval; supd(0,0,n-1,idx);
		}
		if(kind==2) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			SVal cur=sget(0,0,n-1,l,r);
			int len=r-l+1; ll ans=(ll)len*(len+1)/2-cur.inside;
			printf("%lld\n",ans);
		}
	}

}

int main() {
	run();
	return 0;
}