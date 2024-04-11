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

const int MOD=1000000007;
const int INV2=(MOD+1)/2;

int calc(ll cnt) {
	int ret=0;
	vector<ll> used(2); used[0]=1,used[1]=0;
	int at=1; ll len=1; ll rem=cnt;
	while(rem>0) {
		ll cur=min(rem,len); assert(cur>=1);
		ll fst=used[at],lst=used[at]+cur-1;
		int sum=((fst+lst)%MOD)*((lst-fst+1)%MOD)%MOD*INV2%MOD;
		sum=(ll)2*sum%MOD; if(at==1) sum=(sum+lst-fst+1)%MOD; ret=(ret+sum)%MOD;
		used[at]+=cur; rem-=cur; len*=2; at=1-at;
	}
	return ret;
}

ll l,h;

int solve() {
	return (calc(h)+MOD-calc(l-1))%MOD;
}

void run() {
	scanf("%lld%lld",&l,&h);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}