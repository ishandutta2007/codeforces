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

const int MAXN=100;

int n;
char s[MAXN+1];

vector<string> ans;

void solve() {
	int nzero=0,none=0; REP(i,n) if(s[i]=='0') ++nzero; else if(s[i]=='1') ++none;
	ans.clear();
	if(nzero!=none) { ans.PB(s); return; }
	ans.PB(string(s,s+n-1)); ans.PB(string(1,s[n-1]));
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	solve();
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) { if(i!=0) printf(" "); printf("%s",ans[i].c_str()); } puts("");
}

int main() {
	run();
	return 0;
}