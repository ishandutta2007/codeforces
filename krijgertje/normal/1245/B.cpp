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

const int MAXN=100;

int n;
int a,b,c; // rock,paper,scissors
char s[MAXN+1];
char ans[MAXN+1];

bool solve() {
	REP(i,n) ans[i]='?'; ans[n]='\0';
	int aa=a,bb=b,cc=c; int win=0;
	REP(i,n) if(s[i]=='R'&&bb>0) ans[i]='P',--bb,++win;
	REP(i,n) if(s[i]=='P'&&cc>0) ans[i]='S',--cc,++win;
	REP(i,n) if(s[i]=='S'&&aa>0) ans[i]='R',--aa,++win;
	if(win<(n+1)/2) return false;
	REP(i,n) if(ans[i]=='?') if(aa>0) ans[i]='R',--aa; else if(bb>0) ans[i]='P',--bb; else if(cc>0) ans[i]='S',--cc; else assert(false);
	assert(aa==0&&bb==0&&cc==0);
	return true;
}


void run() {
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c); assert(a+b+c==n);
	scanf("%s",s); assert(strlen(s)==n);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n",ans);
}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}