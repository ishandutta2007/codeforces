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

int n,m,p;

bool isprime(int x) { if(x<2) return false; for(int i=2;i*i<=x;++i) if(x%i==0) return false; return true; }

void run() {
	scanf("%d%d",&n,&m);
	p=n-1; while(!isprime(p)) ++p;
	printf("%d %d\n",p,p);
	REP(i,n-1) printf("%d %d %d\n",i+1,i+2,i==0?p-(n-2):1);
	int rem=m-(n-1);
	REP(i,n) FOR(j,i+2,n) { if(rem==0) break; printf("%d %d %d\n",i+1,j+1,1000000000); --rem; }
}

int main() {
	run();
	return 0;
}