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

const int MAXN=50;

int n,c;
int p[MAXN],t[MAXN];

void run() {
	scanf("%d%d",&n,&c); REP(i,n) scanf("%d",&p[i]); REP(i,n) scanf("%d",&t[i]);
	int a=0; { int x=0; REP(i,n) { x+=t[i]; a+=max(0,p[i]-c*x); } }
	int b=0; { int x=0; for(int i=n-1;i>=0;--i) { x+=t[i]; b+=max(0,p[i]-c*x); } }
	//printf("%d %d\n",a,b);
	printf("%s\n",a>b?"Limak":b>a?"Radewoosh":"Tie");
}

int main() {
	run();
	return 0;
}