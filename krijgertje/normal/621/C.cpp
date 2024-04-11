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

int n,p;
int l[MAXN],r[MAXN];

double calc(int l,int r) {
	return 1.0*(r/p-(l-1)/p)/(r-l+1);
}

void run() {
	scanf("%d%d",&n,&p);
	REP(i,n) scanf("%d%d",&l[i],&r[i]);

	double ret=0;
	REP(i,n) {
		int j=i+1>=n?0:i+1;
		double pi=calc(l[i],r[i]),pj=calc(l[j],r[j]);
		ret+=2000*(pi+pj-pi*pj);
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}