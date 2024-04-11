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

const int MAXN=300000;

typedef struct X { int min,cnt,lazy; } X;

int n;
int p[MAXN];

int mx[MAXN],nmx;
int mn[MAXN],nmn;

X val[1<<20];
void push(int x) {
	if(val[x].lazy!=0) { val[2*x+1].min+=val[x].lazy; val[2*x+1].lazy+=val[x].lazy; val[2*x+2].min+=val[x].lazy; val[2*x+2].lazy+=val[x].lazy; val[x].lazy=0; }
}
void update(int x) {
	val[x].min=min(val[2*x+1].min,val[2*x+2].min);
	val[x].cnt=(val[2*x+1].min==val[x].min?val[2*x+1].cnt:0)+(val[2*x+2].min==val[x].min?val[2*x+2].cnt:0);
	val[x].min+=val[x].lazy;
}
void init(int x,int l,int r) {
	if(l==r) { val[x].min=l; val[x].cnt=1; val[x].lazy=0; return; }
	int m=l+(r-l)/2;
	init(2*x+1,l,m); init(2*x+2,m+1,r); update(x);
}
void change(int x,int l,int r,int L,int R,int BY) {
	
	if(L<=l&&r<=R) { /*printf("changing %d=%d..%d (%d..%d) by %d\n",x,l,r,L,R,BY);*/ val[x].min+=BY; val[x].lazy+=BY; return; }
	int m=l+(r-l)/2;
	push(x);
	if(L<=m) change(2*x+1,l,m,L,R,BY); if(m+1<=R) change(2*x+2,m+1,r,L,R,BY);
	update(x);
}
void print(int x,int l,int r,int d) {
	if(l==r) { REP(i,d) printf("  "); printf("%d=%d = (%d,%d,%d)\n",x,l,val[x].min,val[x].cnt,val[x].lazy); return; }
	int m=l+(r-l)/2;
	print(2*x+1,l,m,d+1); REP(i,d) printf("  "); printf("%d=%d..%d = (%d,%d,%d)\n",x,l,r,val[x].min,val[x].cnt,val[x].lazy); print(2*x+2,m+1,r,d+1);
}


void run() {
	scanf("%d",&n);
	REP(i,n) p[i]=-1;
	REP(i,n) { int r,c; scanf("%d%d",&r,&c); --r,--c; p[r]=c; }

	init(0,0,n-1);
	ll ret=0;
	REP(i,n) {
		//printf("%d: %d\n",i,p[i]);
		while(nmx>=1&&p[i]>=p[mx[nmx-1]]) change(0,0,n-1,nmx>=2?mx[nmx-2]+1:0,mx[nmx-1],-p[mx[nmx-1]]),--nmx;
		change(0,0,n-1,nmx>=1?mx[nmx-1]+1:0,i,+p[i]),mx[nmx++]=i;
		while(nmn>=1&&p[i]<=p[mn[nmn-1]]) change(0,0,n-1,nmn>=2?mn[nmn-2]+1:0,mn[nmn-1],+p[mn[nmn-1]]),--nmn;
		change(0,0,n-1,nmn>=1?mn[nmn-1]+1:0,i,-p[i]),mn[nmn++]=i;
		//print(0,0,n-1,0);
		ret+=val[0].cnt;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}