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

const int MAXN=1000;

int n;
int a[MAXN];

vector<int> opt;

pair<int,int> solve() {
	sort(a,a+n);
	opt.clear(); REP(i,n) FORE(x,a[i]-1,a[i]+1) if(x>=1) opt.PB(x); sort(opt.begin(),opt.end()); opt.erase(unique(opt.begin(),opt.end()),opt.end());
	pair<int,int> ret=MP(INT_MAX,-1);
	REPSZ(i,opt) {
		int cur=0;
		REP(j,n) { int diff=abs(a[j]-opt[i]); cur+=max(0,diff-1); }
		if(cur<ret.first) ret=MP(cur,opt[i]);
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.second,ans.first);
}

int main() {
	run();
	return 0;
}