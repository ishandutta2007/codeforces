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

ll a,b;

vector<pair<ll,ll>> opt;

void run() {
	scanf("%lld%lld",&a,&b);

	opt.clear();
	for(ll x=1;x*x<=a;++x) if(a%x==0) opt.PB(MP(x,a/x));
	for(ll x=1;x*x<=b;++x) if(b%x==0) opt.PB(MP(x,b/x));
	sort(opt.begin(),opt.end());
	{ int nopt=0; REPSZ(i,opt) if(nopt==0||opt[i].second<opt[nopt-1].second) opt[nopt++]=opt[i]; opt.resize(nopt); }
	//printf("opt:"); REPSZ(i,opt) printf(" (%lld,%lld)",opt[i].first,opt[i].second);

	int at=0; ll c=a+b; ll ret=LLONG_MAX;
	for(ll x=1;x*x<=c;++x) if(c%x==0) {
		ll y=c/x;
		while(at<SZ(opt)&&opt[at].first<=x) ++at;
		if(at-1>=0&&opt[at-1].second<=y) { ret=min(ret,x+x+y+y); }
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}