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

const int MAXN=1000000;

int n,A,B;
int ret[MAXN],nret=0;

void run() {
	scanf("%d%d%d",&n,&A,&B);
	for(int i=0;i*A<=n;++i) if((n-i*A)%B==0) {
		int j=(n-i*A)/B;
		nret=0;
		REP(ii,i) { REP(a,A) ret[nret+a]=nret+(a+1)%A; nret+=A; }
		REP(jj,j) { REP(b,B) ret[nret+b]=nret+(b+1)%B; nret+=B; }
		REP(k,nret) { if(k!=0) printf(" "); printf("%d",ret[k]+1); } puts("");
		return;
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}