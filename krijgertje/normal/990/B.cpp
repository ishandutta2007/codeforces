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

const int MAXN=200000;

int n,mxdiff;
int a[MAXN];


void run() {
	scanf("%d%d",&n,&mxdiff);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	int ret=0;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		int cnt=r-l;
		if(r==n||a[r]-a[r-1]>mxdiff) ret+=cnt;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}