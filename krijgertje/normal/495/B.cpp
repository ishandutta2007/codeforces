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


int a,b;

void run() {
	scanf("%d%d",&a,&b);
	// a=b (mod x) -> a-b=?*x, b<x
	if(a==b) { printf("infinity\n"); return; }
	int ret=0;
	if(a>b) {
		int d=a-b;
		for(int i=1;i*i<=d;++i) if(d%i==0) {
			if(b<i) ++ret;
			if(i*i!=d&&b<d/i) ++ret;
		}
	}
	printf("%d\n",ret);

}

int main() {
	run();
	return 0;
}