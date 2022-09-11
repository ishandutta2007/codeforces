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

const int MAXN=100;

int n,mx;
int a[MAXN];

void run() {
	scanf("%d%d",&n,&mx); REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	int ret=n;
	for(int l=0,r=l;l<n;++l) {
		if(r<l) r=l;
		while(r<n&&a[r]-a[l]<=mx) ++r;
		int cur=n-(r-l); if(cur<ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}