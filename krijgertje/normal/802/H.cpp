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

char a[100]; int na;
char b[100]; int nb;

char get(int x) {
	if(x<26) return 'a'+x;
	if(x<52) return 'A'+(x-26);
	assert(false); return '?';
}

void run() {
	scanf("%d",&n);
	
	int p=0; while((2<<p)-1<=n) ++p;
	n-=(1<<p)-1;
	//printf("p=%d n=%d\n",p,n);
	
	na=0,nb=0; int nc=0;
	a[na++]=get(nc++);
	REP(i,p) {
		if(n&(1<<i)) a[na++]=get(nc),b[nb++]=get(nc),++nc;
		if(i!=p-1) { a[na++]=get(nc),a[na++]=get(nc),b[nb++]=get(nc); ++nc; }
	}
	REP(i,na) printf("%c",a[i]); REP(i,nb) printf("%c",b[i]); printf(" "); REP(i,nc) printf("%c",get(i)); puts("");


}

int main() {
	run();
	return 0;
}