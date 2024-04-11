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
const int MAXDIG=10;

int n,mod;
int a[MAXN];

vector<int> have[MAXDIG+1];
vector<int> suff[MAXDIG+1];


void run() {
	scanf("%d%d",&n,&mod);
	REP(i,n) scanf("%d",&a[i]);

	ll sub=0;
	REP(i,n) {
		int x=a[i],orig=x%mod,cur=orig;
		REPE(k,MAXDIG) {
			have[k].PB(cur);
			cur=(ll)10*cur%mod;
			if(1<=x&&x<=9) { int want=(mod-orig)%mod; suff[k+1].PB(want); if(want==cur) ++sub; }
			x/=10;
		}
	}

	ll ret=-sub;
	REPE(k,MAXDIG) sort(have[k].begin(),have[k].end());
	REPE(k,MAXDIG) sort(suff[k].begin(),suff[k].end());
	REPE(k,MAXDIG) {
		int haveidx=0,suffidx=0;
		while(haveidx<SZ(have[k])&&suffidx<SZ(suff[k])) {
			int havecnt=0,suffcnt=0,val=min(have[k][haveidx],suff[k][suffidx]);
			while(haveidx<SZ(have[k])&&have[k][haveidx]==val) ++havecnt,++haveidx;
			while(suffidx<SZ(suff[k])&&suff[k][suffidx]==val) ++suffcnt,++suffidx;
			ret+=(ll)havecnt*suffcnt;
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}