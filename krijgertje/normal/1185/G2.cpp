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

const int MAXN=50;
const int MOD=1000000007;
const int MAXKIND=3;
const int MAXCAP=2500;
const ll MODUNDOOVERFLOW=(1ULL<<63)/MOD*MOD;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }

int n,cap;
int cost[MAXN],kind[MAXN];


int waysonekind[MAXKIND][MAXN+1][MAXCAP+1];
int cntkind[MAXKIND];

pair<int,int> o[MAXKIND];
int waystwokind[MAXN+1][MAXN+1][MAXCAP+1];

int waysthreekind[MAXN+1][MAXN+1][MAXN+1];

int dp[MAXN+1][MAXN+1][MAXN+1][3];
int dpsum[MAXN+1][MAXN+1][MAXN+1];
int fac[MAXN+1];


int solve() {
	memset(waysonekind,0,sizeof(waysonekind));
	REP(k,3) cntkind[k]=0,inc(waysonekind[k][0][0],1);
	REP(z,n) {
		int k=kind[z];
		for(int i=cntkind[k];i>=0;--i) REPE(j,cap-cost[z]) inc(waysonekind[k][i+1][j+cost[z]],waysonekind[k][i][j]);
		++cntkind[k];
	}
	//REP(k,3) REPE(i,cntkind[k]) REPE(x,cap) if(waysonekind[k][i][x]!=0) printf("kind %d: %d %d = %d\n",k+1,i,x,waysonekind[k][i][x]);
	
	REP(i,MAXKIND) o[i]=MP(cntkind[i],i); sort(o,o+MAXKIND);
	int a=o[0].second,b=o[1].second,c=o[2].second;
	//printf("a=%d b=%d c=%d\n",a+1,b+1,c+1);
	
	memset(waystwokind,0,sizeof(waystwokind));
	REPE(i,cntkind[a]) REPE(j,cntkind[b]) REPE(x,cap) {
		ll sum=0; REPE(y,x) { sum+=(ll)waysonekind[a][i][y]*waysonekind[b][j][x-y]; if(sum<0) sum-=MODUNDOOVERFLOW; } sum%=MOD; waystwokind[i][j][x]=sum;
	}

	memset(waysthreekind,0,sizeof(waysthreekind));
	REPE(i,cntkind[a]) REPE(j,cntkind[b]) REPE(k,cntkind[c]) {
		ll sum=0; REPE(x,cap) { sum+=(ll)waystwokind[i][j][x]*waysonekind[c][k][cap-x]%MOD; if(sum<0) sum-=MODUNDOOVERFLOW; } sum%=MOD; waysthreekind[i][j][k]=sum;
	}
	//REPE(i,cntkind[a]) REPE(j,cntkind[b]) REPE(k,cntkind[c]) if(waysthreekind[i][j][k]!=0) printf("%d %d %d = %d\n",i,j,k,waysthreekind[i][j][k]);

	memset(dp,0,sizeof(dp)); REP(k,3) if(cntkind[k]>=1) inc(dp[k==a?1:0][k==b?1:0][k==c?1:0][k],1);
	REPE(i,cntkind[a]) REPE(j,cntkind[b]) REPE(k,cntkind[c]) REP(z,3) {
		if(z!=a&&i+1<=cntkind[a]) inc(dp[i+1][j][k][a],dp[i][j][k][z]);
		if(z!=b&&j+1<=cntkind[b]) inc(dp[i][j+1][k][b],dp[i][j][k][z]);
		if(z!=c&&k+1<=cntkind[c]) inc(dp[i][j][k+1][c],dp[i][j][k][z]);
	}
	memset(dpsum,0,sizeof(dpsum));
	REPE(i,cntkind[a]) REPE(j,cntkind[b]) REPE(k,cntkind[c]) REP(z,3) inc(dpsum[i][j][k],dp[i][j][k][z]);
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)fac[i-1]*i%MOD;

	int ret=0;
	REPE(i,cntkind[a]) REPE(j,cntkind[b]) REPE(k,cntkind[c]) if(waysthreekind[i][j][k]!=0&&dpsum[i][j][k]!=0) {
		ret=(ret+(ll)waysthreekind[i][j][k]*dpsum[i][j][k]%MOD*fac[i]%MOD*fac[j]%MOD*fac[k])%MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&cap);
	REP(i,n) scanf("%d%d",&cost[i],&kind[i]),--kind[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}