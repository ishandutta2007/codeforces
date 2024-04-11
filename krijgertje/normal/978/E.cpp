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

const int MAXN=1000;

int n,cap;
int a[MAXN];
int asum[MAXN+1];

void run() {
	scanf("%d%d",&n,&cap); REP(i,n) scanf("%d",&a[i]);
	
	// 0<=s+asum[i]<=cap -> s>=-asum[i] en s<=cap-asum[i]
	asum[0]=0; REP(i,n) asum[i+1]=asum[i]+a[i];
	int l=0,h=cap; FORE(i,1,n) l=max(l,-asum[i]),h=min(h,cap-asum[i]);
	int ans=l<=h?h-l+1:0; printf("%d\n",ans);
}

int main() {
	run();
	return 0;
}