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

typedef struct X { int val,money; } X;
bool operator<(const X &a,const X &b) { return a.money<b.money; }

int n,maxdiff;
X x[MAXN];

void run() {
	scanf("%d%d",&n,&maxdiff); maxdiff--;
	REP(i,n) scanf("%d%d",&x[i].money,&x[i].val);
	sort(x,x+n);

	int a=0,b=0;
	ll ret=0,cur=0;
	while(a<n) {
		while(b<n&&x[b].money<=x[a].money+maxdiff) cur+=x[b++].val;
		if(cur>ret) ret=cur;
		cur-=x[a++].val;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}