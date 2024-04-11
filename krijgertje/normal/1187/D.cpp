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
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=300000;

int n;
int a[MAXN];
int b[MAXN];

pair<int,int> oa[MAXN];
pair<int,int> ob[MAXN];

int apos[MAXN];

int sval[4*MAXN];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=a[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return sval[x];
	int m=l+(r-l)/2;
	int ret=INT_MAX;
	if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
	if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
	return ret;
}
void skill(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=INT_MAX;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) skill(2*x+1,l,m,IDX); else skill(2*x+2,m+1,r,IDX);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}

bool solve() {
	REP(i,n) oa[i]=MP(a[i],i); sort(oa,oa+n);
	REP(i,n) ob[i]=MP(b[i],i); sort(ob,ob+n);
	REP(i,n) if(oa[i].first!=ob[i].first) return false;
	REP(i,n) a[oa[i].second]=i;
	REP(i,n) b[ob[i].second]=i;
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	//printf("b:"); REP(i,n) printf(" %d",b[i]); puts("");

	sinit(0,0,n-1);
	REP(i,n) apos[a[i]]=i;
	REP(i,n) {
		int idx=apos[b[i]];
		if(idx>0&&sget(0,0,n-1,0,idx-1)<b[i]) return false;
		skill(0,0,n-1,idx);
	}


	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int ncase; scanf("%d",&ncase); REP(i,ncase) run();
	return 0;
}