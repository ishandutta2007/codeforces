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

const int MAXN=300000;

int n;
int p[MAXN];

ll ret;
multiset<int> d;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]);

	ret=0; d.clear();
	REP(i,n) {
		if(SZ(d)==0||p[i]<*d.begin()) {
			d.insert(p[i]);
		} else {
			ret+=p[i]-*d.begin();
			d.erase(d.begin());
			d.insert(p[i]);
			d.insert(p[i]);
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}