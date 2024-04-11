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

int n,k;
int cnt[26];


void run() {
	scanf("%d%d",&n,&k);
	REP(i,26) cnt[i]=0;
	REP(i,n) { char c; scanf(" %c",&c); ++cnt[c-'A']; }
	sort(cnt,cnt+26); reverse(cnt,cnt+26);
	ll ret=0; int rem=k;
	REP(i,26) {
		int cur=min(cnt[i],rem);
		ret+=(ll)cur*cur;
		rem-=cur;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}