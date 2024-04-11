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
#include <bitset>
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

const int MAXN=100000;
struct Z { int a,b,c; };
bool operator<(const Z &p,const Z &q) { return p.c>q.c; }

int n;
Z z[MAXN];

ll solve() {
	REP(i,n) z[i].c=z[i].a-z[i].b;
	sort(z,z+n);
	ll ret=0; REP(i,n) ret+=(ll)z[i].a*i+(ll)z[i].b*(n-i-1); return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&z[i].a,&z[i].b);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}