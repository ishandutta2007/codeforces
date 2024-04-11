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

int n,lim;
int a[MAXN];

int solve() {
	sort(a,a+n);
	int rem=lim;
	int val=a[(n-1)/2],cnt=1;
	int at=(n-1)/2+1;
	while(rem>=cnt) {
		while(at<n&&a[at]==val) ++at,++cnt;
		int cur=rem/cnt;
		if(at<n) cur=min(cur,a[at]-val);
		val+=cur; rem-=cur*cnt;
	}
	return val;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}