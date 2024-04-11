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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

const int MOD=1000000007;
const int MAXN=100000;
int nq;

bool isprime[MAXN+1];
int primes[MAXN+1],nprimes;
int somep[MAXN+1];
int nxt[MAXN+1];

int inv[MAXN+1];
int fact[MAXN+1],invfact[MAXN+1];

int choose(int n,int k) {
	int ret=(ll)fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
//	printf("(%d,%d)=%d\n",n,k,ret);
	return ret;
}

int calc(int n,int f,int at) {
	if(n<f) return 0;
	int ret=choose(n-f+f-1,f-1);
	for(;at!=1;at=nxt[at]) { ret-=calc(n/somep[at],f,nxt[at]); if(ret<0) ret+=MOD; }
	//for(int i=at;i<nprimes&&primes[i]<=n;++i) if(n%primes[i]==0) { ret-=calc(n/primes[i],f,i+1); if(ret<0) ret+=MOD; }
	return ret;
}

void run() {
	scanf("%d",&nq);
	REP(i,nq) {
		int n,f;
		scanf("%d%d",&n,&f);
		int ret=calc(n,f,n);
		printf("%d\n",ret);
	}
}

void precalc() {
	isprime[0]=isprime[1]=false; FORE(i,2,MAXN) isprime[i]=true;
	FORE(i,2,MAXN) if(isprime[i]) {
		somep[i]=i; nxt[i]=1;
		for(int j=i+i;j<=MAXN;j+=i) { isprime[j]=false; somep[j]=i; int k=j/i; nxt[j]=somep[k]==i?nxt[k]:k; }
	}
	nprimes=0; FORE(i,2,MAXN) if(isprime[i]) primes[nprimes++]=i;
	inv[1]=1; FORE(i,2,MAXN) inv[i]=(MOD-(MOD/i)*(ll)inv[MOD%i]%MOD)%MOD;
	fact[0]=1; FORE(i,1,MAXN) fact[i]=(ll)fact[i-1]*i%MOD;
	invfact[0]=1; FORE(i,1,MAXN) invfact[i]=(ll)invfact[i-1]*inv[i]%MOD;
}

int main() {
	precalc();
	run();
	return 0;
}