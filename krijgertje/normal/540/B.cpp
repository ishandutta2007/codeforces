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

int n,nhave,maxmark,maxsum,minmed;

int ret[999],nret;

void run() {
	scanf("%d%d%d%d%d",&n,&nhave,&maxmark,&maxsum,&minmed);

	int havesum=0,haveok=0,needok=(n+1)/2;
	REP(i,nhave) { int cur; scanf("%d",&cur); havesum+=cur; if(cur>=minmed) haveok++; }
	
	nret=0; REP(i,n-nhave) { int cur=haveok<needok?minmed:1; havesum+=cur; if(cur>=minmed) haveok++; ret[nret++]=cur; }
	if(haveok<needok||havesum>maxsum) { printf("-1\n"); return; }
	REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}