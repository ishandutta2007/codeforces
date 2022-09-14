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

const int MAXN=100;

int n,p,q;
char s[MAXN+1];

void run() {
	scanf("%d%d%d%s",&n,&p,&q,s);
	for(int i=0;i*p<=n;++i) if((n-i*p)%q==0) {
		int j=(n-i*p)/q,at=0;
		printf("%d\n",i+j);
		REP(k,i) { REP(x,p) printf("%c",s[at++]); puts(""); }
		REP(k,j) { REP(x,q) printf("%c",s[at++]); puts(""); }
		return;
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}