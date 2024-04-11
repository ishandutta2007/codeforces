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

const int MAXN=100;
const int MAXVAL=100;

int n,mxval;
int cnt[MAXVAL+2];
int ret[MAXVAL],nret;

void run() {
	scanf("%d%d",&n,&mxval);
	FORE(i,1,mxval+1) cnt[i]=0;
	REP(i,n) { int l,r; scanf("%d%d",&l,&r); ++cnt[l],--cnt[r+1]; }
	FORE(i,1,mxval) cnt[i+1]+=cnt[i];
	nret=0; FORE(i,1,mxval) if(cnt[i]==0) ret[nret++]=i;
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}