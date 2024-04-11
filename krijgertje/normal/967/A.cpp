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

const int MAXN=100;

int n,mndst;
int t[MAXN];

int solve() {
	if(n==0||t[0]>=mndst+1) return 0;
	REP(i,n-1) if(t[i+1]-t[i]>=2*mndst+2) return t[i]+mndst+1;
	return t[n-1]+mndst+1;
}

void run() {
	scanf("%d%d",&n,&mndst); REP(i,n) { int h,m; scanf("%d%d",&h,&m); t[i]=h*60+m; }
	int ans=solve(); printf("%d %d\n",ans/60,ans%60);
}

int main() {
	run();
	return 0;
}