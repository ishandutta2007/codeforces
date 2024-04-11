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

const int MAXN=70000;
const int LEN=9;

int n;
int val[MAXN];

int p10[LEN+1];

map<int,int> cnt[LEN+1];

bool ok(int cur,int len) {
	return cnt[len][cur]==1;
}

void solve(int want) {
	FORE(len,1,9) REPE(off,LEN-len) {
		int cur=want/p10[off]%p10[len];
		if(ok(cur,len)) { printf("%0*d\n",len,cur); return; }
	}
	printf("err\n");
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&val[i]);
	p10[0]=1; FORE(i,1,LEN) p10[i]=p10[i-1]*10;
	FORE(len,1,9) REP(i,n) { set<int> cur; REPE(off,LEN-len) { cur.insert(val[i]/p10[off]%p10[len]); } for(auto it=cur.begin();it!=cur.end();++it) ++cnt[len][*it]; }
	REP(i,n) solve(val[i]);
}

int main() {
	run();
	return 0;
}