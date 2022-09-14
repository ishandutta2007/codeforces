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

const int MAXN=200000;
char a[MAXN+1],b[MAXN+1]; int len;

void norm(char *s,int n) {
	if(n%2!=0) return;
	int nn=n/2;
	norm(s,nn); norm(s+nn,nn);
	bool ok=true;
	REP(i,nn) if(s[i]!=s[nn+i]) { ok=s[i]<s[nn+i]; break; }
	if(!ok) REP(i,nn) swap(s[i],s[nn+i]);
}

void run() {
	scanf("%s%s",a,b); len=strlen(a);
	norm(a,len);
	norm(b,len);
	bool same=true; REP(i,len) if(a[i]!=b[i]) same=false;
	printf("%s\n",same?"YES":"NO");
}

int main() {
	run();
	return 0;
}