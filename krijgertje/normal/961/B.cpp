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

const int MAXN=100000;

int n,len;
int a[MAXN],b[MAXN];

int sum1[MAXN+1];
int sum2[MAXN+1];

void run() {
	scanf("%d%d",&n,&len); REP(i,n) scanf("%d",&a[i]); REP(i,n) scanf("%d",&b[i]);

	sum1[0]=0; REP(i,n) sum1[i+1]=sum1[i]+a[i];
	sum2[0]=0; REP(i,n) sum2[i+1]=sum2[i]+a[i]*b[i];
	int ret=0;
	REPE(i,n-len) {
		int cur=sum2[i]+(sum2[n]-sum2[i+len])+(sum1[i+len]-sum1[i]);
		ret=max(ret,cur);
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}