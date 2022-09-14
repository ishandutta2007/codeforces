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
const int MAXLEN=200000;
const int MAXE=9*MAXN+1;
typedef struct E { int t,l,r,by; } E;
bool operator<(const E &a,const E &b) { return a.t<b.t; }

int n,len;
int a[MAXN],b[MAXN];
E e[MAXE]; int ne;


int smin[4*MAXN];
int scnt[4*MAXN];
ll ssum[4*MAXN];
int slazy[4*MAXN];

void sapply(int x,int by) { smin[x]+=by; slazy[x]+=by; }
void scalc(int x) { smin[x]=min(smin[2*x+1],smin[2*x+2]); scnt[x]=ssum[x]=0; if(smin[2*x+1]==smin[x]) scnt[x]+=scnt[2*x+1],ssum[x]+=ssum[2*x+1]; if(smin[2*x+2]==smin[x]) scnt[x]+=scnt[2*x+2],ssum[x]+=ssum[2*x+2]; }
void spush(int x) { if(slazy[x]==0) return; sapply(2*x+1,slazy[x]); sapply(2*x+2,slazy[x]); slazy[x]=0; }

void sinit(int x,int l,int r,int p) {
	slazy[x]=0;
	if(l==r) {
		smin[x]=0; if(l%2==p) scnt[x]=1,ssum[x]=l; else scnt[x]=0,ssum[x]=0;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m,p);
		sinit(2*x+2,m+1,r,p);
		scalc(x);
	}
}

void smod(int x,int l,int r,int L,int R,int BY) {
	//if(x==0) printf("\t\t\t%d..%d by %d\n",L,R,BY);
	if(L<=l&&r<=R) {
		sapply(x,BY);
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,BY);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,BY);
		scalc(x);
	}
}


void addrange(int tl,int tr,int l,int r) {
	if(l>r) return;
	e[ne].t=tl,e[ne].l=l,e[ne].r=r,e[ne].by=+1,++ne;
	e[ne].t=tr,e[ne].l=l,e[ne].r=r,e[ne].by=-1,++ne;
}

pair<int,int> c[MAXN]; int nc;
pair<int,int> d[MAXN]; int nd;

void run() {
	scanf("%d%d",&n,&len); REP(i,n) scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
	nc=0; REP(i,n) c[nc++]=MP(a[i],b[i]); sort(c,c+nc); int nnc=0; REP(i,nc) if(nnc==0||c[i].first>c[nnc-1].second+1) c[nnc++]=c[i]; else c[nnc-1].second=max(c[nnc-1].second,c[i].second); nc=nnc;
	nd=0; if(c[0].first>0) d[nd++]=MP(0,c[0].first-1); REP(i,nc-1) d[nd++]=MP(c[i].second+1,c[i+1].first-1); if(c[nc-1].second<len-1) d[nd++]=MP(c[nc-1].second+1,len-1);
	//REP(i,nd) printf("%d..%d\n",d[i].first,d[i].second);
	ll ret=0;
	REP(ps,2) REP(pt,2) {
		//printf("ps=%d pt=%d\n",ps,pt);
		ne=0; sinit(0,0,len-1,pt);
		REP(i,n) {
			//printf("\t\t%d:"); if(pt!=a[i]%2) printf(" Asbef->tnotin"); if((b[i]-a[i]+1)%2==0) printf(" Bsbef->tnotaft"); if(ps!=pt) printf(" Csin->tnotin"); if(ps!=b[i]%2) printf(" Dsin->tnotaft"); puts("");
			if(pt!=a[i]%2) addrange(0,a[i],a[i],b[i]);
			if((b[i]-a[i]+1)%2==0) addrange(0,a[i],b[i]+1,len-1);
			if(ps!=pt) addrange(a[i],b[i]+1,a[i],b[i]);
			if(ps!=b[i]%2) addrange(a[i],b[i]+1,b[i]+1,len-1);
		}
		sort(e,e+ne);
		int ei=0;
		int di=0;
		for(int i=ps;i<len;i+=2) {
			if(di<nd&&i>=d[di].first) smod(0,0,len-1,d[di].first,d[di].second,+1),++di;
			if(i!=0) smod(0,0,len-1,0,i-1,+1);
			while(ei<ne&&e[ei].t<=i) smod(0,0,len-1,e[ei].l,e[ei].r,e[ei].by),++ei;
			//printf("\ts=%d: min=%d cnt=%d sum=%lld\n",i,smin[0],scnt[0],ssum[0]);
			if(smin[0]==0) ret+=ssum[0]+scnt[0]-(ll)scnt[0]*i;
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}