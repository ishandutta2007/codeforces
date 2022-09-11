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

const int MAXN=1500;

int n;
int a[MAXN];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]),--a[i];

	int cnt=0; REP(i,n) FOR(j,i+1,n) if(a[i]>a[j]) ++cnt;
	int par=cnt%2;

	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		int len=r-l+1;
		if(len%4==2||len%4==3) par=1-par;
		printf("%s\n",par==0?"even":"odd");
	}
}

int main() {
	run();
	return 0;
}