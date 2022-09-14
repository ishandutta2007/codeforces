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

const int MOD=1000000007;

ll n,k;

/*const int MAXN=100;
const int MAXK=100;
int f[MAXN+1];
int g[MAXN+1];
int F[MAXK+1][MAXN+1]; */

ll calc(ll n,ll k) {
	if(k==0) return n%MOD;
	if(n==1) return 1;
	ll res=1;
	for(ll i=2;i*i<=n;++i) if(n%i==0) {
		ll p=i; n/=p; int a=1; while(n%p==0) n/=p,++a,res*=p; res*=p-1;
	}
	if(n!=1) res*=n-1;
	return calc(res,k-1);
}

void run() {
	scanf("%lld%lld",&n,&k);
	/*f[1]=1; FORE(i,2,MAXN) { f[i]=0; FORE(x,1,i-1) if(gcd(x,i-x)==1) ++f[i]; }
	FORE(i,1,MAXN) { g[i]=0; FORE(j,1,i) if(i%j==0) g[i]+=f[i/j]; }
	FORE(i,1,MAXN) F[1][i]=f[g[i]];
	FORE(i,2,MAXK) FORE(j,1,MAXN) F[i][j]=i%2==0?g[F[i-1][j]]:f[F[i-1][j]];
	FORE(i,1,MAXN) printf("%d: f=%d g=%d\n",i,f[i],g[i]);
	FORE(i,1,MAXK) { printf("k=%d:",i); FORE(j,1,MAXN) printf(" %d",F[i][j]); puts(""); } */

	printf("%lld\n",calc(n,(k+1)/2));
}

int main() {
	run();
	return 0;
}