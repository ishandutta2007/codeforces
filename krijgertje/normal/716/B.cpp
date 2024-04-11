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

const int MAXLEN=50000;

char s[MAXLEN+1]; int len;
int cnt[26]; int nhave=0,nunknown=0;

void mod(char c,int by) {
	if(c=='?') { nunknown+=by; return; }
	int x=c-'A';
	bool had=cnt[x]>0; cnt[x]+=by;
	if(had&&cnt[x]==0) --nhave; if(!had&&cnt[x]>0) ++nhave;
}

void run() {
	scanf("%s",s); len=strlen(s);
	int at=0,to=0; nhave=0,nunknown=0; memset(cnt,0,sizeof(cnt));
	while(at<len) {
		while(to<len&&nhave+nunknown<26) mod(s[to++],+1);
		if(to-at<=26&&nhave+nunknown>=26) {
			REP(i,26) if(cnt[i]==0) FOR(j,at,to) if(s[j]=='?') { s[j]='A'+i; break; }
			REP(j,len) if(s[j]=='?') s[j]='A'; printf("%s\n",s); return;
		}
		mod(s[at++],-1);
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}