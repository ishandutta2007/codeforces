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


const int MAXN=200000;
const int MOD=998244353;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n;
char s[MAXN+1];

int solve() {
	int ret=0;
	int pref=1; while(pref<n&&s[pref]==s[0]) ++pref; assert(pref<n);
	int suff=1; while(suff<n&&s[n-suff-1]==s[n-1]) ++suff; assert(suff<n);
	// keep all
	inc(ret,1);
	// keep first+last
	if(s[0]==s[n-1]) inc(ret,(ll)pref*suff%MOD);
	// keep first
	inc(ret,pref);
	// keep last
	inc(ret,suff);
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}