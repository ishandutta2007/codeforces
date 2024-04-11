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

const int MAXN=200000;
const int MOD=1000000007;

int n,want;
int l[MAXN],r[MAXN];
int x[2*MAXN],nx;
int cnt[2*MAXN+1];

int fac[MAXN+1];
int inv[MAXN+1];
int ifac[MAXN+1];

int choose(int n,int k) {
	if(k<0||k>n) return 0;
	return (ll)fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

void run() {
	scanf("%d%d",&n,&want);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);
	nx=0; REP(i,n) x[nx++]=l[i],x[nx++]=r[i]+1;
	sort(x,x+nx); nx=unique(x,x+nx)-x;
	REP(i,n) l[i]=lower_bound(x,x+nx,l[i])-x,r[i]=lower_bound(x,x+nx,r[i]+1)-x;
	memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[l[i]],--cnt[r[i]]; REP(i,nx) cnt[i+1]+=cnt[i];
	
	fac[0]=1; FORE(i,1,n) fac[i]=(ll)i*fac[i-1]%MOD;
	inv[1]=1; FORE(i,2,n) inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	ifac[0]=1; FORE(i,1,n) ifac[i]=(ll)inv[i]*ifac[i-1]%MOD;

	int ret=0;
	REP(i,nx-1) {
		int cur=(ll)(x[i+1]-x[i])*choose(cnt[i],want)%MOD;
		if((ret+=cur)>=MOD) ret-=MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}