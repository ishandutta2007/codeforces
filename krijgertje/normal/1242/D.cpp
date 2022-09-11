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
#include <chrono>
#include <chrono>
#include <random>
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

ll q; int k;

ll solve() {
	ll blocksz=(ll)k*k+1;
	ll blockidx=(q-1)/blocksz;
	vector<ll> path; path.PB(blockidx); while(path.back()!=0) { ll nxt=path.back()/k; path.PB(nxt); } reverse(path.begin(),path.end());
	vector<ll> skipped(SZ(path),-1LL);
	skipped[0]=(ll)k*(k+1)/2;
	FORSZ(i,1,path) {
		// (path[i-1]*k+b)*blocksz-b+k*(k+1)/2-[0..k] in (path[i]*blocksz,(path[i]+1)*blocksz]
		// (path[i-1]*k+b)*blocksz = path[i]*blocksz -> b = path[i]-path[i-1]*k
		int b=path[i]-path[i-1]*k;
		//printf("b=%d\n",b);
		// path[i-1]*blocksz+b*k+[1..k]>=skipped[i-1]
		// [1..k]>=skipped[i-1]-path[i-1]*blocksz-b*k
		int off=k-max(0LL,min((ll)k,skipped[i-1]-path[i-1]*blocksz-(ll)b*k-1));
		//printf("off=%d (%lld)\n",off,skipped[i-1]-path[i-1]*blocksz-(ll)b*k-1);
		//printf("off=%d\n",off);
		skipped[i]=(path[i-1]*k+b)*blocksz-b+(ll)k*(k+1)/2+off;
	}
	//printf("path:"); REPSZ(i,path) printf(" %lld",path[i]); puts("");
	//printf("skipped:"); REPSZ(i,path) printf(" %lld",skipped[i]); puts("");
	REPSZ(i,path) assert(skipped[i]>path[i]*blocksz&&skipped[i]<=(path[i]+1)*blocksz);
	if(q==skipped.back()) {
		if(SZ(path)==1) return k+1;
		int b=path[SZ(path)-1]-path[SZ(path)-2]*k;
		return (path[SZ(path)-2]*k+b+1)*(k+1);
	} else {
		ll blockpos=(q-1)%blocksz-(q>skipped.back()?1:0);
		return (blockidx*k+(blockpos/k))*(k+1)+(blockpos%k+1);
	}
	return -1;
}

void run() {
	scanf("%lld%d",&q,&k);
	printf("%lld\n",solve());
}

void stress() {
	int qlim=100000000;
	for(k=2;k<=2;++k) {
		vector<int> sums;
		int at=1,idx=0,pos=1;
		vector<int> ans(qlim+1,-1);
		while(at<=qlim) {
			int sum=0;
			REP(i,k) {
				if(idx<SZ(sums)&&sums[idx]==at) ++at,++idx;
				if(at<=qlim) ans[at]=pos;
				sum+=at,++at,++pos;
			}
			if(sum<=qlim) ans[sum]=pos;
			sums.PB(sum),++pos;
		}
		printf("#");
		for(q=1;q<=qlim;++q) {
			ll have=solve();
			ll want=ans[q];
			if(have==want) continue;
			printf("err have=%lld want=%lld\n",have,want);
			printf("%lld %d\n",q,k);
			break;
		}
	}
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	//stress();
	return 0;
}