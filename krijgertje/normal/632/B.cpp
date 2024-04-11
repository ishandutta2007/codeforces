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

const int MAXN=500000;

int n;
int x[MAXN];
char s[MAXN+1];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); scanf("%s",s);
	ll ret=0,sum=0;
	for(int i=n-1;i>=0;--i) {
		if(s[i]=='A') sum+=x[i]; else sum-=x[i];
		if(sum>ret) ret=sum;
	}
	sum=0;
	REP(i,n) {
		if(s[i]=='A') sum+=x[i]; else sum-=x[i];
		if(sum>ret) ret=sum;
	}
	REP(i,n) if(s[i]=='B') ret+=x[i];
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}