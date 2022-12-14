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

int a,b;
ll l,r;

int solve() {
	int per=a+b,overlap=max(0,a-b);
	int skip=l%per; ll rem=r-l+1;
	int a1=min(rem,(ll)max(0,per-skip-b)); rem-=a1; int b1=min(rem,(ll)min(b,per-skip)); rem-=b1; int a2=min((ll)a,rem); rem-=a2; int b2=min((ll)b,rem); rem-=b2; int a3=min((ll)a,rem); rem-=a3;
	int a1h=min(overlap,a1),a1l=a1-a1h; int a2l=min(a2,a-overlap),a2h=a2-a2l; int a3l=min(a3,a-overlap),a3h=a3-a3l;
	if(b1==0) return a1;
	if(b2==0) {
		if(a1l==0) return max(1,a1)+a2;
		if(a2h==0) return min(a,a1+a2);
		return min(a+overlap,a1h+a2);
	} else {
		return a+max(1,min(overlap,a1h+a3h));
	}
}

void run() {
	scanf("%d%d%lld%lld",&a,&b,&l,&r); --l,--r;
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}