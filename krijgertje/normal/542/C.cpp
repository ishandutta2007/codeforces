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

int n;
int x[200];

int t[200];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]),--x[i];
	ll a=1,b=1;
	REP(i,n) {
		memset(t,-1,sizeof(t));
		int ct=0,at=i;
		while(t[at]==-1) { t[at]=ct; at=x[at]; ++ct; }
		ll ca=ct-t[at],cb=t[at];
		a=a/gcd(a,ca)*ca; if(cb>b) b=cb;
	}
	ll ret=(b+a-1)/a*a;
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}