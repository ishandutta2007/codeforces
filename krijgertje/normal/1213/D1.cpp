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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXVAL=200000;

int n,want;
int a[MAXN];

int cnt[MAXVAL+1];

int solve() {
	REPE(i,MAXVAL) cnt[i]=0;
	REP(i,n) ++cnt[a[i]]; REP(i,MAXVAL) cnt[i+1]+=cnt[i];
	int ret=INT_MAX;
	REPE(x,MAXVAL) {
		int cur=0,have=cnt[x]-(x==0?0:cnt[x-1]),l=x,r=x,cost=0;
		while(have<want&&r<MAXVAL) {
			int nr=min(MAXVAL,2*r+1),nl=min(nr+1,max(r+1,2*l)); ++cost;
			//if(x<=10) printf("x=%d cur=%d have=%d cost=%d %d..%d\n",x,cur,have,cost,nl,nr);
			int lim=cnt[nr]-cnt[nl-1];
			int now=min(lim,want-have);
			cur+=cost*now; have+=now; l=nl,r=nr;
		}
		if(have>=want) ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}