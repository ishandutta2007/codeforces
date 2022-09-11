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

int l,r,x,y;

int solve() {
	if(y%x!=0) return 0;
	y/=x;
	l=(l+x-1)/x;
	r=r/x;
	if(l>r) return 0;
	vector<int> dv;
	for(int d=1;(ll)d*d<=y;++d) if(y%d==0) {
		dv.PB(d);
		if(d*d!=y) dv.PB(y/d);
	}
	int ret=0;
	REPSZ(i,dv) { int d=dv[i]; if(l<=d&&d<=r&&l<=y/d&&y/d<=r&&gcd(d,y/d)==1) ++ret; }
	return ret;
}

void run() {
	scanf("%d%d%d%d",&l,&r,&x,&y);
	printf("%d\n",solve());
}

int bf(int l,int r,int x,int y) {
	int ret=0;
	FORE(i,l,r) FORE(j,l,r) if(gcd(i,j)==x&&i/gcd(i,j)*j==y) ++ret;
	return ret;
}

void stress() {
	FORE(l,1,50) FORE(r,l,50) FORE(x,1,50) FORE(y,1,50) {
		::l=l,::r=r,::x=x,::y=y;
		int have=solve();
		int want=bf(l,r,x,y);
		if(have!=want) { printf("%d %d %d %d: have=%d want=%d\n",l,r,x,y,have,want); return; }
	}
}

int main() {
	run();
	//stress();
	return 0;
}