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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;

int n;
int a[MAXN];

int solve() {
	sort(a,a+n); n=unique(a,a+n)-a;
	int ret=0;
	{ // use last one
		int cur=0; vector<int> have;
		for(int i=n-1;i>=0;--i) if(SZ(have)<3) {
			bool ok=true; REPSZ(j,have) if(have[j]%a[i]==0) ok=false;
			if(ok) cur+=a[i],have.PB(a[i]);
		}
		ret=max(ret,cur);
	}
	{ // use three divisors of last one, one of which is half, one of which is a third, one of which is a fifth
		int mx=a[n-1];
		bool havehalf=false,havethird=false,havefifth=false;
		REP(i,n) {
			if(2*a[i]==mx) havehalf=true;
			if(3*a[i]==mx) havethird=true;
			if(5*a[i]==mx) havefifth=true;
		}
		if(havehalf&&havethird&&havefifth) ret=max(ret,mx/2+mx/3+mx/5);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run();
	return 0;
}