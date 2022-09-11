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

const int MAXKIND=100;

int nrow,nkind;
int cnt[MAXKIND];

bool solve() {
	int n4=nrow,n2=2*nrow;
	REP(i,nkind) while(cnt[i]>=4&&n4>0) cnt[i]-=4,--n4;
	REP(i,nkind) while(cnt[i]>=2&&n2>0) cnt[i]-=2,--n2;
	int r1=0,r2=0;
	REP(i,nkind) while(cnt[i]>=2) cnt[i]-=2,++r2;
	REP(i,nkind) while(cnt[i]>=1) cnt[i]-=1,++r1;
	while(r2>0&&n2>0) --r2,--n2;
	if(r2==0) return r1<=2*n4+n2;
	assert(n2==0);
	while(r2>0&&r1>0&&n4>0) --r2,--r1,--n4;
	if(r2==0) return r1<=2*n4;
	while(r2>=3&&n4>=2) r2-=3,n4-=2;
	if(r1==0) return r2<=n4;
	return false;
}

void run() {
	scanf("%d%d",&nrow,&nkind); REP(i,nkind) scanf("%d",&cnt[i]);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}