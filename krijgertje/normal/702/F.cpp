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
const int MAXG=30;
const int MAXQ=200000;
typedef struct T { int p,v,pos,g; } T;
bool vcmp(const T &a,const T &b) { if(a.v!=b.v) return a.v>b.v; return a.p<b.p; }
bool gcmp(const T &a,const T &b) { if(a.g!=b.g) return a.g<b.g; return a.pos<b.pos; }

int n,nq;
T t[MAXN];
int q[MAXQ];
int ret[MAXQ];

// x coins in [2a,4a), next shirt to consider at position i -> either:
// * buy upto including first shirt z with p[z]>=2a for which the cumulative sum of prices of shirts costing [1..2a) in i..idx[z] + p[z] <=x
// * buy no more shirts in [2a,4a) -> buy upto excluding first shirt z with p[z]<2a for which the cumulative sum of prices of shirts costing [0..2a) in i..idx[z] > x

// x coins considering only shirts in range [1..4a) from position i onwards:
// * buy upto including last shirt z with pos[z]>=i costing [2a..4a) for which the cumulative sum of prices of shirts costing [1..4a) in i..pos[z]<=x  -> can buy at most one shirt from [2a..4a) afterwards
// * but upto including first shirt z with pos[z]>=i costing [2a..4a) for which p[z]+the cumulative sum of prices of shirts costing [1..2a) in i..pos[z]<=x -> can buy no more shirts from [2a..4a) afterwards

ll sum1[MAXN]; int cnt1[MAXN];
ll sum2[MAXN]; int cnt2[MAXN];

int off[MAXG+1];
int at[MAXG];

ll smin[4*MAXN];
void sinit(int x,int l,int r) {
	if(l==r) { smin[x]=sum2[l]; return;	}
	int m=l+(r-l)/2;
	sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
	smin[x]=min(smin[2*x+1],smin[2*x+2]);
}

int sfind(int x,int l,int r,int L,int R,ll VAL) {
	if(R<l||L>r||L<=l&&r<=R&&smin[x]>VAL) return -1;
	if(l==r) return l;
	// l..m, m+1..r
	int m=l+(r-l)/2;
	int a=sfind(2*x+1,l,m,L,R,VAL);
	if(a!=-1) return a;
	int b=sfind(2*x+2,m+1,r,L,R,VAL);
	return b;
}

int find1(int l,int r,ll val) {
	--l; while(l+1<r) { int m=l+(r-l)/2; if(sum1[m]<=val) l=m; else r=m; } return l;
}
int find2(int l,int r,ll val) {
	--r; return sfind(0,0,n-1,l,r,val);
}
int find3(int l,int r,int pos) {
	--l; while(l+1<r) { int m=l+(r-l)/2; if(t[m].pos<pos) l=m; else r=m; } return l;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&t[i].p,&t[i].v);
	scanf("%d",&nq);
	REP(i,nq) scanf("%d",&q[i]);

	sort(t,t+n,vcmp);
	REP(i,n) { t[i].pos=i,t[i].g=0; while((1LL<<(t[i].g+1))<=t[i].p) ++t[i].g; }
	sort(t,t+n,gcmp);
	off[0]=0; REP(i,MAXG) { off[i+1]=off[i]; while(off[i+1]<n&&t[off[i+1]].g==i) ++off[i+1]; }
	//REP(i,n) printf("%d: at %d get %d costs %d\n",i,t[i].pos,t[i].v,t[i].p);

	REP(i,MAXG) {
		ll cur1=0,cur2=0; int x1=0,x2=0;
		REP(ii,i) at[ii]=off[ii];
		FOR(j,off[i],off[i+1]) {
			REP(ii,i) while(at[ii]<off[ii+1]&&t[at[ii]].pos<=t[j].pos) cur2+=t[at[ii]++].p,++x2;
			cur1+=t[j].p; ++x1;
			sum1[j]=cur1+cur2; cnt1[j]=x1+x2;
			sum2[j]=t[j].p+cur2; cnt2[j]=1+x2;
		}
	}
	sinit(0,0,n-1);
	//REP(i,MAXG) { if(off[i]==off[i+1]) continue; printf("%d:",i); FOR(j,off[i],off[i+1]) printf("%lld ",sum1[j]); } puts("");
	//REP(i,MAXG) { if(off[i]==off[i+1]) continue; printf("%d:",i); FOR(j,off[i],off[i+1]) printf("%lld ",sum2[j]); } puts("");

	REP(qi,nq) {
		ll x=q[qi]; int pos=0;
		ll havesum=0; int havecnt=0; // cumulative sum and cnt of prices costing [1..2^(i+?)) in [0..pos)
		for(int i=MAXG-1;i>=0;--i) {
			// j1=last index in [off[i]..off[i+1]) for which sum1[j1]<=havesum+x (sum1 is increasing)
			int j1=find1(off[i],off[i+1],havesum+x);
			if(j1>=off[i]&&t[j1].pos>=pos) {
				//printf("A buying %d of cost %lld [%d:..%d]\n",cnt1[j1]-havecnt,sum1[j1]-havesum,i,j1-off[i]);
				x-=sum1[j1]-havesum;
				ret[qi]+=cnt1[j1]-havecnt;
				havesum=sum1[j1];
				havecnt=cnt1[j1];
				pos=t[j1].pos+1;
			}
			// j3=last index in [off[i]..off[i+1]) for which t[j].pos<pos
			int j3=find3(off[i],off[i+1],pos);
			if(j3>=off[i]) havesum-=sum1[j3]-sum2[j3]+t[j3].p,havecnt-=cnt1[j3]-cnt2[j3]+1;
			// j2=first index in [j3+1..off[i+1]) for which sum2[j2]<=havesum+x
			int j2=find2(j3+1,off[i+1],havesum+x);
			if(j2!=-1) {
				//printf("B buying %d of cost %lld [%d:..%d] [%d,%d)->%d\n",cnt2[j2]-havecnt,sum2[j2]-havesum,i,j2-off[i],j3+1,off[i+1],j2);
				x-=sum2[j2]-havesum;
				ret[qi]+=cnt2[j2]-havecnt;
				havesum=sum2[j2]-t[j2].p;
				havecnt=cnt2[j2]-1;
				pos=t[j2].pos+1;
			}
		}
		//printf("=> %lld %d\n",x,ret[qi]);
	}
	REP(i,nq) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}