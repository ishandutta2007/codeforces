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

char buff[20];

int n,p;

void run() {
	scanf("%d%d",&n,&p);
	ll mask=0;
	REP(i,n) {
		scanf("%s",buff);
		if(strcmp(buff,"halfplus")==0) mask|=1LL<<i;
	}
	ll have=0,ret=0;
	for(int i=n-1;i>=0;--i) {
		if((mask&(1LL<<i))!=0) {
			have=2*have+1;
		} else {
			have=2*have;
		}
		ret+=p/2*have;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}