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

const int MAXN=100000;

int n,limden;
int a[MAXN];

void run() {
	scanf("%d%d",&n,&limden); REP(i,n) scanf("%d",&a[i]);

	int at=0; double ret=0; bool any=false;
	REP(i,n) {
		if(at<i) at=i;
		while(at+1<n&&a[at+1]-a[i]<=limden) ++at;
		if(at<=i+1) continue;
		double cur=1.0*(a[at]-a[i+1])/(a[at]-a[i]);
		if(!any||cur>ret) any=true,ret=cur;
	}
	if(!any) printf("-1\n"); else printf("%.15lf\n",ret);
}

int main() {
	run();
	return 0;
}