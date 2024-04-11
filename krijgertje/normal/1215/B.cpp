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

const int MAXN=200000;

int n;
int a[MAXN];

pair<ll,ll> solve() {
	ll npos=0,nneg=0; pair<ll,ll> ret=MP(0LL,0LL);
	REP(i,n) {
		if(a[i]>0) ++npos; else swap(npos,nneg),++nneg;
		ret.first+=nneg; ret.second+=npos;
	}
	return ret;
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	pair<ll,ll> ans=solve();
	printf("%lld %lld\n",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}