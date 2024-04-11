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

int scramble(int n) {
	int a=n%10; n/=10; int b=n%10; n/=10; int c=n%10; n/=10; int d=n%10; n/=10; int e=n;
	return 10000*e+1000*c+100*a+10*b+d;
}

int mypow(int n,int k,int mod) {
	int ret=1;
	REP(i,k) ret=(ll)ret*n%mod;
	return ret;
}

int n;
void run() {
	scanf("%d",&n);
	printf("%05d\n",mypow(scramble(n),5,100000));
}

int main() {
	run();
	return 0;
}