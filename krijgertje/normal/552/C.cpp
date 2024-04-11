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

const int MAXDIG=32;

int base,have;

int d[MAXDIG],nd;

void run() {
	scanf("%d%d",&base,&have);

	nd=0; for(int x=have;x!=0;x/=base) d[nd++]=x%base;

	REP(i,nd) {
		if(d[i]==1) --d[i];
		if(d[i]==base-1) ++d[i];
		if(d[i]==base) { d[i]=0; if(i+1<nd) ++d[i+1]; else d[i+1]=1,++nd; }
		if(d[i]==0) continue;
		printf("NO\n"); return;
	}
	printf("YES\n");
}

int main() {
	run();
	return 0;
}