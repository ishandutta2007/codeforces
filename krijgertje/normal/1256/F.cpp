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
#include <chrono>
#include <chrono>
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

const int MAXN=200000;

int n;
char s[MAXN+1];
char t[MAXN+1];

int scnt[26],tcnt[26];

bool solve() {
	memset(scnt,0,sizeof(scnt)); REP(i,n) ++scnt[s[i]-'a'];
	memset(tcnt,0,sizeof(tcnt)); REP(i,n) ++tcnt[t[i]-'a'];
	REP(i,26) if(scnt[i]!=tcnt[i]) return false;
	REP(i,26) if(scnt[i]>=2) return true;
	assert(n<=26);
	int sinv=0; REP(i,n) FOR(j,i+1,n) if(s[i]>s[j]) ++sinv;
	int tinv=0; REP(i,n) FOR(j,i+1,n) if(t[i]>t[j]) ++tinv;
	return sinv%2==tinv%2;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s); assert(strlen(s)==n);
	scanf("%s",t); assert(strlen(t)==n);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}