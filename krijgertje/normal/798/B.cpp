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

const int MAXN=50;
const int MAXLEN=50;

int n,len;
char s[MAXN][MAXLEN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",s[i]); len=strlen(s[0]);
	int ret=INT_MAX;
	REP(a,len) {
		int cur=a;
		FOR(i,1,n) {
			int low=INT_MAX;
			REP(b,len) {
				int now=b; bool ok=true;
				REP(j,len) if(s[0][(a+j)%len]!=s[i][(b+j)%len]) { ok=false; break; }
				if(ok&&now<low) low=now;
			}
			if(low==INT_MAX||cur==INT_MAX) cur=INT_MAX; else cur+=low;
		}
		if(cur<ret) ret=cur;
	}
	printf("%d\n",ret==INT_MAX?-1:ret);
}

int main() {
	run();
	return 0;
}