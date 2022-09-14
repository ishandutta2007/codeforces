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

int n,nq;
int a[MAXN];
int nxt[MAXN];

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&a[i]);
	for(int i=n-1;i>=0;--i) nxt[i]=i==n-1?-1:a[i+1]!=a[i]?i+1:nxt[i+1];
	REP(i,nq) {
		int l,r,x; scanf("%d%d%d",&l,&r,&x); --l,--r;
		printf("%d\n",a[l]!=x?l+1:nxt[l]!=-1&&nxt[l]<=r?nxt[l]+1:-1);
	}
}

int main() {
	run();
	return 0;
}