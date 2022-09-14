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

const int MAXPROD=100000;

int h,w;
int a[MAXPROD];
int b[MAXPROD];
int rmx[MAXPROD];
int nq;



void run() {
	scanf("%d%d",&h,&w); REP(x,h) REP(y,w) scanf("%d",&a[x*w+y]);
	for(int x=h-1;x>=0;--x) REP(y,w) b[x*w+y]=x==h-1?h-1:a[x*w+y]<=a[(x+1)*w+y]?b[(x+1)*w+y]:x;
	REP(x,h) rmx[x]=INT_MIN; REP(x,h) REP(y,w) if(b[x*w+y]>rmx[x]) rmx[x]=b[x*w+y];
	scanf("%d",&nq);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		printf("%s\n",rmx[l]>=r?"Yes":"No");
	}
}

int main() {
	run();
	return 0;
}