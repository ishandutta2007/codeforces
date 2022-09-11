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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXEMP=200000;
struct Emp { int l,r; };
bool operator<(const Emp &a,const Emp &b) { return a.l>b.l; }

int nemp; ll budget;
Emp emp[MAXEMP];

int solve() {
	sort(emp,emp+nemp);
	int maxr=emp[0].r; FOR(i,1,nemp) maxr=max(maxr,emp[i].r);
	int lo=0,hi=maxr+1;
	while(lo+1<hi) {
		int mi=lo+(hi-lo)/2;
		ll need=0; int cnt=0;
		REP(i,nemp) if(cnt<(nemp+1)/2&&emp[i].r>=mi) need+=max(emp[i].l,mi),++cnt; else need+=emp[i].l;
		if(cnt==(nemp+1)/2&&need<=budget) lo=mi; else hi=mi;
	}
	return lo;
}

void run() {
	scanf("%d%lld",&nemp,&budget);
	REP(i,nemp) scanf("%d%d",&emp[i].l,&emp[i].r);
	printf("%d\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}