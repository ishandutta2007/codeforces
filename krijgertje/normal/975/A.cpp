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

const int MAXN=1000;
const int MAXLEN=1000;

int n;
char s[MAXN][MAXLEN+1];

int mask[MAXN],nmask;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%s",s[i]);
	nmask=0; REP(i,n) { int cur=0; int len=strlen(s[i]); REP(j,len) { int x=s[i][j]-'a'; cur|=1<<x; } mask[nmask++]=cur; }
	sort(mask,mask+nmask); nmask=unique(mask,mask+nmask)-mask;
	printf("%d\n",nmask);

}

int main() {
	run();
	return 0;
}