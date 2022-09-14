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
int x[MAXN];
int y[MAXN];
int z[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]);

	// ret=max(min(min(x[j]-j+i,j=-1..i),min(x[j]+j-i,j=i..n)),i=0..n-1)
	{ int best=1; REP(i,n) { int cur=x[i]-i; if(cur<best) best=cur; y[i]=best+i; } }
	{ int best=n; for(int i=n-1;i>=0;--i) { int cur=x[i]+i; if(cur<best) best=cur; z[i]=best-i; } }

	int ret=INT_MIN; REP(i,n) { int cur=min(y[i],z[i]); if(cur>ret) ret=cur; } printf("%d\n",ret);
}


int main() {
	run();
	return 0;
}