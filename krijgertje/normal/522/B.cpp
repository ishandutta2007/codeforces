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

int n;
int w[200000],h[200000];
int maxh[2],sumw;

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&w[i],&h[i]);
	maxh[0]=maxh[1]=sumw=0;
	REP(i,n) {
		sumw+=w[i];
		if(h[i]>maxh[0]) maxh[1]=maxh[0],maxh[0]=h[i]; else if(h[i]>maxh[1]) maxh[1]=h[i];
	}
	REP(i,n) {
		ll ret=(ll)(sumw-w[i])*(h[i]==maxh[0]?maxh[1]:maxh[0]);
		if(i!=0) printf(" "); cout<<ret;
	}
	puts("");
}

int main() {
	run();
	return 0;
}