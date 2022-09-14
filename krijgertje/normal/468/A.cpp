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

void run() {
	scanf("%d",&n);
	if(n<4) { printf("NO\n"); return; }
	printf("YES\n"); int n1=0;
	while(n>5) {
		int a=n,b=n-1;
		printf("%d - %d = %d\n",a,b,1); 		
		n-=2; ++n1;
	}
	if(n==4) {
		++n1;
		printf("%d * %d = %d\n",2,3,6);
		printf("%d * %d = %d\n",6,4,24);
	}
	if(n==5) {
		printf("%d * %d = %d\n",4,5,20);
		printf("%d - %d = %d\n",20,1,19);
		printf("%d + %d = %d\n",19,2,21);
		printf("%d + %d = %d\n",21,3,24);
	}
	REP(i,n1) printf("%d * %d = %d\n",24,1,24);
}

int main() {
	run();
	return 0;
}