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
int a[MAXN];
bool skipped[MAXN];
int cnt[MAXN];



void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]),--a[i];
	REP(i,n) cnt[i]=0,skipped[i]=false; REP(i,n) ++cnt[a[i]];

	int at=0,ret=0;
	REP(i,n) if(cnt[i]==0) {
		while(true) {
			while(at<n&&cnt[a[at]]<=1) ++at; assert(at<n);
			if(a[at]<i&&!skipped[a[at]]) { skipped[a[at]]=true; ++at; continue; }
			++ret; --cnt[a[at]]; a[at]=i; ++cnt[a[at]]; break;
		}
	}
	printf("%d\n",ret);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}