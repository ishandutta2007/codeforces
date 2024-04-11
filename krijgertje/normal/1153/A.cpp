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

const int MAXN=100;

int n,t;
int fst[MAXN],dst[MAXN];

int solve() {
	int ret=-1; int best=INT_MAX;
	REP(i,n) {
		// fst[i]+x*dst[i]>=t
		int x;
		if(fst[i]>=t) x=0; else x=(t-fst[i]+dst[i]-1)/dst[i];
		int cur=fst[i]+x*dst[i]; if(cur<best) best=cur,ret=i;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&t);
	REP(i,n) scanf("%d%d",&fst[i],&dst[i]);
	printf("%d\n",solve()+1);
}

int main() {
	run();
	return 0;
}