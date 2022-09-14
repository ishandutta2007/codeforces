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

int n,x;

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int mpow(int a,int n,int m) {
	if(n==0) return 1;
	if(n%2==1) return (ll)a*mpow(a,n-1,m)%m;
	return mpow((ll)a*a%m,n/2,m);
}

void run(int casenr) {
	scanf("%d%d",&n,&x);
	if(n==1) { printf("%d\n",x==2?-1:x-1); return; }

	//n+1 (=p) must be prime
	{ int y=n+1; for(int i=2;i*i<=y;++i) if(y%i==0) { printf("-1\n"); return; } }

	// find factors of n (=p-1)
	vector<int> fact;
	{ int y=n; for(int i=2;i*i<=y;++i) if(y%i==0) { fact.PB(i); while(y%i==0) y/=i; } if(y!=1) fact.PB(y); }
//	printf("facts: "); REPSZ(i,fact) printf(" %d",fact[i]); puts("");
	
	// find a generator
	int gen=-1;
	FOR(i,2,n+1) {
		assert(mpow(i,n,n+1)==1);
		bool ok=true;
		REPSZ(j,fact) if(mpow(i,n/fact[j],n+1)==1) { ok=false; break; }
		if(!ok) continue;
		gen=i; break;
	}
	assert(gen!=-1);
//	printf("gen: %d\n",gen);
	
	int ret=-1,cur=1;
	REP(i,n) {
		if(gcd(i,n)==1&&cur<x) {
			int now = cur+(x-cur-1)/(n+1)*(n+1);
//			printf("%d -> %d\n",cur,now);
			if(now>ret) ret=now;
		}
		cur=(ll)cur*gen%(n+1);
	}
	printf("%d\n",ret);
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}