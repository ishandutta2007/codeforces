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

const int MAXN=100000;

int n;
int x[MAXN];

ll choose(ll n,int cnt) {
	ll ret=1;
	REP(i,cnt) ret=ret*(n-i)/(i+1);
	return ret;
}

ll solve() {
	int a=-1,acnt=0; REP(i,n) if(a==-1||x[i]<a) a=x[i],acnt=1; else if(x[i]==a) ++acnt;
	int b=-1,bcnt=0; REP(i,n) if(x[i]!=a&&(b==-1||x[i]<b)) b=x[i],bcnt=1; else if(x[i]==b) ++bcnt;
	int c=-1,ccnt=0; REP(i,n) if(x[i]!=a&&x[i]!=b&&(c==-1||x[i]<c)) c=x[i],ccnt=1; else if(x[i]==c) ++ccnt;
	int need=3;
	if(a!=-1&&acnt>=need) return choose(acnt,need); else need-=acnt;
	if(b!=-1&&bcnt>=need) return choose(bcnt,need); else need-=bcnt;
	if(c!=-1&&ccnt>=need) return choose(ccnt,need); else need-=ccnt;
	assert(false); return -1;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}