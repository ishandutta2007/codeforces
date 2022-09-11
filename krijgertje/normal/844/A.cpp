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

const int MAXLEN=1000;

char s[MAXLEN+1]; int len,want;
int cnt[26];

void run() {
	scanf("%s%d",s,&want); len=strlen(s);
	if(want>len) { printf("impossible\n"); return; }
	REP(i,26) cnt[i]=0; REP(i,len) ++cnt[s[i]-'a'];
	int have=0; REP(i,26) if(cnt[i]>0) ++have;
	printf("%d\n",max(0,want-have));
}

int main() {
	run();
	return 0;
}