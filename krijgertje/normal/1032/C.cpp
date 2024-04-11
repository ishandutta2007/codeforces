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
const int MAXVAL=5;

int n;
int a[MAXN];
int b[MAXN];

int act[MAXN][MAXVAL]; // act[i][j] = pj when it is possibly to play the ith note with the jth finger (pj is the finger that could have played the (i-1)th note or MAXVAL if no such note)

bool solve() {
	memset(act,-1,sizeof(act));
	REP(j,MAXVAL) act[0][j]=MAXVAL;
	FOR(i,1,n) REP(j,MAXVAL) REP(pj,MAXVAL) if(act[i-1][pj]!=-1) {
		if(a[i-1]<a[i]&&pj>=j) continue;
		if(a[i-1]>a[i]&&pj<=j) continue;
		if(a[i-1]==a[i]&&pj==j) continue;
		act[i][j]=pj; break;
	}
	REP(tj,MAXVAL) if(act[n-1][tj]!=-1) {
		for(int i=n-1,j=tj;i>=0;j=act[i][j],--i) b[i]=j;
		return true;
	}
	return false;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("-1\n"); return; }
	REP(i,n) { if(i!=0) printf(" "); printf("%d",b[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}