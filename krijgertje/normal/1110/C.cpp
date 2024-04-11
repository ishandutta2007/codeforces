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

const int MAXBIT=25;

int precalc[MAXBIT+1];

void run() {
	FORE(nbit,2,MAXBIT) {
		int a=(1<<nbit)-1;
		int mx=-1; for(int i=1;i*i<=a;++i) if(a%i==0) { if(i<a) mx=max(mx,gcd(a^i,a&i)); int j=a/i; if(j<a) mx=max(mx,gcd(a^j,a&j)); }
		//printf("%d: %d\n",nbit,mx);
		precalc[nbit]=mx;
	}
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int a; scanf("%d",&a);
		int nbit=0; while(a>=(1<<nbit)) ++nbit;
		int ans=a==(1<<nbit)-1?precalc[nbit]:(1<<nbit)-1;
		printf("%d\n",ans);
	}
}

void research() {
	FORE(nbit,1,25) {
		int a=(1<<nbit)-1;
		int mx=-1;
		int best=-1;
		FOR(b,1,a) { int cur=gcd(a^b,a&b); if(cur>mx) mx=cur,best=b; }
		printf("%d: %d -> %d (%d)\n",nbit,a,mx,best);
		assert(a%mx==0);
	}
}

int main() {
	//research();
	run();
	return 0;
}