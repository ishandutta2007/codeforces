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

int l[2],r[2],p[2],len[2];

int solve() {
	if(l[0]>l[1]) swap(l[0],l[1]),swap(r[0],r[1]),swap(p[0],p[1]);
	REP(i,2) len[i]=r[i]-l[i]+1;
	int g=gcd(p[0],p[1]);
	int d=(l[1]-l[0])%g;
	int ret=0;
	ret=max(ret,min(len[1],len[0]-d));
	ret=max(ret,min(len[0],len[1]-(g-d)%g));
	return ret;
}

void run() {
	REP(i,2) scanf("%d%d%d",&l[i],&r[i],&p[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}