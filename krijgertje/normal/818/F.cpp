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

const int MAXN=2000000000;

vector<pair<ll,ll> > res;

void run() {
	res.clear();
	for(int x=1;SZ(res)==0||res.back().first<MAXN;++x) {
		res.PB(MP(x+(ll)x*(x-1)/2,(ll)x*(x-1)));
	}
	//REP(i,min(20,SZ(res))) printf("%lld %lld\n",res[i].first,res[i].second);
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int cur; scanf("%d",&cur);
		auto it=lower_bound(res.begin(),res.end(),MP((ll)cur,(ll)-1));
		ll ret=0;
		ret=max(ret,it->second-2*(it->first-cur));
		if(it!=res.begin()) {
			--it;
			ret=max(ret,it->second+(cur-it->first));
		}
		printf("%lld\n",ret);
	}
}

int main() {
	run();
	return 0;
}