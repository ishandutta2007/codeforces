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

const int MAXN=400000;

int n,k;
char s[MAXN+1];

bool keep[MAXN];
char ans[MAXN+1]; int anslen;

void run() {
	scanf("%d%d",&n,&k); scanf("%s",s);

	REP(i,n) keep[i]=true;
	for(char c='a';c<='z';++c) REP(i,n) if(k>0&&s[i]==c) keep[i]=false,--k;

	anslen=0; REP(i,n) if(keep[i]) ans[anslen++]=s[i]; ans[anslen++]='\0';
	printf("%s\n",ans);
}

int main() {
	run();
	return 0;
}