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

const int MAXN=100000;
typedef struct R { int a,b,idx; } R;
bool operator<(const R &p,const R &q) { return p.a>q.a; }

int n;
R r[MAXN];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&r[i].a); REP(i,n) scanf("%d",&r[i].b); REP(i,n) r[i].idx=i; sort(r,r+n);
	nret=0; ret[nret++]=r[0].idx; for(int i=1;i+1<n;i+=2) ret[nret++]=r[i].b>=r[i+1].b?r[i].idx:r[i+1].idx; if(n%2==0) ret[nret++]=r[n-1].idx;
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}