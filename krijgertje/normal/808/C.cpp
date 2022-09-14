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

int n,have;
int x[MAXN];
int ret[MAXN];

pair<int,int> o[MAXN];

void run() {
	scanf("%d%d",&n,&have); REP(i,n) scanf("%d",&x[i]);
	REP(i,n) o[i]=MP(-x[i],i); sort(o,o+n);
	int left=have;
	REP(i,n) {
		int need=(x[i]+1)/2; if(left<need) { printf("-1\n"); return; }
		left-=need; ret[i]=need;
	}
	REP(ii,n) {
		int i=o[ii].second; 
		int cur=min(x[i]-ret[i],left); ret[i]+=cur; left-=cur;
	}
	if(left>0) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}