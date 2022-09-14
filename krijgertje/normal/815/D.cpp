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

const int MAXN=500000;
const int MAXS=4*MAXN;
typedef struct P { int a,b,c,id; } P;
bool operator<(const P &u,const P &v) { return u.c<v.c; }

int n;
int amx,bmx,cmx;
P p[MAXN];

priority_queue<pair<int,int> > aq;
priority_queue<pair<int,int> > bq;


ll ssum[MAXS]; int smn[MAXS],smx[MAXS]; int sval[MAXS];
void sapply(int x,int l,int r,int VAL) {
	smn[x]=smx[x]=VAL;
	sval[x]=VAL;
	ssum[x]=(ll)(r-l+1)*VAL;
}
void spush(int x,int l,int m,int r) {
	if(sval[x]==0) return;
	sapply(2*x+1,l,m,sval[x]);
	sapply(2*x+2,m+1,r,sval[x]);
	sval[x]=0;
}
void scalc(int x) {
	smn[x]=min(smn[2*x+1],smn[2*x+2]);
	smx[x]=max(smx[2*x+1],smx[2*x+2]);
	ssum[x]=ssum[2*x+1]+ssum[2*x+2];
}
void sinit(int x,int l,int r) {
	sval[x]=0;
	if(l==r) {
		smn[x]=smx[x]=ssum[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		scalc(x);
	}
}
void sset(int x,int l,int r,int IDX,int VAL) {
	if(smn[x]>=VAL) return;
	if(smx[x]<=VAL&&IDX>=r) {
		sapply(x,l,r,VAL);
	} else {
		int m=l+(r-l)/2;
		spush(x,l,m,r);
		sset(2*x+1,l,m,IDX,VAL);
		if(IDX>=m+1) sset(2*x+2,m+1,r,IDX,VAL);
		scalc(x);
	}
}
ll sget(int x,int l,int r,int IDX,int VAL) {
	//printf("sget(%d,%d,%d,%d,%d)\n",x,l,r,IDX,VAL);
	if(smx[x]<VAL||IDX>r) return 0;
	if(smn[x]>=VAL&&IDX<=l) return ssum[x]-(ll)(r-l+1)*(VAL-1);
	int m=l+(r-l)/2;
	spush(x,l,m,r);
	ll ret=sget(2*x+1,l,m,IDX,VAL)+sget(2*x+2,m+1,r,IDX,VAL);
	scalc(x);
	return ret;
}


void run() {
	scanf("%d%d%d%d",&n,&amx,&bmx,&cmx); REP(i,n) scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c),p[i].id=i;
	sort(p,p+n);
	sinit(0,1,amx);
	aq=bq=priority_queue<pair<int,int> >(); REP(i,n) aq.push(MP(p[i].a,i)); REP(i,n) bq.push(MP(p[i].b,i));
	int at=0;
	ll ret=0;
	FORE(c,1,cmx) {
		while(at<n&&p[at].c<c) {
			//printf("c=%d: inserting (%d,%d)\n",c,p[at].a,p[at].b);
			sset(0,1,amx,p[at].a,p[at].b);
			++at;
		}
		while(SZ(aq)>0&&p[aq.top().second].c<c) aq.pop();
		while(SZ(bq)>0&&p[bq.top().second].c<c) bq.pop();
		int amn,bmn;
		if(SZ(aq)==0&&SZ(bq)==0) {
			amn=1,bmn=1;
		} else {
			assert(SZ(aq)>0&&SZ(bq)>0);
			amn=aq.top().first+1,bmn=bq.top().first+1;
		}
		if(amn>amx) {
			//printf("c=%d: amn=%d bmn=%d\n",c,amn,bmn);
		} else {
			ll blocked=sget(0,1,amx,amn,bmn);
			ll cur=(ll)(amx-amn+1)*(bmx-bmn+1)-blocked;
			//printf("c=%d: amn=%d bmn=%d -> %lld -> %lld\n",c,amn,bmn,blocked,cur);
			ret+=cur;
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}