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

const int MAXN=100000;
const int MOD=998244353;
const int MAXDIG=10;

int n;
int a[MAXN];

vector<int> d[MAXN];

int cnt[MAXDIG+1];
int p10[2*MAXDIG+1];

int solve() {
	REP(i,n) { int x=a[i]; d[i].clear(); while(x!=0) d[i].PB(x%10),x/=10; }
	memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[SZ(d[i])];
	p10[0]=1; FORE(i,1,2*MAXDIG) p10[i]=(ll)p10[i-1]*10%MOD;
	int ret=0;
	REP(i,n) REPE(jlen,MAXDIG) {
		int mlt=cnt[jlen]; if(mlt==0) continue;
		REPSZ(k,d[i]) {
			int fstidx=k+min(k+1,jlen);
			int sndidx=k+min(k,jlen);
			ret=(ret+(ll)d[i][k]*mlt%MOD*(p10[fstidx]+p10[sndidx]))%MOD;
		}
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}