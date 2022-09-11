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

int n,have;
int a[MAXN];

int b[MAXN];

bool can(int cnt) {
	REP(i,cnt) b[i]=a[i];
	sort(b,b+cnt); reverse(b,b+cnt);
	ll need=0; for(int i=0;i<cnt;i+=2) need+=b[i]; return need<=have;
}

int solve() {
	int l=0,h=n+1;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) l=m; else h=m;
	}
	return l;
}

void run() {
	scanf("%d%d",&n,&have);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}