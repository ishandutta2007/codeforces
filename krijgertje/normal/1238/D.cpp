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

const int MAXLEN=300000;

int slen;
char s[MAXLEN+1];

ll solve() {
	ll ret=(ll)slen*(slen+1)/2;
	ret-=slen;
	REP(i,slen-1) if(s[i]!=s[i+1]) --ret;
	for(int l=0,r=l;l<slen;l=r) {
		while(r<slen&&s[r]==s[l]) ++r;
		int cnt=r-l,times=cnt-1;
		if(l-1>=0) ret-=times;
		if(r<slen) ret-=times;
	}
	return ret;
}

void run() {
	scanf("%d",&slen);
	scanf("%s",s); assert(strlen(s)==slen);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}