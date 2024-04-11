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

ll x;
ll ret[1000000][2]; int nret;

void run() {
	// (a,b) -> a*b+(a-1)*(b-1)+(a-2)*(b-2)+....(a-a)*(b-a)
	// (a+1)*a*b-a*(a+1)/2*(a+b)+a*(a+1)*(2*a+1)/6
	// (a+1)*a*(3b-a+1)/6=x -> b=(6x/(a+1)/a+a-1)/3

	scanf("%I64d",&x);
	nret=0;
	for(int a=1;(ll)a*(a+1)*(2*a+1)<=6*x;++a) {
		ll b=6*x; if(b%a!=0) continue; else b/=a; if(b%(a+1)!=0) continue; else b/=a+1; b+=a-1; if(b%3!=0) continue; else b/=3;
		if(b<a) break;
		ret[nret][0]=a,ret[nret][1]=b,++nret;
	}
	for(int i=nret-1;i>=0;--i) if(ret[i][0]!=ret[i][1]) ret[nret][0]=ret[i][1],ret[nret][1]=ret[i][0],++nret;
	printf("%d\n",nret); REP(i,nret) printf("%I64d %I64d\n",ret[i][0],ret[i][1]);
}

int main() {
	run();
	return 0;
}