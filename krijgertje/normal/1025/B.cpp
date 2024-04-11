#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXN=150000;

int n;
int a[MAXN],b[MAXN];

vector<int> primes(int x) {
	vector<int> ret;
	for(int i=2;i*i<=x;++i) if(x%i==0) { ret.PB(i); while(x%i==0) x/=i;  }
	if(x!=1) ret.PB(x);
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&a[i],&b[i]);

	vector<int> ap=primes(a[0]),bp=primes(b[0]);
	vector<int> p; REPSZ(i,ap) p.PB(ap[i]); REPSZ(i,bp) p.PB(bp[i]); sort(p.begin(),p.end()); p.erase(unique(p.begin(),p.end()),p.end());
	REPSZ(i,p) {
		int cur=p[i]; bool ok=true;
		REP(j,n) if(a[j]%cur!=0&&b[j]%cur!=0) { ok=false; break; }
		if(ok) { printf("%d\n",cur); return; }
	}
	printf("-1\n");
}

int main() {
	run();
	return 0;
}