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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
bool lasta;
int a[200000],na; ll suma;
int b[200000],nb; ll sumb;

bool win() {
	if(suma!=sumb) return suma>sumb;
	int ln=min(na,nb); REP(i,ln) if(a[i]!=b[i]) return a[i]>b[i];
	if(na!=nb) return na>nb;
	return lasta;
}


void run() {
	na=nb=suma=sumb=0; lasta=false;
	scanf("%d",&n); REP(i,n) { int x; scanf("%d",&x); if(x>0) a[na++]=x,suma+=x,lasta=true; else b[nb++]=-x,sumb-=x,lasta=false; }
	printf("%s\n",win()?"first":"second");
}

int main() {
	run();
	return 0;
}