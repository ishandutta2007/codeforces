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

int freq[26][MAXN][26];

void run() {
	scanf("%s",s); n=strlen(s);
	REP(x,26) REP(i,n) REP(y,26) freq[x][i][y]=0;
	REP(j,n) { int x=s[j]-'a'; REP(i,n) { int k=(i+j)%n,y=s[k]-'a'; ++freq[x][i][y]; } }
	int ret=0;
	REP(x,26) { int mx=0; REP(i,n) { int cur=0; REP(y,26) if(freq[x][i][y]==1) ++cur; mx=max(mx,cur); } ret+=mx; }
	printf("%.15lf\n",1.0*ret/n);
}

int main() {
	run();
	return 0;
}