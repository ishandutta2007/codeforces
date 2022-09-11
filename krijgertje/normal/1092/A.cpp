#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXALPH=26;
const int MAXLEN=100;

int len,nalph;

int cnt[MAXALPH];
char ans[MAXLEN+1];

void solve() {
	REP(i,nalph) cnt[i]=len/nalph+(i<len%nalph?1:0);
	int at=0; REP(i,nalph) REP(j,cnt[i]) ans[at++]='a'+i; ans[at]='\0';
}

void run() {
	scanf("%d%d",&len,&nalph);
	solve();
	printf("%s\n",ans);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}