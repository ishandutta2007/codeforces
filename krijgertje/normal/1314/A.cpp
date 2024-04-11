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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
struct Z { int val, cost; };
bool operator<(const Z& a, const Z& b) { return a.val < b.val; }


int n;
Z z[MAXN];

ll solve() {
	sort(z, z + n);
	int at = 0, cnt = 0;
	int curval = -1;
	priority_queue<ll> curcost; ll sumcost = 0;
	ll ret = 0;
	while (cnt > 0 || at < n) {
		if (cnt == 0) curval = z[at].val;
		while (at < n && z[at].val == curval) { ++cnt; curcost.push(z[at].cost); sumcost += z[at].cost; ++at; }
		ll remcost = curcost.top(); curcost.pop(); sumcost -= remcost; --cnt;
		//printf("curval=%d sumcost=%lld remcost=%lld cnt=%d\n", curval, sumcost, remcost, cnt);
		ret += sumcost; ++curval;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &z[i].val);
	REP(i, n) scanf("%d", &z[i].cost);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}