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

const int MAXN=100000;

int n,sz;
char s[MAXN+1];

int nxtonorafter[2][MAXN];
int lstonorbefore[2][MAXN];

int solve() {
	REP(i,n) REP(x,2) lstonorbefore[x][i]=s[i]=='0'+x?i:i-1<0?-1:lstonorbefore[x][i-1];
	for(int i=n-1;i>=0;--i) REP(x,2) nxtonorafter[x][i]=s[i]=='0'+x?i:i+1>=n?-1:nxtonorafter[x][i+1];

	REPE(i,n-sz) REP(x,2) {
		bool ok=true;
		if(i-1>=0&&lstonorbefore[1-x][i-1]!=-1) ok=false;
		if(i+sz<n&&nxtonorafter[1-x][i+sz]!=-1) ok=false;
		if(ok) return +1;
	}
	REPE(i,n-sz) REP(x,2) {
		int lstbefore=i-1<0?-1:lstonorbefore[1-x][i-1];
		int nxtafter=i+sz>=n?-1:nxtonorafter[1-x][i+sz];
		if(lstbefore!=-1&&nxtafter!=-1) return 0;
		assert(lstbefore!=-1||nxtafter!=-1);
		if(lstbefore!=-1&&lstbefore-nxtonorafter[1-x][0]+1>sz) return 0;
		if(nxtafter!=-1&lstonorbefore[1-x][n-1]-nxtafter+1>sz) return 0;
	}
	return -1;
}

void run() {
	scanf("%d%d",&n,&sz);
	scanf("%s",s); assert(strlen(s)==n);
	int ans=solve();
	printf("%s\n",ans==+1?"tokitsukaze":ans==-1?"quailty":"once again");
}

int main() {
	run();
	return 0;
}