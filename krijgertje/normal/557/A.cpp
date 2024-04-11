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
int l[3],h[3],ret[3];

void run() {
	scanf("%d",&n);
	REP(i,3) scanf("%d%d",&l[i],&h[i]);
	ret[0]=min(h[0],n-l[1]-l[2]);
	ret[1]=min(h[1],n-ret[0]-l[2]);
	ret[2]=min(h[2],n-ret[0]-ret[1]);
	printf("%d %d %d\n",ret[0],ret[1],ret[2]);
}

int main() {
	run();
	return 0;
}