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

int n,k;
int a[MAXN];

int mn[MAXN];
bool ok[MAXN];
vector<pair<int,int> > fact;
int b[MAXN];

void calcfact() {
	int k=::k; fact.clear();
	for(int i=2;i*i<=k;++i) if(k%i==0) {
		int cnt=0; while(k%i==0) k/=i,++cnt; fact.PB(MP(i,cnt));
	}
	if(k!=1) fact.PB(MP(k,1));
}

void run() {
	scanf("%d%d",&n,&k); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) mn[i]=i,ok[i]=true;
	calcfact();
	REPSZ(i,fact) {
		int d=fact[i].first,need=fact[i].second;
		REP(j,n) { int z=a[j]; b[j]=0; while(z%d==0) ++b[j],z/=d; }
		int sum=0,skip=0,at=0;
		REP(j,n) {
			sum+=b[j];
			while(sum-skip-b[at]>=need) skip+=b[at++];
			if(sum-skip<need) ok[j]=false; else mn[j]=min(mn[j],at);
		}
	}
	ll ret=0; REP(j,n) if(ok[j]) ret+=mn[j]+1; printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}