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

typedef long long nval[3][3]; // for ranges of at least 2, val[i][j] means optimimum when i connect to left and j to right
const int MAXN=30000;
const int MAXVAL=1<<17;

int n,nq;
int have[MAXN];
int w[MAXN],h[MAXN];


inline ll calc(int a,int b) { return have[a]==b?-1:(ll)w[a]*h[b]; } // match warrior a with horse b
inline void update(ll &res,ll a,ll b,ll c,ll d,ll e) { if(a==-1||b==-1||c==-1||d==-1||e==-1) return; ll cur=a+b+c+d+e; if(cur>res) res=cur; }
void init2(nval &c,int l) {
	REP(i,3) REP(j,3) c[i][j]=-1;
	REPE(i,2) { int j=2-i; update(c[i][j],0,0,0,0,0); } //0
	REPE(i,1) { int j=1-i; update(c[i][j],0,0,calc(l+i,l+i),0,0); } //1
	REPE(i,0) { int j=0-i; update(c[i][j],0,0,calc(l,l),calc(l+1,l+1),0); update(c[i][j],0,0,calc(l,l+1),calc(l+1,l),0); } //2
	//printf("init(%d,%d) [%d,%d]:",l,l+1,have[l],have[l+1]); REP(i,3) REP(j,3) printf(" %I64d",c[i][j]); puts("");
}
void init3(nval &c,int l) {
	REP(i,3) REP(j,3) c[i][j]=-1;
	REPE(i,3) { int j=3-i; if(i!=3&&j!=3) update(c[i][j],0,0,0,0,0); } //0
	REPE(i,2) { int j=2-i; update(c[i][j],0,0,calc(l+i,l+i),0,0); } //1
	REPE(i,1) { int j=1-i; update(c[i][j],0,0,calc(l+i,l+i),calc(l+i+1,l+i+1),0); update(c[i][j],0,0,calc(l+i,l+i+1),calc(l+i+1,l+i),0); } //2
	REPE(i,0) {
		int j=0-i;
		update(c[i][j],0,0,calc(l,l),calc(l+1,l+1),calc(l+2,l+2));
		update(c[i][j],0,0,calc(l,l),calc(l+1,l+2),calc(l+2,l+1));
		update(c[i][j],0,0,calc(l,l+1),calc(l+1,l),calc(l+2,l+2));
		update(c[i][j],0,0,calc(l,l+1),calc(l+1,l+2),calc(l+2,l));
		update(c[i][j],0,0,calc(l,l+2),calc(l+1,l),calc(l+2,l+1));
	}
	//printf("init(%d,%d,%d) [%d,%d,%d]:",l,l+1,l+2,have[l],have[l+1],have[l+2]); REP(i,3) REP(j,3) printf(" %I64d",c[i][j]); puts("");
}
void combine(const nval &a,const nval &b,nval &c,int m) {
	REP(i,3) REP(j,3) {
		c[i][j]=-1;
		update(c[i][j],a[i][0],b[0][j],0,0,0); //no crossover
		update(c[i][j],a[i][1],b[1][j],calc(m,m+1),calc(m+1,m),0); //1x1 crossover
		update(c[i][j],a[i][1],b[2][j],calc(m,m+1),calc(m+1,m+2),calc(m+2,m)); //1x2 crossover a
		update(c[i][j],a[i][1],b[2][j],calc(m,m+2),calc(m+1,m),calc(m+2,m+1)); //1x2 crossover b
		update(c[i][j],a[i][2],b[1][j],calc(m-1,m),calc(m,m+1),calc(m+1,m-1)); //2x1 crossover a
		update(c[i][j],a[i][2],b[1][j],calc(m-1,m+1),calc(m,m-1),calc(m+1,m)); //2x1 crossover b
	}
	//printf("combine(%d,%d,%d,%d) [%d,%d,%d,%d]:",m-1,m,m+1,m+2,have[m-1],have[m],have[m+1],have[m+2]); REP(i,3) REP(j,3) printf(" %I64d",c[i][j]); puts("");
}

nval val[MAXVAL];
void init(int x,int l,int h) {
	if(h-l+1==2) init2(val[x],l);
	else if(h-l+1==3) init3(val[x],l);
	else {
		int m=l+(h-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,h);
		combine(val[2*x+1],val[2*x+2],val[x],m);
	}
}
void update(int x,int l,int h,int IDX) {
	if(h-l+1==2) init2(val[x],l);
	else if(h-l+1==3) init3(val[x],l);
	else {
		int m=l+(h-l)/2;
		if(IDX<=m) update(2*x+1,l,m,IDX); else update(2*x+2,m+1,h,IDX);
		combine(val[2*x+1],val[2*x+2],val[x],m);
	}
}

pair<int,int> worig[MAXN];
pair<int,int> horig[MAXN];
int wmap[MAXN];
int hmap[MAXN];



void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) worig[i].second=i,scanf("%d",&worig[i].first); sort(worig,worig+n); REP(i,n) wmap[worig[i].second]=i,w[i]=worig[i].first;
	REP(i,n) horig[i].second=i,scanf("%d",&horig[i].first); sort(horig,horig+n); REP(i,n) hmap[horig[i].second]=i,h[i]=horig[i].first;
	REP(i,n) have[wmap[i]]=hmap[i];
	init(0,0,n-1);
	REP(qi,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		swap(have[wmap[a]],have[wmap[b]]);
		update(0,0,n-1,wmap[a]);
		update(0,0,n-1,wmap[b]);
		printf("%I64d\n",val[0][0][0]);
	}
}


int main() {
	run();
	return 0;
}