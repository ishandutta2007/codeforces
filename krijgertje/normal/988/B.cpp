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

int n;
string s[MAXN];

bool mycmp(const string &a,const string &b) { return SZ(a)<SZ(b); }

int indexof(const string &a,const string &b) { REPE(i,SZ(b)-SZ(a)) { bool ok=true; REPSZ(j,a) if(a[j]!=b[i+j]) { ok=false; break; } if(ok) return i; } return -1; }

void run() {
	cin>>n; REP(i,n) cin>>s[i];
	sort(s,s+n,mycmp);
	REP(i,n-1) if(indexof(s[i],s[i+1])==-1) { printf("NO\n"); return; }
	printf("YES\n"); REP(i,n) printf("%s\n",s[i].c_str());
}

int main() {
	run();
	return 0;
}