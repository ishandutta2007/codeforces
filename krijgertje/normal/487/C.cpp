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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int inv[100000];

bool isprime(int n) {
	if(n<=1) return false;
	for(int i=2;i*i<=n;++i) if(n%i==0) return false;
	return true;
}

void printprime() {
	inv[1]=1; FOR(i,2,n) inv[i]=(n-(ll)(n/i)*inv[n%i]%n)%n;
	printf("%d\n",1);
	FOR(i,1,n-1) {
		int now=(ll)(i+1)%n*inv[i]%n;
		printf("%d\n",now);
	}
	printf("%d\n",n);
}

void run() {
	scanf("%d",&n);
	if(isprime(n)) { printf("YES\n"); printprime(); }
	else if(n==4) printf("YES\n%d\n%d\n%d\n%d\n",1,3,2,4);
	else if(n==1) printf("YES\n%d\n",1);
	else printf("NO\n");
}

int main() {
	run();
	return 0;
}