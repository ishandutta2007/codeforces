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
#include <random>
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

const int MAXN=100000;

int n;
int a[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	int g=a[0]; FOR(i,1,n) g=gcd(g,a[i]); if(g>1) { printf("YES\n0\n"); return; }
	int ret=0;
	for(int at=0,to=at;at<n;at=to) {
		if(to<at) to=at;
		while(to<n&&a[at]%2==a[to]%2) ++to;
		int cnt=to-at;
		if(a[at]%2==1) { ret+=cnt/2; if(cnt%2==1) ret+=2; }
	}
	printf("YES\n%d\n",ret);
}

int main() {
	run();
	return 0;
}