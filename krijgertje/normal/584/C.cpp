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

int n,want; bool wantt;
char s[MAXN+1],t[MAXN+1];

char getdiff(char a,char b) { char ret='a'; while(ret==a||ret==b) ++ret; return ret; }

void run() {
	scanf("%d%d%s%s",&n,&want,s,t); wantt=false;
	int nsame=0,ndiff=0;
	REP(i,n) if(s[i]==t[i]) ++nsame; else ++ndiff;
	if(2*want-(wantt?1:0)<ndiff) { printf("-1\n"); return; }
	REP(i,n) {
		if(s[i]==t[i]) {
			--nsame;
			if(2*want-(wantt?1:0)-2<ndiff) printf("%c",s[i]); else printf("%c",getdiff(s[i],t[i])),--want;
		} else {
			--ndiff;
			if(2*want-(wantt?1:0)-2<ndiff) printf("%c",wantt?s[i]:t[i]),want-=wantt?1:0,wantt=!wantt; else printf("%c",getdiff(s[i],t[i])),--want;
		}
	}
	puts("");
}

int main() {
	run();
	return 0;
}