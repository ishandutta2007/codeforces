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

const int MAXN=1000;

int n,k1,k2;
int a[MAXN],b[MAXN];

int d[MAXN];

void run() {
	scanf("%d%d%d",&n,&k1,&k2); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);
	
	REP(i,n) d[i]=abs(b[i]-a[i]); sort(d,d+n); reverse(d,d+n);
	int rem=k1+k2;
	int cnt=1,val=d[0];
	while(rem>0&&val>0) {
		while(cnt<n&&d[cnt]==val) ++cnt;
		if(rem>=cnt) { rem-=cnt; --val; continue; }
		break;		
	}
	if(val==0) { printf("%d\n",rem%2); return; }
	ll ret=0;
	REP(i,rem) ret+=(ll)(val-1)*(val-1);
	REP(i,cnt-rem) ret+=(ll)val*val;
	FOR(i,cnt,n) ret+=(ll)d[i]*d[i];
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}