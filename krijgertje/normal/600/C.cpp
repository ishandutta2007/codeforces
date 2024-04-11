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

const int MAXLEN=200000;

char s[MAXLEN+1]; int slen;
int cnt[26];


void run() {
	scanf("%s",s); slen=strlen(s);
	REP(i,26) cnt[i]=0; REP(i,slen) ++cnt[s[i]-'a'];
	int nodd=0; REP(i,26) if(cnt[i]%2!=0) ++nodd;
	for(int lft=nodd/2,i=0;i<26&&lft>0;++i) if(cnt[i]%2!=0) ++cnt[i],--lft;
	for(int lft=nodd/2,i=25;i>=0&&lft>0;--i) if(cnt[i]%2!=0) --cnt[i],--lft;
	REP(i,26) REP(j,cnt[i]/2) printf("%c",'a'+i);
	REP(i,26) if(cnt[i]%2!=0) printf("%c",'a'+i);
	for(int i=25;i>=0;--i) REP(j,cnt[i]/2) printf("%c",'a'+i);
	puts("");
}

int main() {
	run();
	return 0;
}