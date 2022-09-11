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

int query(vector<int> a) {
	printf("?"); REPSZ(i,a) printf(" %d",a[i]); puts(""); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}

int solve() {
	int ret=0;
	vector<int> a; FORE(i,1,100) a.PB(i); int aval=query(a);
	vector<int> b; FORE(i,1,100) b.PB(i<<7); int bval=query(b);
	return ((aval>>7)<<7)+(bval&((1<<7)-1));
}

void run() {
	int ans=solve();
	printf("! %d\n",ans); fflush(stdout);
}

int main() {
	run();
	return 0;
}