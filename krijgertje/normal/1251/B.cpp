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

const int MAXN=50;
const int MAXLEN=50;

int n;
char s[MAXN][MAXLEN+1];
int len[MAXN];

int solve() {
	REP(i,n) len[i]=strlen(s[i]);
	int none=0,nzero=0; REP(i,n) REP(j,len[i]) if(s[i][j]=='0') ++nzero; else if(s[i][j]=='1') ++none;
	int nodd=0; REP(i,n) if(len[i]%2==1) ++nodd;
	if(nodd>0||none%2==0||nzero%2==0) return n;
	return n-1;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%s",s[i]);
	printf("%d\n",solve());

}

int main() {
	int ncase; scanf("%d",&ncase); FORE(i,1,ncase) run();
	return 0;
}