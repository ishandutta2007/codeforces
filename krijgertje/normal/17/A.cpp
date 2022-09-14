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

const int MAXN=1000;
bool isprime[MAXN+1];
vector<int> primes;

void run() {
	int n,k; scanf("%d%d",&n,&k);
	int cnt=0;
	FORSZ(i,1,primes) { int cur=1+primes[i-1]+primes[i]; if(2<=cur&&cur<=n&&isprime[cur]) ++cnt; }
	printf("%s\n",cnt>=k?"YES":"NO");
}

void precalc() {
	REPE(i,MAXN) isprime[i]=i!=0&&i!=1; primes.clear();
	FORE(i,2,MAXN) if(isprime[i]) { primes.PB(i); for(int j=i+i;j<=MAXN;j+=i) isprime[j]=false; }
}

int main() {
	precalc();
	run();
	return 0;
}