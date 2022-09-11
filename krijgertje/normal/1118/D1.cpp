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

const int MAXN=200000;

int n,need;
int a[MAXN];

bool can(int days) {
	ll have=0; REP(i,n) { int penalty=i/days; have+=max(0,a[i]-penalty); } return have>=need;
}

int solve() {
	sort(a,a+n);
	reverse(a,a+n);
	ll sum=0; REP(i,n) sum+=a[i]; if(sum<need) return -1;
	int l=0,h=n;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(can(m)) h=m; else l=m;
	}
	return h;
}

void run() {
	scanf("%d%d",&n,&need);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}