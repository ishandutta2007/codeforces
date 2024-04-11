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
const int MOD=1000000007;

int cnt(int a,int nzero,int dv) {
	ll ret=a/dv; ll c=a%dv;
	REP(i,nzero) {
		c*=10;
		ret=(10*ret+c/dv)%MOD;
		c%=dv;
	}
	if(c!=0) ++ret;
	//printf("\t%d %d %d -> %d\n",a,nzero,dv,(int)ret);
	return ret;
}

int calc(int len,int dv,int forbid) {
	// #<p10[len]+(#<(forbid+1)*p10[len-1]-#<forbid*p10[len-1])
	// #<x == ceil(x/dv)
	int ret=cnt(1,len,dv)-cnt(forbid==9?1:forbid+1,forbid==9?len:len-1,dv)+cnt(forbid,len-1,dv);
	while(ret<0) ret+=MOD;
	//printf("%d %d %d -> %d\n",len,dv,forbid,ret);
	return ret;
}

int n,k,m;
int a[MAXN],b[MAXN];

void run() {
	scanf("%d%d",&n,&k); m=n/k;
	REP(i,m) scanf("%d",&a[i]);
	REP(i,m) scanf("%d",&b[i]);

	int ret=1;
	REP(i,m) ret=(ll)ret*calc(k,a[i],b[i])%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}