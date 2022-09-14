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
const int MAXVALBIT=30;

int n,k,x;
int a[MAXN];

int cnt[MAXVALBIT+1];



void run() {
	scanf("%d%d%d",&n,&k,&x);
	REP(i,n) scanf("%d",&a[i]);

	REP(i,n) REPE(j,MAXVALBIT) if((a[i]>>j)&1) ++cnt[j];

	ll ret=0;
	REP(i,n) {
		ll me=a[i]; REP(j,k) me*=x;
		ll cur=me;
		REPE(j,MAXVALBIT) if(cnt[j]>((a[i]>>j)&1)?1:0) cur|=1LL<<j;
		if(cur>ret) ret=cur;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}