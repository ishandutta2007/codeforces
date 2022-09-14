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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int na,a[100];
int nb,b[100];

bool can[100];

void run() {
	scanf("%d",&n);
	scanf("%d",&na); REP(i,na) { scanf("%d",&a[i]); --a[i]; }
	scanf("%d",&nb); REP(i,nb) { scanf("%d",&b[i]); --b[i]; }
	REP(i,n) can[i]=false; REP(i,na) can[a[i]]=true; REP(i,nb) can[b[i]]=true;
	bool win=true; REP(i,n) if(!can[i]) win=false;
	printf("%s\n",win?"I become the guy.":"Oh, my keyboard!");
}

int main() {
	run();
	return 0;
}