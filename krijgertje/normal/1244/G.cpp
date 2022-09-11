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

const int MAXN=1000000;

int n; ll lim;
ll anssum;
int ans[MAXN][2];

int seq[MAXN];
int cnt[MAXN+1];
int seen[MAXN+1];

bool solve() {
	REP(i,n) seq[i]=n-i;
	ll cursum=0; REP(i,n) cursum+=seq[i]; if(cursum>lim) return false;
	REPE(i,n) cnt[i]=0; REP(i,n) ++cnt[seq[i]];
	int at=n;
	REP(i,n) {
		while(at>seq[i]&&cnt[at]>=2) --at;
		if(at>seq[i]) { int delta=min(lim-cursum,(ll)at-seq[i]); --cnt[seq[i]]; seq[i]+=delta; cursum+=delta; ++cnt[seq[i]]; }
	}
	anssum=cursum;
	at=1;
	REPE(i,n) seen[i]=0;
	for(int i=n-1;i>=0;--i) {
		while(at<seq[i]&&cnt[at]>=2) ++at;
		assert(at<=seq[i]&&cnt[at]<2);
		++cnt[at];
		int a=seq[i],b=at;
		if((seen[a]&1)!=0||(seen[b]&2)!=0) swap(a,b);
		if((seen[a]&1)!=0||(seen[b]&2)!=0) assert(false);
		ans[i][0]=a,ans[i][1]=b,seen[a]|=1,seen[b]|=2;
	}
	return true;
}

void run() {
	scanf("%d%lld",&n,&lim);
	if(!solve()) { printf("-1\n"); return; }
	printf("%lld\n",anssum);
	REP(j,2) { REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i][j]); } puts(""); }
}

void stress() {
	for(n=1;n<=1000;++n) { for(lim=1;lim<=(ll)n*n;++lim) solve(); printf("done %d\n",n); }
}

int main() {
	run();
	//stress();
	return 0;
}