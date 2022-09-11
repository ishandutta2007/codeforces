#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

const int MAXA=1000;
const int MAXB=1000;

int na,nb;
int a[MAXA];
int b[MAXB];

void run() {
	scanf("%d%d",&na,&nb); REP(i,na) scanf("%d",&a[i]); REP(i,nb) scanf("%d",&b[i]);
	int at=0;
	REP(i,na) if(at<nb&&b[at]>=a[i]) ++at;
	printf("%d\n",at);
}

int main() {
	run();
	return 0;
}