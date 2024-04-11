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

const int MAXN=6;

int n,me;
int x[MAXN-1];

void run() {
	scanf("%d%d",&n,&me); --me;
	REP(i,n-1) scanf("%d",&x[i]);
	int sum=0; REP(i,n-1) sum+=x[i];
	// we guess sum+xme = me (mod n) -> xme=me-sum (mod n)
	int ret=(me-sum)%n; if(ret<=0) ret+=n;
	printf("%d\n",ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}