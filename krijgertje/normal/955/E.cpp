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

const int MAXN=100000;
const int MAXLG=16;

int n;
int a[MAXN];


vector<pair<int,int> > e[MAXN+1];
set<int> stops;

int lg[MAXN+1];

int b[MAXLG+1][MAXN];
// min of a[i]+shoutidx-i
int solvebefore(int l,int r,int shoutidx) {
	if(l>r) return INT_MAX;
	//int ret=INT_MAX; FORE(i,l,r) ret=min(ret,a[i]+shoutidx-i); return ret;
	int k=lg[r-l+1]; return min(b[k][l],b[k][r-(1<<k)+1])+shoutidx;
}

int c[MAXLG+1][MAXN];
// min of a[i]+i-shoutidx
int solveafter(int l,int r,int shoutidx) {
	if(l>r) return INT_MAX;
	//int ret=INT_MAX; FORE(i,l,r) ret=min(ret,a[i]+i-shoutidx); return ret;
	int k=lg[r-l+1]; return min(c[k][l],c[k][r-(1<<k)+1])-shoutidx;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	// find index idx of the leftmost one with dx+a[i]-i<=0, this is the first icicle that will stop the running
	// find the minimum of dx+a[i] at positions >= idx and the minimum of dx+a[i] at positions < idx

	lg[1]=0; FORE(i,2,n) { lg[i]=lg[i-1]; while((2<<lg[i])<=i) ++lg[i]; }
	REP(i,n) b[0][i]=a[i]-i; REP(k,MAXLG) REPE(i,n-(1<<k)) b[k+1][i]=min(b[k][i],b[k][i+(1<<k)]);
	REP(i,n) c[0][i]=a[i]+i; REP(k,MAXLG) REPE(i,n-(1<<k)) c[k+1][i]=min(c[k][i],c[k][i+(1<<k)]);


	REP(i,n) {
		int dx=i-a[i]; if(dx<0) continue;
		int l=max(0,i-dx),r=min(n-1,i+dx);
		//printf("%d stops when shouting in range %d..%d\n",i,l,r);
		e[l].PB(MP(i,+1)); e[r+1].PB(MP(i,-1));
	}

	int ret=INT_MAX;
	REP(shoutidx,n) {
		REPSZ(j,e[shoutidx]) {
			int k=e[shoutidx][j].first,kind=e[shoutidx][j].second;
			if(kind==+1) stops.insert(k); else if(kind==-1) stops.erase(k);
		}
		if(SZ(stops)==0) continue;
		int stopidx=*stops.begin();
		// <  stopidx <=shoutidx
		int ltrap1=solvebefore(0,min(stopidx-1,shoutidx),shoutidx);
		// <  stopidx >=shoutidx
		int ltrap2=solveafter(shoutidx,stopidx-1,shoutidx);
		// >= stopidx <=shoutidx
		int rtrap1=solvebefore(stopidx,shoutidx-1,shoutidx);
		// >= stopidx >=shoutidx
		int rtrap2=solveafter(max(stopidx,shoutidx),n-1,shoutidx);
		int ltrap=min(ltrap1,ltrap2),rtrap=min(rtrap1,rtrap2),cur=max(ltrap,rtrap);
		//printf("shout at %d -> stopped by %d [%d,%d] [%d,%d] -> %d\n",shoutidx,stopidx,ltrap1,ltrap2,rtrap1,rtrap2,cur);
		ret=min(ret,cur);
	}
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}