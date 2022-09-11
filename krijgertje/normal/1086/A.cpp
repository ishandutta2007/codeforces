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

int n=3;
int x[3],y[3];

int cx[3],cy[3];
set<pair<int,int>> have;

void solve() {
	int lx=x[0],hx=x[0]; REP(i,n) lx=min(lx,x[i]),hx=max(hx,x[i]); int mx=x[0]+x[1]+x[2]-lx-hx;
	int ly=y[0],hy=y[0]; REP(i,n) ly=min(ly,y[i]),hy=max(hy,y[i]); int my=y[0]+y[1]+y[2]-ly-hy;
	REP(i,n) cx[i]=x[i],cy[i]=y[i];
	REP(i,n) {
		while(true) {
			have.insert(MP(cx[i],cy[i]));
			if(cx[i]<mx) ++cx[i]; else if(cx[i]>mx) --cx[i]; else break;
		}
	}
	REP(i,n) {
		while(true) {
			have.insert(MP(cx[i],cy[i]));
			if(cy[i]<my) ++cy[i]; else if(cy[i]>my) --cy[i]; else break;
		}
	}
}

void run() {
	REP(i,n) scanf("%d%d",&x[i],&y[i]);
	solve();
	printf("%d\n",SZ(have)); for(auto it=have.begin();it!=have.end();++it) printf("%d %d\n",it->first,it->second);
}

int main() {
	run();
	return 0;
}