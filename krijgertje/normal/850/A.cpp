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

const int MAXN=1000;

int n;
int x[MAXN][5];

int ret[MAXN],nret;

bool ok(int o) {
	REP(i,n) if(i!=o) REP(j,i) if(j!=o) {
		int sum=0; REP(k,5) sum+=x[i][k]*x[j][k];
		if(sum>0) return false;
	}
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) REP(k,5) scanf("%d",&x[i][k]);

	nret=0;
	REP(i,n) {
		REP(j,n) if(i!=j) REP(k,5) x[j][k]-=x[i][k]; REP(k,5) x[i][k]=0;
		if(ok(i)) ret[nret++]=i;
	}
	printf("%d\n",nret); REP(i,nret) printf("%d\n",ret[i]+1);
}

int main() {
	run();
	return 0;
}