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

const int MAXLEN=100000;

int want;
char ans[MAXLEN+1]; int anslen;

void solve() {
	int rem=want;
	vector<int> parts;
	while(rem>0) {
		int x=2; while((ll)x*(x+1)/2<=rem) ++x;
		rem-=x*(x-1)/2;
		parts.PB(x);
	}
	reverse(parts.begin(),parts.end());
	anslen=0;
	ans[anslen++]='1'; REPSZ(i,parts) { int cnt=parts[i]-(i==0?0:parts[i-1]); REP(j,cnt) ans[anslen++]='3'; ans[anslen++]='7'; } ans[anslen]='\0';
}

void run() {
	scanf("%d",&want);
	solve();
	printf("%s\n",ans);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}