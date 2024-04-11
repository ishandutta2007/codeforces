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
#include <random>
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
const int MOD=1000000007;
typedef struct S {
	ll ways123,ways12,ways23,ways1,ways2,ways3;
} S;

int n;
int a[MAXN];
int b[MAXN];
int bb[MAXN];
int c[MAXN];
int v[MAXN];
int off[MAXN+1],nr;
int cur[MAXN];

int before[MAXN],after[MAXN];
int bit[MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void binc(int idx) { ++idx; while(idx<=n) { ++bit[idx]; idx+=idx&-idx; } }

S sval[4*MAXN];
void scalc(S &res,const S &l,const S &r) {
	res.ways123=l.ways123+l.ways12*r.ways3+l.ways1*r.ways23+r.ways123;
	res.ways12=l.ways12+l.ways1*r.ways2+r.ways12;
	res.ways23=l.ways23+l.ways2*r.ways3+r.ways23;
	res.ways1=l.ways1+r.ways1;
	res.ways2=l.ways2+r.ways2;
	res.ways3=l.ways3+r.ways3;
	res.ways123%=MOD; res.ways12%=MOD; res.ways23%=MOD; res.ways1%=MOD; res.ways2%=MOD; res.ways3%=MOD;
}
void sinit(int x,int l,int r) {
	if(l==r) {
		int idx=b[l];
		S &res=sval[x]; res.ways123=res.ways12=res.ways23=0; res.ways1=before[idx],res.ways2=1,res.ways3=after[idx];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r); scalc(sval[x],sval[2*x+1],sval[2*x+2]);
	}
}
S sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return sval[x];
	int m=l+(r-l)/2;
	if(R<=m) return sget(2*x+1,l,m,L,R);
	if(m+1<=L) return sget(2*x+2,m+1,r,L,R);
	S ret; scalc(ret,sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R)); return ret;
}
void smod(int x,int l,int r,int IDX,bool ON) {
	if(l==r) {
		S &res=sval[x]; int idx=b[IDX];
		if(ON) { res.ways123=res.ways12=res.ways23=0; res.ways1=before[idx],res.ways2=1,res.ways3=after[idx]; }
		else { res.ways123=res.ways12=res.ways23=0; res.ways1=0,res.ways2=0,res.ways3=0; }
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*x+1,l,m,IDX,ON); else smod(2*x+2,m+1,r,IDX,ON);
		scalc(sval[x],sval[2*x+1],sval[2*x+2]);
	}
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	vector<pair<int,int> > o; REP(i,n) o.PB(MP(a[i],i)); sort(o.begin(),o.end());
	REP(i,2) {
		memset(bit,0,sizeof(bit));
		for(int at=0,to=at;at<n;at=to) {
			while(to<n&&o[at].first==o[to].first) ++to;
			FOR(j,at,to) { int idx=o[j].second; binc(i==0?idx:n-idx-1); }
			FOR(j,at,to) { int idx=o[j].second; (i==0?before:after)[idx]=bget(i==0?idx:n-idx-1)-1; }
		}
	}
	//REP(i,n) printf("%d: before=%d after=%d\n",i,before[i],after[i]);
	nr=0; off[0]=0;
	for(int at=0,to=at;at<n;at=to) {
		while(to<n&&o[at].first==o[to].first) ++to;
		REP(j,to-at) b[off[nr]+j]=o[at+j].second,c[off[nr]+j]=nr;
		v[nr]=o[at].first,off[nr+1]=off[nr]+to-at; ++nr;
	}
	REP(i,n) bb[b[i]]=i;
	//REP(i,n) printf("%d ",b[i]); puts("");
	sinit(0,0,n-1);
	ll cursum=0;
	REP(i,nr) cur[i]=sget(0,0,n-1,off[i],off[i+1]-1).ways123,cursum+=cur[i];
	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int type,x; scanf("%d%d",&type,&x); --x; x=bb[x]; int cr=c[x];
		cursum-=cur[cr];
		smod(0,0,n-1,x,type==2);
		cur[cr]=sget(0,0,n-1,off[cr],off[cr+1]-1).ways123;
		cursum+=cur[cr];
		printf("%d\n",cursum%MOD);
	}
}

int main() {
	run();
	return 0;
}