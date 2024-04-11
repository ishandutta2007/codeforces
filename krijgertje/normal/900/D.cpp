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

const int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int g,sum;

vector<int> getprimes(int x) {
	vector<int> ret;
	for(int i=2;i*i<=x;++i) if(x%i==0) { ret.PB(i); while(x%i==0) x/=i; }
	if(x!=1) ret.PB(x);
	return ret;
}

int solve() {
	if(sum%g!=0) return 0;
	sum/=g; g=1;
	int ret=0;
	vector<int> p=getprimes(sum);
	REP(i,1<<SZ(p)) {
		int prod=1,cnt=0; REPSZ(j,p) if(i&(1<<j)) prod*=p[j],++cnt;
		int times=sum/prod;
		int cur=pw(2,times-1);
		if(cnt%2==0) ret=(ret+cur)%MOD; else ret=(ret+MOD-cur)%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&g,&sum);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}