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

const int MAXN=200000;

int n; ll t;
ll a[MAXN];
int x[MAXN];

int cnt[MAXN+1];
ll b[MAXN];


bool solve() {
	REP(i,n-1) if(x[i]>x[i+1]) return false;
	REP(i,n) if(x[i]<i) return false;

	REPE(i,n) cnt[i]=0;
	REP(i,n) ++cnt[i],--cnt[x[i]]; 
	REP(i,n) cnt[i+1]+=cnt[i];
	REP(i,n) b[i]=(cnt[i]==0?a[i]:a[i+1])+t;
	FOR(i,1,n) if(b[i]<=b[i-1]) b[i]=b[i-1]+1;
	REP(i,n-1) if(cnt[i]==0&&b[i]>=a[i+1]+t) return false;
	REP(i,n) if(cnt[x[i]]>0) return false;
	return true;
}

void run() {
	scanf("%d%lld",&n,&t);
	REP(i,n) scanf("%lld",&a[i]);
	REP(i,n) scanf("%d",&x[i]),--x[i];
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REP(i,n) { if(i!=0) printf(" "); printf("%lld",b[i]); } puts("");
}

int main() {
	run();
	return 0;
}