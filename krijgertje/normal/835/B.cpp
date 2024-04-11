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

int want;
char s[MAXLEN+1]; int len;

int cnt[10];

void run() {
	scanf("%d%s",&want,s); len=strlen(s);
	memset(cnt,0,sizeof(cnt)); REP(i,len) ++cnt[s[i]-'0'];
	int have=0; REP(i,10) have+=cnt[i]*i;
	int left=max(0,want-have);
	int ret=0; REP(i,9) { int each=9-i; int x=min((left+each-1)/each,cnt[i]); ret+=x; left=max(0,left-each*x); }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}