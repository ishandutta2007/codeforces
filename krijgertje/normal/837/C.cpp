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

const int MAXN=100;

int n,A,B;
int x[MAXN],y[MAXN];

void run() {
	scanf("%d%d%d",&n,&A,&B); REP(i,n) scanf("%d%d",&x[i],&y[i]);
	int ret=0;
	REP(i,n) REP(fi,2) FOR(j,i+1,n) REP(fj,2) {
		int a1=x[i],b1=y[i]; if(fi==1) swap(a1,b1);
		int a2=x[j],b2=y[j]; if(fj==1) swap(a2,b2);
		if(a1>A||a2>A||b1>B||b2>B) continue;
		int c1=a1-1,d1=b1-1,c2=A-a2,d2=B-b2,cur=a1*b1+a2*b2;
		if(c1>=c2&&d1>=d2) continue;
		if(cur>ret) ret=cur;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}