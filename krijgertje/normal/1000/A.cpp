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
const int MAXX=3;
const int MAXLEN=MAXX+1;

int n;
char a[MAXN][MAXLEN+1];
char b[MAXN][MAXLEN+1];

int bal[3][MAXX+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",a[i]); REP(i,n) scanf("%s",b[i]);

	memset(bal,0,sizeof(bal));
	REP(i,n) { int len=strlen(a[i]); int nx=len-1; char c=a[i][len-1]; int id=c=='S'?0:c=='L'?1:2; ++bal[id][nx]; }
	REP(i,n) { int len=strlen(b[i]); int nx=len-1; char c=b[i][len-1]; int id=c=='S'?0:c=='L'?1:2; --bal[id][nx]; }
	//REPE(nx,MAXX) { printf("%d:",nx); REP(id,3) printf(" %2d",bal[id][nx]); puts(""); }

	int ret=0;
	REPE(nx,MAXX) { int cur=0,sum=0; REP(id,3) cur=max(cur,abs(bal[id][nx])),sum+=bal[id][nx]; assert(sum==0); ret+=cur; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}