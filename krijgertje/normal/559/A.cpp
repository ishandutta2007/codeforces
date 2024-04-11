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

int a,b,c,d,e,f;

void run() {
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	printf("%d\n",2*a*b+2*b*c+2*a*c+b*b-e*e);

	// w=1/2*(2a+b+f)
	// h=sqrt(3)/2*(b+c)
	// sub=sqrt(3)/8*(b*b+c*c+e*e+f*f)
	// (w*h-sub)/(sqrt(3)/4)
	// (1/2*(2a+b+f)*sqrt(3)/2*(b+c)-sqrt(3)/8*(b*b+c*c+e*e+f*f))/(sqrt(3)/4)
	// (4a*b+2b*b+2f*b+4a*c+2b*c+2f*c-b*b-c*c-e*e-f*f)/(2)
	// 2ab+bb+2bc+2ac-ee
}

int main() {
	run();
	return 0;
}