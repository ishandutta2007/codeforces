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

int n,have;
char s[MAXN+2];
int sep;

void inc(int at) {
	while(s[at]=='9') {
		s[at]='0';
		if(at==0) { for(int i=n;i>=0;--i) s[i+1]=s[i]; s[0]='1'; ++n; ++sep; return; }
		at=s[at-1]=='.'?at-2:at-1;
	}
	++s[at];
}
void solve() {
	int left=have; sep=-1;
	REP(i,n) if(s[i]=='.') { sep=i; break; } if(sep==-1) return;
	int fst=-1; FOR(i,sep+1,n) if(isdigit(s[i])&&s[i]>='5') { fst=i; break; } if(fst==-1) return;
	FOR(i,fst,n) s[i]='0'; int at=s[fst-1]=='.'?fst-2:fst-1; inc(at); --left;
	while(left>0&&s[at]>='5'&&at>sep) {
		s[at]='0'; at=s[at-1]=='.'?at-2:at-1; inc(at); --left;
	}
	while(sep<n&&s[n-1]=='0'||s[n-1]=='.') --n; s[n]='\0';
}

void run() {
	scanf("%d%d%s",&n,&have,s); n=strlen(s);
	solve();
	printf("%s\n",s);
}

int main() {
	run();
	return 0;
}