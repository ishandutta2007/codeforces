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

const int MAXH=20;
const int MAXW=20;

int h,w; ll want;
ll g[MAXH][MAXW];

map<ll,int> cnt[MAXH][MAXW];

void run() {
	scanf("%d%d%lld",&h,&w,&want); REP(x,h) REP(y,w) scanf("%lld",&g[x][y]);

	int n=h-1+w-1,n1=n/2,n2=n-n1; ll ret=0;
	REP(mask,1<<n1) {
		int x=0,y=0; ll cur=g[x][y]; bool ok=true;
		REP(i,n1) {
			if((mask&(1<<i))==0) ++x; else ++y;
			if(x>=h||y>=w) { ok=false; break; }
			cur^=g[x][y];
		}
		if(!ok) continue;
		++cnt[x][y][cur];
	}
	REP(mask,1<<n2) {
		int x=h-1,y=w-1; ll cur=g[x][y]; bool ok=true;
		REP(i,n2) {
			if((mask&(1<<i))==0) --x; else --y;
			if(x<0||y<0) { ok=false; break; }
			cur^=g[x][y];
		}
		if(!ok) continue;
		cur^=g[x][y]^want;
		ret+=cnt[x][y][cur];
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}