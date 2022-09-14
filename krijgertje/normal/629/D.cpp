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

int n;
map<ll,ll> cur;

void run() {
	scanf("%d",&n);
	cur.clear(); cur[0]=0;
	REP(i,n) {
		int r,h; scanf("%d%d",&r,&h); ll val=(ll)r*r*h;
		map<ll,ll>::iterator at=cur.lower_bound(val); --at;
		ll sum=at->second+val;
		++at;
		while(at!=cur.end()&&sum>=at->second) cur.erase(at++);
		cur[val]=sum;
	}
	map<ll,ll>::iterator ret=cur.end(); --ret; printf("%.9lf\n",ret->second*acos(-1));	
}

int main() {
	run();
	return 0;
}