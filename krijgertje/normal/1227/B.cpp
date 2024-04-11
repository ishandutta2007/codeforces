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

const int MAXN=100000;

int n;
int q[MAXN];
int p[MAXN];

bool used[MAXN];

bool solve() {
	REP(i,n) p[i]=-1,used[i]=false;
	REP(i,n) if(i==0||q[i]>q[i-1]) { p[i]=q[i],used[p[i]]=true; }
	int at=0;
	REP(i,n) if(p[i]==-1) {
		while(at<n&&used[at]) ++at;
		assert(at<n);
		if(at>q[i]) return false;
		p[i]=at,used[at]=true;
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&q[i]),--q[i];
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",p[i]+1); } puts("");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}