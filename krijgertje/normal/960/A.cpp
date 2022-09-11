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

char s[MAXN+1]; int n;

bool solve() {
	int na=0,nb=0,nc=0;
	REP(i,n) if(s[i]=='a') ++na; else if(s[i]=='b') ++nb; else if(s[i]=='c') ++nc;
	if(na+nb+nc!=n) return false;
	FOR(i,1,n) if(s[i-1]>s[i]) return false;
	if(na==0||nb==0) return false;
	if(nc!=na&&nc!=nb) return false;
	return true;
}

void run() {
	scanf("%s",s); n=strlen(s);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}