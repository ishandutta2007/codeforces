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

const int MAXBIT=30;
const int MAXAVENG=100000;

int nbit,naveng,A,B;
int x[MAXAVENG];

ll calc(int lx,int hx,int lidx,int hidx) {
	//printf("calc(%d,%d,%d,%d)\n",lx,hx,lidx,hidx);
	if(lidx==hidx) return A;
	ll ret=(ll)B*(hidx-lidx)*(hx-lx);
	if(hx-lx==1) return ret;
	int mx=lx+(hx-lx)/2;
	int midx=lidx; while(midx<hidx&&x[midx]<mx) ++midx;
	ret=min(ret,calc(lx,mx,lidx,midx)+calc(mx,hx,midx,hidx));
	return ret;
}

ll solve() {
	sort(x,x+naveng);
	return calc(0,1<<nbit,0,naveng);
}

void run() {
	scanf("%d%d%d%d",&nbit,&naveng,&A,&B);
	REP(i,naveng) scanf("%d",&x[i]),--x[i];
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}