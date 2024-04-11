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

typedef struct R { int minx,cnt,gcd; } R;
R combine(const R &a,const R &b) { R ret; ret.minx=min(a.minx,b.minx); ret.cnt=(a.minx==ret.minx?a.cnt:0)+(b.minx==ret.minx?b.cnt:0); ret.gcd=gcd(a.gcd,b.gcd); return ret; }

int n,nq;
int s[100000];
R val[1<<18];

void init(int x,int l,int r) {
	if(l==r) { val[x].minx=s[l]; val[x].cnt=1; val[x].gcd=s[l]; return; }
	int m=l+(r-l)/2;
	init(2*x+1,l,m); init(2*x+2,m+1,r);
	val[x]=combine(val[2*x+1],val[2*x+2]);
}

R calc(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return val[x];
	int m=l+(r-l)/2;
	if(R<=m) return calc(2*x+1,l,m,L,R);
	if(m+1<=L) return calc(2*x+2,m+1,r,L,R);
	return combine(calc(2*x+1,l,m,L,R),calc(2*x+2,m+1,r,L,R));
}


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&s[i]);
	init(0,0,n-1);

	scanf("%d",&nq);
	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		R res=calc(0,0,n-1,l,r);
		int ans=(r-l+1)-(res.minx==res.gcd?res.cnt:0);
		printf("%d\n",ans);
	}

}

int main() {
	run();
	return 0;
}