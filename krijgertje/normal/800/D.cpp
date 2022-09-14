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

const int MAXN=1000000;
const int MAXVAL=999999;
const int MAXDIG=6;
const int p[]={1,10,100,1000,10000,100000};
const int MOD=1000000007;
const int DIV2=(MOD+1)/2;

int n;
int cnt[MAXVAL+1];
int sum1[MAXVAL+1];
int sum2[MAXVAL+1];
int sum3[MAXVAL+1];
int p2[MAXN+1];
int F[MAXVAL+1];
int G[MAXVAL+1];

void run() {
	scanf("%d",&n); memset(cnt,0,sizeof(cnt)); REP(i,n) { int x; scanf("%d",&x); ++cnt[x]; }
	p2[0]=1; REP(i,n) p2[i+1]=2*p2[i]%MOD;
	REPE(i,MAXVAL) sum1[i]=(ll)cnt[i]*i%MOD;
	REP(k,MAXDIG) for(int i=MAXVAL;i>=0;--i) if(i/p[k]%10!=9) sum1[i]=(sum1[i]+sum1[i+p[k]])%MOD;
	REPE(i,MAXVAL) sum2[i]=(ll)cnt[i]*i%MOD*i%MOD;
	REP(k,MAXDIG) for(int i=MAXVAL;i>=0;--i) if(i/p[k]%10!=9) sum2[i]=(sum2[i]+sum2[i+p[k]])%MOD;
	REPE(i,MAXVAL) sum3[i]=cnt[i]%MOD;
	REP(k,MAXDIG) for(int i=MAXVAL;i>=0;--i) if(i/p[k]%10!=9) sum3[i]=(sum3[i]+sum3[i+p[k]])%MOD;

	REPE(i,MAXVAL) { F[i]=((ll)sum1[i]*sum1[i]+sum2[i])%MOD; if(sum3[i]==1) F[i]=(ll)F[i]*DIV2%MOD; if(sum3[i]>=2) F[i]=(ll)F[i]*p2[sum3[i]-2]%MOD; }
	REPE(i,MAXVAL) G[i]=0;
	REPE(i,MAXVAL) REP(j,1<<MAXDIG) {
		int cnt=0,cur=i; bool ok=true; REP(k,MAXDIG) if(j&(1<<k)) { ++cnt; if(i/p[k]%10==9) ok=false; else cur+=p[k]; } if(!ok) continue;
		//printf("%d %x -> %d %d (%d)\n",i,j,cur,cnt,F[cur]);
		if(cnt%2==0) G[i]=(G[i]+F[cur])%MOD; else G[i]=(G[i]+MOD-F[cur])%MOD;
	}
	//REPE(i,MAXVAL) if(sum1[i]>0||sum2[i]>0) printf("%2d: %d %d %d %d\n",i,sum1[i],sum2[i],F[i],G[i]);
	//REPE(i,MAXVAL) if(G[i]>0) printf("%d: %d\n",i,G[i]);
	ll ret=0; REPE(i,MAXVAL) ret^=(ll)i*G[i]; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}