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

ll a,b;

ll f[100]; int nf;

void run() {
	scanf("%I64d%I64d",&a,&b);
	if(gcd(a,b)!=1) { printf("Impossible\n"); return; }

	//(a1,b1)+(a2,b2)=(a,b)

	nf=0;
	while(b!=0) { f[nf++]=a/b; a%=b; swap(a,b); }
	//printf("%d",f[0]); FOR(i,1,nf) printf("%c%lld",i==1?';':',',f[i]); puts("");

	REP(i,nf) if(f[i]!=0) printf("%I64d%c",f[i]-(i==nf-1?1:0),"AB"[i%2]); puts("");
}

int main() {
	run();
	return 0;
}