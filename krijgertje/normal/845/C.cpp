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

const int MAXN=200000;

int n;
pair<int,int> x[MAXN];

int avail[2];

bool solve() {
	sort(x,x+n);
	avail[0]=avail[1]=0;
	REP(i,n) {
		int idx=-1;
		REP(j,2) if(x[i].first>=avail[j]) { idx=j; break; }
		if(idx==-1) return false;
		avail[idx]=x[i].second+1;
	}
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&x[i].first,&x[i].second);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}