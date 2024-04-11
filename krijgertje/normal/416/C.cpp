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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

typedef struct X { int need,get,id; } X;
typedef struct Y { int have,id; } Y;
bool operator<(const X &a,const X &b) { return a.get>b.get; }
bool operator<(const Y &a,const Y &b) { return a.have<b.have; }

int nvisit;
X x[1000];
int ntable;
Y y[1000];

int ret,nans;
int ans[1000][2];

void run() {
	scanf("%d",&nvisit); REP(i,nvisit) { scanf("%d %d",&x[i].need,&x[i].get); x[i].id=i+1; }
	scanf("%d",&ntable); REP(i,ntable) { scanf("%d",&y[i].have); y[i].id=i+1; }
	sort(x,x+nvisit);
	sort(y,y+ntable);
	ret=0,nans=0;
	REP(i,nvisit) {
		REP(j,ntable) if(x[i].need<=y[j].have) {
			ret+=x[i].get;
			ans[nans][0]=x[i].id; ans[nans][1]=y[j].id; ++nans;
			for(;j+1<ntable;++j) y[j]=y[j+1];
			--ntable;
		}
	}
	printf("%d %d\n",nans,ret);
	REP(i,nans) printf("%d %d\n",ans[i][0],ans[i][1]);
}

int main() {
	run();
	return 0;
}