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
const int MOD=1000000007;

char s[MAXLEN+1]; int slen;
int conv(char c) { if(isdigit(c)) return c-'0'; if(isupper(c)) return c-'A'+10; if(islower(c)) return c-'a'+36; if(c=='-') return 62; if(c=='_') return 63; assert(false); return -1; }
int cnt[64];

void run() {
	scanf("%s",s); slen=strlen(s);
	int ret=1;
	memset(cnt,0,sizeof(cnt)); REP(i,64) REP(j,64) ++cnt[i&j];
	REP(i,slen) ret=(ll)ret*cnt[conv(s[i])]%MOD;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}