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
#include <bitset>
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

const int MAXN=1000;
struct Portal { int x1,y1,x2,y2; Portal() {} Portal(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2) {} };

int n;
int rdest[MAXN];
int cdest[MAXN];
vector<Portal> ans;

int rcur[MAXN];
int ccur[MAXN];

bool solve() {
	ans.clear();
	REP(i,n) rcur[rdest[i]]=i,ccur[cdest[i]]=i;
	for(int i=n-1;i>=1;--i) {
		int r=-1; REPE(j,i) if(rcur[j]==i) { assert(r==-1); r=j; } assert(r!=-1);
		int c=-1; REPE(j,i) if(ccur[j]==i) { assert(c==-1); c=j; } assert(c!=-1);
		if(r!=i&&c!=i) ans.PB(Portal(r,i,i,c));
		else if(r!=i) ans.PB(Portal(r,i,i,i));
		else if(c!=i) ans.PB(Portal(i,i,i,c));
		swap(rcur[r],rcur[i]); swap(ccur[c],ccur[i]);
	}
	return true;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&rdest[i]),--rdest[i];
	REP(i,n) scanf("%d",&cdest[i]),--cdest[i];
	if(!solve()) { printf("-1\n"); return; }
	printf("%d\n",SZ(ans));
	REPSZ(i,ans) printf("%d %d %d %d\n",ans[i].x1+1,ans[i].y1+1,ans[i].x2+1,ans[i].y2+1);
}

int main() {
	run();
	return 0;
}