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

const int MAXLEN=1000000;

char s[MAXLEN+1]; int slen;
char t[MAXLEN+1]; int tlen;
char ret[MAXLEN+1];

int need[26];
int have[26],rem;

bool ok(int x) {
	ll left=rem;
	REP(i,26) {
		ll cur=max(0LL,(ll)x*need[i]-have[i]);
		left-=cur; if(left<0) return false;
	}
	return true;
}

void run() {
	scanf("%s%s",s,t); slen=strlen(s); tlen=strlen(t);

	memset(need,0,sizeof(need)); REP(i,tlen) ++need[t[i]-'a'];
	memset(have,0,sizeof(have)); rem=0; REP(i,slen) if(s[i]=='?') ++rem; else ++have[s[i]-'a'];

	int l=0,h=slen/tlen+1;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(ok(m)) l=m; else h=m;
	}
	int x=l;
	int at=0; ret[slen]='\0';
	REP(i,slen) if(s[i]!='?') ret[i]=s[i]; else {
		while(at<26&&x*need[at]<=have[at]) ++at;
		if(at>=26) ret[i]='a'; else ret[i]='a'+at,++have[at];
	}
	printf("%s\n",ret);
}

int main() {
	run();
	return 0;
}