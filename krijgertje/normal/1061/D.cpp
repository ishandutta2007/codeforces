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
const int MOD=1000000007;
struct Seg { int l,r; };
bool operator<(const Seg &a,const Seg &b) { return a.l<b.l; }

int n,fixedcost,varcost;
Seg seg[MAXN];

multiset<int> avail;

int solve() {
	sort(seg,seg+n);
	avail.clear();
	int ret=0;
	REP(i,n) {
		// find last element in avail < seg[i].l
		auto it=avail.lower_bound(seg[i].l);
		ll bestcost=fixedcost;
		if(it!=avail.begin()) {
			it=prev(it);
			ll keepcost=(ll)(seg[i].l-*it)*varcost;
			if(keepcost<=bestcost) {
				bestcost=keepcost;
				avail.erase(it);
			}
		}
		ll extracost=(ll)(seg[i].r-seg[i].l)*varcost;
		ret=(ret+bestcost+extracost)%MOD;
		avail.insert(seg[i].r);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&fixedcost,&varcost);
	REP(i,n) scanf("%d%d",&seg[i].l,&seg[i].r);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}