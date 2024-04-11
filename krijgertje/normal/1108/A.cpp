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

int a,b,c,d;

pair<int,int> solve() {
	int l=a,r=c;
	if(l==r&&l!=b) ++l;
	if(l==r&&r!=d) ++r;
	assert(l!=r);
	return MP(l,r);
}

void run() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	pair<int,int> ans=solve();
	printf("%d %d\n",ans.first,ans.second);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}