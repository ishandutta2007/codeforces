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

const int MAXN=1000000;

int n;
int len[MAXN];

int cnt[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&len[i]);

	memset(cnt,0,sizeof(cnt));
	REP(i,n) { int fst=max(0,i-len[i]); ++cnt[fst],--cnt[i]; }
	REP(i,n-1) cnt[i+1]+=cnt[i];
	int ret=0; REP(i,n) if(cnt[i]==0) ++ret; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}