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

const int MAXLEN=100000;
const int MAXN=100;

int len,n;
int l[MAXN],r[MAXN];

int dp[2][MAXLEN+1]; // dp[i][x] is min # flips to cook the cutlet for x seconds on side A, where i indicates if the cutlet is currently on side A
int ndp[2][MAXLEN+1];

void upd(int &a,int b,int c) { if(b!=INT_MAX&&b+c<a) a=b+c; }

void dofixed(int dx) {
	REPE(x,len) {
		ndp[0][x]=ndp[1][x]=INT_MAX;
		upd(ndp[0][x],dp[0][x],0);
		upd(ndp[0][x],dp[1][x],1);
		if(x-dx>=0) {
			upd(ndp[1][x],dp[1][x-dx],0);
			upd(ndp[1][x],dp[0][x-dx],1);
		}
	}
	REPE(x,len) dp[0][x]=ndp[0][x],dp[1][x]=ndp[1][x];
}

typedef struct Q {
	pair<int,int> v[MAXLEN+1]; int head,tail;
	void init() { head=tail=0; }
	void add(int x,int y) { while(tail<head&&v[head-1].second>=y) --head; v[head++]=MP(x,y); }
	void remove(int x) { while(tail<head&&v[tail].first<x) ++tail; }
	int get() { return tail<head?v[tail].second:INT_MAX; }
} Q;

Q q0,q1;
void dovariable(int dx) {
	q0.init(); q1.init();
	REPE(x,len) {
		ndp[0][x]=ndp[1][x]=INT_MAX;
		upd(ndp[0][x],dp[0][x],0);
		if(x-dx>=0) {
			upd(ndp[1][x],dp[1][x-dx],0);
		}
		q0.add(x,dp[0][x]); q1.add(x,dp[1][x]); q0.remove(x-dx); q1.remove(x-dx);
		//printf("dx=%d x=%d -> %d %d [%d %d]\n",dx,x,q0.get(),q1.get(),q0.head,q0.tail);
		upd(ndp[0][x],q1.get(),1);
		upd(ndp[1][x],q1.get(),2);
		upd(ndp[0][x],q0.get(),2);
		upd(ndp[1][x],q0.get(),1);
	}
	REPE(x,len) dp[0][x]=ndp[0][x],dp[1][x]=ndp[1][x];
}

void run() {
	scanf("%d%d",&len,&n); REP(i,n) scanf("%d%d",&l[i],&r[i]);
	REP(i,2) REPE(x,len) dp[i][x]=x==0?0:INT_MAX;
	REP(i,n) {
		dofixed(l[i]-(i==0?0:r[i-1]));
		//printf("after fixed %d..%d:\n",i==0?0:r[i-1],l[i]); REP(j,2) { REPE(x,len) if(dp[j][x]==INT_MAX) printf(" X"); else printf(" %d",dp[j][x]); puts(""); }
		dovariable(r[i]-l[i]);
		//printf("after var %d..%d:\n",l[i],r[i]); REP(j,2) { REPE(x,len) if(dp[j][x]==INT_MAX) printf(" X"); else printf(" %d",dp[j][x]); puts(""); }
	}
	dofixed(2*len-r[n-1]);
	//printf("after fixed %d..%d:\n",r[n-1],2*len); REP(j,2) { REPE(x,len) if(dp[j][x]==INT_MAX) printf(" X"); else printf(" %d",dp[j][x]); puts(""); }
	int ret=min(dp[0][len],dp[1][len]);
	if(ret==INT_MAX) printf("Hungry\n"); else printf("Full %d\n",ret);
}

int main() {
	run();
	return 0;
}