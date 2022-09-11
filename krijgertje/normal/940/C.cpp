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

const int MAXLEN=100000;

int slen,tlen;
char s[MAXLEN+1];
char t[MAXLEN+1];

void solve() {
	char mn=s[0]; FOR(i,1,slen) mn=min(mn,s[i]);
	char mx=s[0]; FOR(i,1,slen) mx=max(mx,s[i]);
	if(tlen>slen) { REP(j,tlen) t[j]=j<slen?s[j]:mn; t[tlen]='\0'; return; }
	for(int i=tlen-1;i>=0;--i) if(s[i]<mx) {
		char c=mx; REP(j,slen) if(s[j]>s[i]) c=min(c,s[j]);
		REP(j,tlen) t[j]=j<i?s[j]:j==i?c:mn; t[tlen]='\0'; return;
	}
	assert(false);
}

void run() {
	scanf("%d%d%s",&slen,&tlen,&s);
	solve();
	printf("%s\n",t);
}

int main() {
	run();
	return 0;
}