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

const int MAXN=200000;

int n;
char s[MAXN+1];
int tx,ty;

int prefx[MAXN+1],prefy[MAXN+1];

bool can(int l,int r) {
	int dx=prefx[l]+prefx[n]-prefx[r+1];
	int dy=prefy[l]+prefy[n]-prefy[r+1];
	int have=r-l+1,need=abs(dx-tx)+abs(dy-ty);
	return have%2==need%2&&have>=need;
}

int solve() {
	prefx[0]=prefy[0]=0;
	REP(i,n) {
		prefx[i+1]=prefx[i]+(s[i]=='R'?1:0)-(s[i]=='L'?1:0);
		prefy[i+1]=prefy[i]+(s[i]=='U'?1:0)-(s[i]=='D'?1:0);
	}
	if(prefx[n]==tx&&prefy[n]==ty) return 0;

	int ret=INT_MAX;
	REP(i,n) { // i is last index we change
		if(!can(0,i)) continue;
		int l=0,h=i+1; while(l+1<h) { int m=l+(h-l)/2; if(can(m,i)) l=m; else h=m; }
		int cur=i-l+1; ret=min(ret,cur);
	}
	return ret==INT_MAX?-1:ret;
}

void run() {
	scanf("%d",&n); scanf("%s",s); scanf("%d%d",&tx,&ty);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}