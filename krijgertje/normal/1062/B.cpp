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

vector<pair<int,int>> factorize(int n) {
	vector<pair<int,int>> ret;
	for(int i=2;(ll)i*i<=n;++i) if(n%i==0) {
		int cnt=0; while(n%i==0) ++cnt,n/=i; ret.PB(MP(i,cnt));
	}
	if(n!=1) ret.PB(MP(n,1));
	return ret;
}

int n;

pair<int,int> solve() {
	vector<pair<int,int>> f=factorize(n);
	if(SZ(f)==0) return MP(1,0);
	int mx=INT_MIN; REPSZ(i,f) mx=max(mx,f[i].second);
	int ret=0,want=1; while(want<mx) want*=2,++ret;
	bool allsame=true; REPSZ(i,f) if(f[i].second!=want) allsame=false; if(!allsame) ++ret;
	int prod=1; REPSZ(i,f) prod*=f[i].first;
	return MP(prod,ret);
}

void run() {
	scanf("%d",&n);
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.first,ans.second);
}

int main() {
	run();
	return 0;
}