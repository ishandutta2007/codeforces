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

const int MAXN=300000;

int n,den,num;
int a[MAXN];

ll solve() {
	ll ret=0;
	REP(off,den) {
		ll lft=LLONG_MAX,sum=0;
		REP(i,n) {
			if(i%den==off) lft=min(lft,sum);
			sum+=a[i];
			if(i%den==off) sum-=num;
			if(lft!=LLONG_MAX) ret=max(ret,sum-lft);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&den,&num);
	REP(i,n) scanf("%d",&a[i]);
	printf("%lld\n",solve());

}

int main() {
	run();
	return 0;
}