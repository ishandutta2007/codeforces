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

const int MAXN=100000;

int n;
int pmx[MAXN+1];

void run() {
	scanf("%d",&n);
	// k(q+x) = (k+1)*(k+1)*y*y -> nq=y
	memset(pmx,-1,sizeof(pmx));
	FORE(i,2,n) if(pmx[i]==-1) for(int j=i;j<=n;j+=i) pmx[j]=i;

	ll q=2;
	FORE(k,1,n) {
		ll y=1; for(int z=k;z!=1;) { int p=pmx[z],cnt=0; while(pmx[z]==p) z/=p,++cnt; REP(i,(cnt+1)/2) y=y*p; }
		assert((y*y)%k==0);
		ll x=y*y/k*(k+1)*(k+1)-q;
		printf("%lld\n",x);
		q=y;
	}
}

int main() {
	run();
	return 0;
}