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

int n,maxhave,T;
int t[20000];
int q[20000],qhead,qtail;
int ret[20000];

void run() {
	scanf("%d%d%d",&n,&maxhave,&T);
	REP(i,n) { int a,b,c; scanf("%d:%d:%d",&a,&b,&c); t[i]=a*3600+b*60+c; }
	qhead=qtail=0; bool ok=false;
	REP(i,n) {
		while(qtail<qhead&&q[qtail]<t[i]) ++qtail;
		if(qhead-qtail==maxhave) q[qhead-1]=t[i]+T-1; else q[qhead++]=t[i]+T-1;
		if(qhead-qtail==maxhave) ok=true;
		ret[i]=qhead;
		//printf("%d: %d..%d\n",t[i],qtail,qhead-1);
	}
	if(!ok) printf("No solution\n"); else { printf("%d\n",qhead); REP(i,n) printf("%d\n",ret[i]); }
}

int main() {
	run();
	return 0;
}