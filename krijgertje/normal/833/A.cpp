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


bool solve(int a,int b) {
	int g=gcd(a,b);
	int wa=a/g,wb=b/g;
	if(g%wa!=0||g%wb!=0) return false;
	int gg=g/wa/wb;
	for(int i=1;i*i*i<=gg;++i) if(i*i*i==gg) return true;
	return false;
}

void run() {
	int a,b; scanf("%d%d",&a,&b);
	printf("%s\n",solve(a,b)?"Yes":"No");
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}