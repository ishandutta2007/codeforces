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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int nbun,nbeef,nchick;
int pbeef,pchick;

int solve() {
	int na=nbeef,nb=nchick,pa=pbeef,pb=pchick;
	if(pa<pb) swap(na,nb),swap(pa,pb);
	int cnt=nbun/2;
	int rem=cnt;
	int cur=min(rem,na);
	int ret=0;
	ret+=cur*pa; rem-=cur;
	cur=min(rem,nb);
	ret+=cur*pb; rem-=cur;
	return ret;
}

void run() {
	scanf("%d%d%d",&nbun,&nbeef,&nchick);
	scanf("%d%d",&pbeef,&pchick);
	printf("%d\n",solve());
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}