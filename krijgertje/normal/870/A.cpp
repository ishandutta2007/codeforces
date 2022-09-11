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

const int MAXA=9;
const int MAXB=9;

int na,nb;
int a[MAXA];
int b[MAXB];

void run() {
	scanf("%d%d",&na,&nb); REP(i,na) scanf("%d",&a[i]); REP(i,nb) scanf("%d",&b[i]);
	FORE(x,1,9) { bool ina=false,inb=false; REP(i,na) if(a[i]==x) ina=true; REP(i,nb) if(b[i]==x) inb=true; if(ina&&inb) { printf("%d\n",x); return; } }
	sort(a,a+na); sort(b,b+nb); int x=a[0],y=b[0]; if(x>y) swap(x,y); printf("%d\n",10*x+y);
}

int main() {
	run();
	return 0;
}