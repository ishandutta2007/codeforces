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
const int MAXMOD=100000;

int n,need,mod;
int a[MAXN];
int cnt[MAXMOD];

int ret[MAXN],nret;


void run() {
	scanf("%d%d%d",&n,&need,&mod);
	REP(i,n) scanf("%d",&a[i]);

	REP(i,mod) cnt[i]=0; REP(i,n) ++cnt[a[i]%mod];
	REP(i,mod) if(cnt[i]>=need) {
		nret=0;
		REP(j,n) if(nret<need&&a[j]%mod==i) ret[nret++]=a[j];
		printf("Yes\n"); REP(j,nret) { if(j!=0) printf(" "); printf("%d",ret[j]); } puts(""); return;
	}
	printf("No\n");
}

int main() {
	run();
	return 0;
}