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
const int MAXBIT=13;

int n,want;
int opt[2<<MAXBIT],nopt;
int cnt[2<<MAXBIT];


void run() {
	scanf("%d%d",&n,&want); memset(cnt,0,sizeof(cnt)); REP(i,n) { int a; scanf("%d",&a); ++cnt[a]; }
	REP(i,2<<MAXBIT) { int cur=0; REPE(j,MAXBIT) if(i&(1<<j)) ++cur; if(cur==want) opt[nopt++]=i; }
	//REP(j,nopt) printf("%d ",opt[j]); puts("");
	ll ret=0;
	REP(i,2<<MAXBIT) REP(j,nopt) { int ii=i^opt[j]; if(i==ii) ret+=(ll)cnt[i]*(cnt[i]-1); else ret+=(ll)cnt[i]*cnt[ii]; }
	assert(ret%2==0);
	printf("%lld\n",ret/2);
}

int main() {
	run();
	return 0;
}