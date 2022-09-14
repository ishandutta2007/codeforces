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

int n,tburn,need;
int t[300];
bool have[601];

void run() {
	scanf("%d%d%d",&n,&tburn,&need);
	REP(i,n) scanf("%d",&t[i]); REP(i,n) t[i]+=tburn;
	memset(have,0,sizeof(have));
	int cur=0,at=0,ret=0;
	REP(i,n) {
		while(at<t[i]) { ++at; if(at>=tburn+1&&have[at-tburn-1]) --cur; }
		REP(j,tburn) {
			if(cur>=need||at<j+1) break;
			if(!have[at-1-j]) { have[at-1-j]=true; ++cur; ++ret; }
		}
		if(cur<need) { printf("-1\n"); return; }
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}