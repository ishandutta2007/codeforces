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

const int MAXQ=200000;
const int MAXN=MAXQ+1;
const int MAXSEG=1<<19;
const int MOD=1000000007;

int sval[MAXSEG];
int smult[MAXSEG];
void push(int x) {
	if(sval[x]==0) return;
	if((sval[2*x+2]+=sval[x])>=MOD) sval[2*x+2]-=MOD;
	sval[x]=(ll)sval[x]*smult[2*x+2]%MOD;
	if((sval[2*x+1]+=sval[x])>=MOD) sval[2*x+1]-=MOD;
	sval[x]=0;
}
void calc(int x) {
	smult[x]=(ll)smult[2*x+1]*smult[2*x+2]%MOD;
}
void incval(int x,int l,int h,int L,int H,int &BY) {
	if(L<=l&&h<=H) {
		if((sval[x]+=BY)>=MOD) sval[x]-=MOD;
		BY=(ll)BY*smult[x]%MOD;
	} else {
		int m=l+(h-l)/2;
		if(m+1<=H) incval(2*x+2,m+1,h,L,H,BY);
		if(L<=m) incval(2*x+1,l,m,L,H,BY);
	}
}
void setmult(int x,int l,int h,int IDX,int MULT) {
	if(l==h) {
		smult[x]=MULT;
	} else {
		push(x);
		int m=l+(h-l)/2;
		if(IDX<=m) setmult(2*x+1,l,m,IDX,MULT); else setmult(2*x+2,m+1,h,IDX,MULT);
		calc(x);
	}
}
int getval(int x,int l,int h,int IDX) {
	if(l==h) {
		return sval[x];
	} else {
		push(x);
		int m=l+(h-l)/2;
		return IDX<=m?getval(2*x+1,l,m,IDX):getval(2*x+2,m+1,h,IDX);
	}
}
void printtree(int x,int l,int h,int d) {
	REP(i,d) printf("  "); printf("%d:%d..%d val=%d mult=%d\n",x,l,h,sval[x],smult[x]);
	if(l!=h) {
		int m=l+(h-l)/2;
		printtree(2*x+1,l,m,d+1); printtree(2*x+2,m+1,h,d+1);
	}
}


int v[MAXN],n,nq;
int qtype[MAXQ],qidx[MAXQ];

int head[MAXN],nxt[MAXN],par[MAXN];
int sz[MAXN],heavy[MAXN],root[MAXN];
int sidx[MAXN],ns;
int mult[MAXN];

void run() {
	n=1; scanf("%d%d",&v[0],&nq); head[0]=nxt[0]=par[0]=-1;
	REP(i,nq) {
		scanf("%d",&qtype[i]);
		if(qtype[i]==1) {
			scanf("%d",&par[n]),--par[n];
			scanf("%d",&v[n]); head[n]=-1; nxt[n]=head[par[n]]; head[par[n]]=n; qidx[i]=n++;
		}
		if(qtype[i]==2) scanf("%d",&qidx[i]),--qidx[i];
	}
	REP(i,n) sz[i]=1; for(int i=n-1;i>=1;--i) sz[par[i]]+=sz[i];
	REP(i,n) heavy[i]=head[i]; REP(i,n) for(int x=head[i];x!=-1;x=nxt[x]) if(sz[x]>sz[heavy[i]]) heavy[i]=x;
	REP(i,n) root[i]=par[i]==-1||heavy[par[i]]!=i?i:root[par[i]];
	ns=0; REP(i,n) if(root[i]==i) for(int j=i;j!=-1;j=heavy[j]) sidx[j]=ns++;
	//REP(i,n) printf("%d: par=%d, sz=%d, heavy=%d, root=%d, sidx=%d\n",i,par[i],sz[i],heavy[i],root[i],sidx[i]);

	memset(sval,0,sizeof(sval));
	memset(smult,0,sizeof(smult));
	memset(mult,0,sizeof(mult));
	setmult(0,0,ns-1,sidx[0],1); mult[0]=1;
	incval(0,0,ns-1,sidx[0],sidx[0],v[0]);
	REP(i,nq) {
		int idx=qidx[i];
		if(qtype[i]==1) {
			setmult(0,0,ns-1,sidx[idx],1); mult[idx]=1;
			int by=v[idx];
			for(int at=idx;at!=-1;at=par[root[at]]) {
				//printf("A%d: %d..%d (%d)\n",i,root[at],at,by);
				incval(0,0,ns-1,sidx[root[at]],sidx[at],by);
			}
			setmult(0,0,ns-1,sidx[par[idx]],mult[par[idx]]+1); mult[par[idx]]++;
			if(par[par[idx]]!=-1) {
				by=getval(0,0,ns-1,sidx[par[idx]]);
				for(int at=par[par[idx]];at!=-1;at=par[root[at]]) {
					//printf("B%d: %d..%d (%d)\n",i,root[at],at,by);
					incval(0,0,ns-1,sidx[root[at]],sidx[at],by);
				}
			}
		}
		if(qtype[i]==2) {
			int sum=getval(0,0,ns-1,sidx[idx]);
			int ret=(ll)sum*mult[idx]%MOD;
			printf("%d\n",ret);
		}
	}
}

int main() {
	run();
	return 0;
}