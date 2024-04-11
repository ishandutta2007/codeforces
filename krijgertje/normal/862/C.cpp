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

int n,want;

int ret[MAXN],nret;

void run() {
	scanf("%d%d",&n,&want);
	nret=0; int have=0;
	if(n==2&&want==0) { printf("NO\n"); return; }
	if(n>=2) {
		ret[nret++]=1<<18; have^=1<<18;
		REP(i,n-2) { int cur=(1<<17)-i-1; ret[nret++]=cur; have^=cur; }
		if((have^want)==1<<18) { ret[0]^=1<<17; ret[1]^=1<<17; }
	}
	ret[nret++]=want^have;
	sort(ret,ret+nret);
	printf("YES\n"); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}