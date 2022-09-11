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
const int MOD=1000000007;

int n;

int E[MAXN+1];

int pmn[MAXN+1];
int mu[MAXN+1];
int inv[MAXN+1];

int cnt[MAXN+1];


void calccnt(int lim) {
	FORE(i,1,lim) cnt[i]=0;
	FORE(i,1,lim) for(int j=i;j<=lim;j+=i) cnt[j]+=mu[i]*(lim/i);
	//printf("cnt:"); FORE(i,1,lim) printf(" %d",cnt[i]); puts("");
}

int solve() {
	memset(pmn,-1,sizeof(pmn));
	FORE(i,2,MAXN) if(pmn[i]==-1) for(int j=i;j<=MAXN;j+=i) if(pmn[j]==-1) pmn[j]=i;
	mu[1]=1; FORE(i,2,MAXN) { int p=pmn[i],j=i/pmn[i]; mu[i]=pmn[j]==p?0:-mu[j]; }
	//printf("mu:"); FORE(i,1,100) printf(" %d",mu[i]); puts("");
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;

	FORE(i,1,n) E[i]=0;
	FORE(d,1,n) {
		calccnt(n/d);
		if(d!=1) E[d]=((ll)(n+E[d])*inv[n-cnt[1]])%MOD;
		for(int i=d+d;i<=n;i+=d) E[i]=(E[i]+(ll)E[d]*cnt[i/d]%MOD)%MOD;
	}
	//printf("E:"); FORE(i,1,n) printf(" %d",E[i]); puts("");
	int ret=n; FORE(i,1,n) ret=(ret+E[i])%MOD; ret=(ll)ret*inv[n]%MOD; return ret;
}

void run() {
	scanf("%d",&n);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}