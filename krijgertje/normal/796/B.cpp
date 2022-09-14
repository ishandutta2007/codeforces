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
#include <random>
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

int n,nhole,nq;
bool hole[MAXN];

void run() {
	scanf("%d%d%d",&n,&nhole,&nq);
	REP(i,n) hole[i]=false;
	REP(i,nhole) { int x; scanf("%d",&x); --x; hole[x]=true; }
	int ret=0;
	REP(i,nq) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		if(!hole[ret]&&(ret==a||ret==b)) ret=a+b-ret;
	}
	printf("%d\n",ret+1);
}

int main() {
	run();
	return 0;
}