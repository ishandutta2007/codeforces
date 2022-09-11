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

const int MAXN=5000;

bool local=false;
int ploc[MAXN],rloc[MAXN];

int query(int a,int b) {
	if(local) {
		return ploc[a]^rloc[b];
	} else {
		printf("? %d %d\n",a,b); fflush(stdout); int ret; scanf("%d",&ret); return ret;
	}
}

int n;
int pxor[MAXN],rxor[MAXN];
int p[MAXN],r[MAXN];
bool have[MAXN];
bool ok() {
	REP(i,n) have[i]=false; REP(i,n) have[p[i]]=true; REP(i,n) if(!have[i]) return false;
	REP(i,n) if(r[p[i]]!=i) return false;
	return true;
}

int pans[MAXN];

int solve() {
//	REP(i,n) REP(j,n) printf("? %d %d = %d\n",i,j,query(i,j));
	REP(j,n) rxor[j]=query(0,j);
	FOR(i,1,n) pxor[i]=query(i,0)^rxor[0];
	//printf("pxor:"); FOR(i,1,n) printf(" %x",pxor[i]); puts("");
	//printf("rxor:"); REP(i,n) printf(" %x",rxor[i]); puts("");
	int ret=0;
	REP(p0,n) {
		p[0]=p0; FOR(i,1,n) p[i]=p0^pxor[i]; REP(j,n) r[j]=p0^rxor[j];
		if(!ok()) continue;
		++ret;
		if(ret==1) REP(i,n) pans[i]=p[i];
	}
	return ret;
}

void run() {
	scanf("%d",&n);
	int ret=solve();
	printf("!\n%d\n",ret);
	if(ret>=1) { REP(i,n) { if(i!=0) printf(" "); printf("%d",pans[i]); } puts(""); }
}

void test() {
	local=true; scanf("%d",&n); REP(i,n) scanf("%d",&ploc[i]); REP(i,n) rloc[ploc[i]]=i;
	int ret=solve();
	printf("%d solutions\n",ret);
}

int main() {
	run();
	//test();
	return 0;
}