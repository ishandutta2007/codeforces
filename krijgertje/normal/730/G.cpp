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

const int MAXN=200;

int n;
int s[MAXN],d[MAXN];

bool conflict(int i,int j) {
	if(s[i]>s[j]) swap(i,j);
	return s[i]+d[i]>s[j];
}
bool ok(int i) {
	REP(j,i) if(conflict(i,j)) return false;
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&s[i],&d[i]);
	REP(i,n) {
		if(ok(i)) continue;
		int t=INT_MAX;
		if(1<t) { s[i]=1; if(ok(i)) t=s[i]; }
		REP(j,i) if(s[j]+d[j]<t) { s[i]=s[j]+d[j]; if(ok(i)) t=s[i]; }
		s[i]=t;
	}
	REP(i,n) printf("%d %d\n",s[i],s[i]+d[i]-1);
}

int main() {
	run();
	return 0;
}