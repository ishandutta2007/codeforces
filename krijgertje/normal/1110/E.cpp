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

int n;
ll a[MAXN];
ll b[MAXN];

ll adiff[MAXN-1];
ll bdiff[MAXN-1];

bool solve() {
	if(a[0]!=b[0]||a[n-1]!=b[n-1]) return false;
	REP(i,n-1) adiff[i]=a[i+1]-a[i]; sort(adiff,adiff+n-1);
	REP(i,n-1) bdiff[i]=b[i+1]-b[i]; sort(bdiff,bdiff+n-1);
	REP(i,n-1) if(adiff[i]!=bdiff[i]) return false;
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&a[i]);
	REP(i,n) scanf("%lld",&b[i]);
	printf("%s\n",solve()?"Yes":"No");
}

void research() {
	scanf("%d",&n); REP(i,n) scanf("%lld",&a[i]); REP(i,n) scanf("%lld",&b[i]);
	set<vector<ll>> seen; queue<vector<ll>> q;
	vector<ll> s(n); REP(i,n) s[i]=a[i]; q.push(s); seen.insert(s);
	vector<ll> t(n); REP(i,n) t[i]=b[i];
	vector<ll> mx=s;
	while(!q.empty()&&SZ(seen)<10000000) {
		vector<ll> at=q.front(); q.pop(); mx=max(mx,at);
		if(at==t) { printf("FOUND!\n"); break; }
		//printf("at:"); REPSZ(i,at) printf(" %lld",at[i]); puts("");
		if(at==s) { printf("dat:"); FORSZ(i,1,at) printf(" %lld",at[i]-at[i-1]); puts(""); }
		FORE(i,1,n-2) {
			vector<ll> to=at; to[i]=to[i-1]+to[i+1]-to[i];
			if(!seen.count(to)) q.push(to),seen.insert(to);
		}
	}
	printf("dmx:"); FORSZ(i,1,mx) printf(" %lld",mx[i]-mx[i-1]); puts("");
	printf("dt:"); FORSZ(i,1,t) printf(" %lld",t[i]-t[i-1]); puts("");
}

int main() {
	//research();
	run();
	return 0;
}