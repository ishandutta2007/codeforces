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

const int MAXX=200;

int n0,n1,nx;

char c[MAXX+1];
int cnt[MAXX+1];

void run() {
	scanf("%d%d%d",&n0,&n1,&nx);

	for(int i=0;i<=nx;i+=2) c[i]=n0>=n1?'0':'1',cnt[i]=1;
	for(int i=1;i<=nx;i+=2) c[i]=n0>=n1?'1':'0',cnt[i]=1;
	int rem0=n0,rem1=n1;
	REPE(i,nx) if(c[i]=='0') rem0-=cnt[i]; else if(c[i]=='1') rem1-=cnt[i];
	assert(rem0>=0&&rem1>=0);
	REPE(i,nx) if(c[i]=='0') cnt[i]+=rem0,rem0=0; else if(c[i]=='1') cnt[i]+=rem1,rem1=0;
	REPE(i,nx) REP(j,cnt[i]) printf("%c",c[i]); puts("");
}

int main() {
	run();
	return 0;
}