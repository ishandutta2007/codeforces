#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
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

int n,m,k;

int h,w;

bool solve() {
	int a=2,b=n,c=m,rem=k,g;
	g=gcd(b,rem); b/=g,rem/=g;
	g=gcd(c,rem); c/=g,rem/=g;
	g=gcd(a,rem); a/=g,rem/=g;
	if(rem!=1) return false;
	if(a==2&&2*b<=n) a/=2,b*=2;
	if(a==2&&2*c<=m) a/=2,c*=2;
	assert(a==1);
	w=b,h=c; return true;

}

void run() {
	scanf("%d%d%d",&n,&m,&k);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d %d\n%d %d\n%d %d\n",0,0,w,0,0,h);
}

int main() {
	run();
	return 0;
}