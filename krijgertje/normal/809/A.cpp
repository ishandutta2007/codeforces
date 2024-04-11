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

const int MAXN=300000;
const int MOD=1000000007;

int n;
int x[MAXN];
int p2[MAXN];

int calc() {
	int ret=0;
	REP(i,n) {
		ret=(ret+(ll)x[i]*p2[i])%MOD;
	}
	return ret;
}

void run() {
	p2[0]=1; FORE(i,1,MAXN) p2[i]=(ll)2*p2[i-1]%MOD;
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); sort(x,x+n);
	int ret=0;
	ret+=calc();
	reverse(x,x+n);
	ret-=calc();
	ret=(ret%MOD+MOD)%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}