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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n,nq;
int a[100000];
int val[1<<18][60];

void init(int x,int l,int r) {
	if(l==r) {
		REP(t,60) val[x][t]=t%a[l]==0?2:1;
	} else {
		int m=l+(r-l)/2;
		init(2*x+1,l,m); init(2*x+2,m+1,r);
		REP(t,60) val[x][t]=val[2*x+1][t]+val[2*x+2][(t+val[2*x+1][t])%60];
	}
}

void update(int x,int l,int r,int at) {
	if(l==at&&at==r) {
		REP(t,60) val[x][t]=t%a[l]==0?2:1;
	} else {
		int m=l+(r-l)/2;
		if(at<=m) update(2*x+1,l,m,at);
		if(m+1<=at) update(2*x+2,m+1,r,at);
		REP(t,60) val[x][t]=val[2*x+1][t]+val[2*x+2][(t+val[2*x+1][t])%60];
	}
}

int calc(int x,int l,int r,int t,int L,int R) {
	if(L<=l&&r<=R) {
//		printf("\tcalc(%d,%d,%d,%d,%d,%d)=%d\n",x,l,r,t,L,R,val[x][t%60]);
		return val[x][t%60];
	}
	int m=l+(r-l)/2;
	int ret=0;
	if(L<=m) ret+=calc(2*x+1,l,m,t,L,R);
	if(m+1<=R) ret+=calc(2*x+2,m+1,r,t+ret,L,R);
//	printf("\tcalc(%d,%d,%d,%d,%d,%d)=%d\n",x,l,r,t,L,R,ret);
	return ret;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	init(0,0,n-1);
	scanf("%d",&nq);
	REP(qi,nq) {
		char c; scanf(" %c",&c);
		if(c=='A') {
			int x,y; scanf("%d%d",&x,&y); --x,--y;
			int ret=calc(0,0,n-1,0,x,y-1);
			printf("%d\n",ret);
		} else {
			int x; scanf("%d",&x); --x; scanf("%d",&a[x]);
			update(0,0,n-1,x);
		}
	}

}

int main() {
	run();
	return 0;
}