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

const int MAXN=200000;

int n;
int p[MAXN];
int b[MAXN];
bool done[MAXN];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]),--p[i]; REP(i,n) scanf("%d",&b[i]);

	int ncyc=0;
	REP(i,n) done[i]=false;
	REP(i,n) if(!done[i]) {
		int at=i;
		while(!done[at]) { done[at]=true; at=p[at]; }
		++ncyc;
	}
	int sumb=0; REP(i,n) sumb+=b[i];
	//printf("ncyc=%d sumb=%d\n",ncyc,sumb);
	int ret=(ncyc==1?0:ncyc)+(1-sumb%2);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}