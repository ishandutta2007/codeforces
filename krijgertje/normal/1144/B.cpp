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

const int MAXN=2000;

int n;
int a[MAXN];

int even[MAXN],neven;
int odd[MAXN],nodd;

ll solve() {
	neven=nodd=0; REP(i,n) if(a[i]%2==0) even[neven++]=a[i]; else odd[nodd++]=a[i];
	sort(even,even+neven); sort(odd,odd+nodd);
	ll ret=LLONG_MAX;
	REP(fsteven,2) {
		int takeeven,takeodd;
		if(fsteven==1) {
			takeeven=min(neven,nodd+1);
			takeodd=min(nodd,neven);
		} else {
			takeeven=min(neven,nodd);
			takeodd=min(nodd,neven+1);
		}
		ll cur=0; REP(i,neven-takeeven) cur+=even[i]; REP(i,nodd-takeodd) cur+=odd[i];
		//printf("%d: takeeven=%d takeodd=%d -> %lld\n",fsteven,takeeven,takeodd,cur);
		ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}