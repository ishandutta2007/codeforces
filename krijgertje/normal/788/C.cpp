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
#include <random>
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

const int DEN=1000;

int n,want;
bool have[DEN+1];

int d[2*DEN+1];
int q[2*DEN+1],qhead,qtail;


void run() {
	scanf("%d%d",&want,&n); memset(have,false,sizeof(have)); REP(i,n) { int x; scanf("%d",&x); have[x]=true; }

	FORE(i,-DEN,+DEN) d[i+DEN]=INT_MAX; qhead=qtail=0; REPE(i,DEN) if(have[i]) d[i-want+DEN]=1,q[qhead++]=i-want;
	while(qtail<qhead) {
		int at=q[qtail++]; //printf("%d = %d\n",at,d[at+DEN]);
		REPE(i,DEN) if(have[i]) { int to=at+i-want; if(to<-DEN||to>DEN||d[to+DEN]!=INT_MAX) continue; d[to+DEN]=d[at+DEN]+1,q[qhead++]=to; }
	}
	printf("%d\n",d[0+DEN]==INT_MAX?-1:d[0+DEN]);
}

int main() {
	run();
	return 0;
}