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

int n,ncap;
int c[MAXN];
bool iscap[MAXN];


void run() {
	scanf("%d%d",&n,&ncap);
	REP(i,n) scanf("%d",&c[i]);
	REP(i,n) iscap[i]=false;
	REP(i,ncap) { int x; scanf("%d",&x); --x; iscap[x]=true; }

	ll ret=0,sum=0,sumcap=0;
	REP(i,n) sum+=c[i],sumcap+=iscap[i]?c[i]:0;
	REP(i,n) {
		if(iscap[i]) { ret+=(ll)c[i]*(sum-c[i]); continue; }
		ret+=(ll)c[i]*sumcap;
		for(int d=-1;d<=+1;d+=2) {
			int j=i+d; if(j<0) j+=n; if(j>=n) j-=n; if(iscap[j]) continue;
			ret+=(ll)c[i]*c[j];
		}
	}
	printf("%lld\n",ret/2);
}

int main() {
	run();
	return 0;
}