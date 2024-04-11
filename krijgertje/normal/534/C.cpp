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

int n; ll have;
int d[200000];
ll sum;

void run() {
	scanf("%d",&n); cin>>have; REP(i,n) scanf("%d",&d[i]);
	sum=0; REP(i,n) sum+=d[i];
	REP(i,n) {
		ll mn=n-1,mx=(sum-d[i]);
		int l=max(1LL,have-mx),r=min((ll)d[i],have-mn);
		int can=l<=r?r-l+1:0;
		if(i!=0) printf(" "); printf("%d",d[i]-can);
	}
	puts("");
}

int main() {
	run();
	return 0;
}