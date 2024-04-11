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

const int MAXN=100;

int n,nq;
int q[MAXN];
int ret[MAXN],nret;
int id[MAXN];


void run() {
	scanf("%d%d",&n,&nq);
	REP(i,nq) scanf("%d",&q[i]);
	REP(i,n) id[i]=i+1;
	nret=0; int at=0;
	REP(qq,nq) {
		//printf("n=%d at=%d\n",n,at); REP(i,n) printf("%d ",id[i]); puts("");
		int to=(at+q[qq])%n;
		ret[nret++]=id[to]; FOR(i,to,n-1) id[i]=id[i+1]; --n;
		at=to%n;
	}
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}