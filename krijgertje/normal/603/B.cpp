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

const int MOD=1000000007;
const int MAXP=1000000;

int p,k;
bool done[MAXP];

void run() {
	scanf("%d%d",&p,&k);
	int ret=1;
	memset(done,false,sizeof(done));
	FOR(i,k==1?0:1,p) if(!done[i]) {
		int cur=1,at=i;
		while(!done[at]) { done[at]=true; cur=(ll)cur*k%p; at=(ll)k*at%p; }
		if(cur!=0&&cur!=1) { printf("0\n"); return; }
		ret=(ll)ret*p%MOD;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}