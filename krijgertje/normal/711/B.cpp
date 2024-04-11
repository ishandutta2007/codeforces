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

const int MAXN=500;

int n;
int a[MAXN][MAXN];

ll solve() {
	if(n==1) return 1;
	int xx=-1,yy=-1; REP(x,n) REP(y,n) if(a[x][y]==0) xx=x,yy=y;
	ll want=0; { int x=0; if(x==xx) ++x; REP(y,n) want+=a[x][y]; }
	vector<ll> need;
	REP(x,n) { ll cur=0; REP(y,n) cur+=a[x][y]; if(x!=xx&&cur!=want) return -1; if(x==xx) need.PB(want-cur); }
	REP(y,n) { ll cur=0; REP(x,n) cur+=a[x][y]; if(y!=yy&&cur!=want) return -1; if(y==yy) need.PB(want-cur); }
	{ ll cur=0; REP(z,n) cur+=a[z][z]; if(xx!=yy&&cur!=want) return -1; if(xx==yy) need.PB(want-cur); }
	{ ll cur=0; REP(z,n) cur+=a[z][n-z-1]; if(xx!=n-yy-1&&cur!=want) return -1; if(xx==n-yy-1) need.PB(want-cur); }
	sort(need.begin(),need.end()); need.erase(unique(need.begin(),need.end()),need.end()); if(SZ(need)!=1||need[0]<1) return -1; return need[0];
}

void run() {
	scanf("%d",&n); REP(i,n) REP(j,n) scanf("%d",&a[i][j]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}