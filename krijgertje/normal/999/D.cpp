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

int n,mod;
int a[MAXN];

vector<int> pos[MAXN];

void run() {
	scanf("%d%d",&n,&mod); REP(i,n) scanf("%d",&a[i]);

	int want=n/mod;
	REP(i,n) pos[a[i]%mod].PB(i);
	int to=0;
	ll ret=0;
	REP(i,n) while(SZ(pos[i])>want) {
		while(to<i||SZ(pos[to%mod])>=want) ++to;
		int idx=pos[i].back(); pos[i].pop_back();
		int j=to%mod;
		ret+=(j-i+mod)%mod;
		a[idx]+=(j-i+mod)%mod;
		pos[j].PB(idx);
	}
	printf("%lld\n",ret); REP(i,n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");
}

int main() {
	run();
	return 0;
}