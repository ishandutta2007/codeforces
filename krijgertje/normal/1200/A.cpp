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

const int MAXN=100000;
const int NROOM=10;

int n;
char s[MAXN+1];
char ans[NROOM+1];

void solve() {
	REP(i,NROOM) ans[i]='0'; ans[NROOM]='\0';
	REP(i,n) {
		if(s[i]=='L') { int x=0; while(x<NROOM&&ans[x]=='1') ++x; assert(x<NROOM); ans[x]='1'; }
		if(s[i]=='R') { int x=NROOM-1; while(x>=0&&ans[x]=='1') --x; assert(x>=0); ans[x]='1'; }
		if(isdigit(s[i])) { int x=s[i]-'0'; assert(ans[x]=='1'); ans[x]='0'; }
	}
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	solve();
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}