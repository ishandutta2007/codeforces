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

const int MAXN=100000;

int n,MOD;
int w[MAXN];

vector<int> mods;

int calcphi(int x) {
	int ret=1;
	for(int i=2;i*i<=x;++i) if(x%i==0) {
		x/=i; ret*=i-1;
		while(x%i==0) x/=i,ret*=i;
	}
	if(x!=1) ret*=x-1;
	return ret;
}
int pw(int x,int n,int mod) { int ret=1%mod; while(true) { if(n&1) ret=(ll)ret*x%mod; if((n>>=1)==0) return ret; x=(ll)x*x%mod; } }

void init() {
	mods.clear(); mods.PB(MOD); while(mods.back()!=1) mods.PB(calcphi(mods.back()));
	//printf("mods:"); REPSZ(i,mods) printf(" %d",mods[i]); puts("");
}
bool atleast(int l,int r,int want) {
	if(w[l]>=want) return true;
	if(l==r||w[l]==1) return false;
	ll have=1; int need=0; while(have<want) have*=w[l],++need;
	return atleast(l+1,r,need);
}
int rec(int l,int r,int idx) {
	if(mods[idx]==1) return 0;
	if(l==r) return w[l]%mods[idx];
	if(w[l]==1) return 1;
	int cur=rec(l+1,r,idx+1);
	if(atleast(l+1,r,mods[idx+1])) cur+=mods[idx+1];
	return pw(w[l],cur,mods[idx]);
}

int solve(int l,int r) {
	return rec(l,r,0);
}

void run() {
	scanf("%d%d",&n,&MOD); REP(i,n) scanf("%d",&w[i]);
	init();

	int nq; scanf("%d",&nq);
	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		int ans=solve(l,r);
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}