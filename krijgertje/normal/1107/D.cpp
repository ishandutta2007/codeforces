#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=5200;

int n;
int a[MAXN][MAXN];

int m;
int b[MAXN][MAXN];

bool can(int p) {
	if(n%p!=0) return false;
	m=n/p;
	REP(x,m) REP(y,m) { b[x][y]=a[x*p][y*p]; REP(i,p) REP(j,p) if(a[x*p+i][y*p+j]!=b[x][y]) return false; }
	//printf("yes %d->%d\n",n,m);
	return true;
}

int solve() {
	//REP(i,n) { REP(j,n) printf("%d",a[i][j]); puts(""); }
	vector<int> p; { int x=n; for(int i=2;i*i<=x;++i) if(x%i==0) { p.PB(i); while(x%i==0) x/=i; } if(x!=1) p.PB(x); }
	//printf("p:"); REPSZ(i,p) printf(" %d",p[i]); puts("");
	int ret=1;
	REPSZ(i,p) while(can(p[i])) { ret*=p[i]; n=m; REP(x,n) REP(y,n) a[x][y]=b[x][y]; }
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) REP(j,n/4) { char c; scanf(" %c",&c); int x=isdigit(c)?c-'0':10+c-'A'; REP(k,4) a[i][4*j+3-k]=(x>>k)&1; }
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}