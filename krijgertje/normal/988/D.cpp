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

const int MAXN=200000;

int n;
int x[MAXN];

int ret[MAXN],nret;

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	
	sort(x,x+n);
	nret=1; ret[0]=x[0];
	for(ll d=1;d<=x[n-1]-x[0];d*=2) {
		int a=0,b=0;
		REP(i,n) {
			while(a<n&&x[a]<x[i]+d) ++a;
			while(b<n&&x[b]<x[i]+d+d) ++b;
			if(nret<1) { nret=1; ret[0]=x[i]; }
			if(nret<2&&a<n&&x[a]==x[i]+d) { nret=2; ret[0]=x[i],ret[1]=x[a]; }
			if(nret<3&&a<n&&x[a]==x[i]+d&&b<n&&x[b]==x[i]+d+d) { nret=3; ret[0]=x[i],ret[1]=x[a],ret[2]=x[b]; }
		}
	}
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}