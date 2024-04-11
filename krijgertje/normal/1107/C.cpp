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

int n,ntimes;
int a[MAXN];
char s[MAXN+1];

ll solve() {
	ll ret=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&s[l]==s[r]) ++r;
		sort(a+l,a+r);
		int cnt=min(r-l,ntimes);
		REP(i,cnt) ret+=a[r-1-i];
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&ntimes);
	REP(i,n) scanf("%d",&a[i]);
	scanf("%s",s);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}