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

const int MOD=840;

ll want;
ll cnt[9];

vector<bool> can;
int small[9];

ll solve() {
	ll big=0;
	FORE(i,1,8) {
		int x=MOD/i;
		if(cnt[i]<x) { small[i]=cnt[i]; continue; }
		ll cbig=cnt[i]/x-1;
		big+=cbig; small[i]=cnt[i]-cbig*x;
	}
	int sum=0; FORE(i,1,8) sum+=i*small[i];
	can=vector<bool>(sum+1,false); can[0]=true;
	FORE(i,1,8) {
		REP(off,i) {
			int times=0;
			for(int k=off;k<SZ(can);k+=i) {
				if(can[k]) times=small[i]+1;
				if(times>0) can[k]=true,--times;
			}
		}
	}
	//printf("can: "); REPSZ(i,can) printf("%c",can[i]?'V':'x'); puts("");
	ll ret=0;
	REPSZ(k,can) if(k<=want&&can[k]) {
		ll cur=k+min((want-k)/MOD,big)*MOD;
		ret=max(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%lld",&want);
	FORE(i,1,8) scanf("%lld",&cnt[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}