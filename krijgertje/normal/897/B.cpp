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

int cnt,mod;

void run() {
	scanf("%d%d",&cnt,&mod);
	int rem=cnt; int ret=0;
	for(int hlen=1;rem>0;++hlen) {
		int p=1; REP(i,hlen-1) p*=10;
		for(int i=p;i<10*p&&rem>0;++i) {
			int j=0,k=i; REP(z,hlen) j=10*j+(k%10),k/=10;
			ret=(ret+(ll)i*p*10+j)%mod; --rem;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}