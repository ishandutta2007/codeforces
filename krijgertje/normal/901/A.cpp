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

const int MAXH=100001;
const int MAXN=200001;

int h;
int cnt[MAXH];

int par1[MAXN],n1;
int par2[MAXN],n2;

void run() {
	scanf("%d",&h); ++h; REP(i,h) scanf("%d",&cnt[i]);
	int idx=0; while(idx<h&&(cnt[idx]==1||idx+1>=h||cnt[idx+1]==1)) ++idx;
	if(idx>=h) { printf("perfect\n"); return; }

	n1=0; par1[n1++]=-1; REP(i,h) par1[n1++]=i; REP(i,h) REP(j,cnt[i]-1) par1[n1++]=i;
	n2=0; par2[n2++]=-1; REP(i,h) par2[n2++]=i; par2[n2++]=idx; par2[n2++]=1+h; REP(i,h) REP(j,cnt[i]-1-(i==idx||i==idx+1?1:0)) par2[n2++]=i;
	printf("ambiguous\n");
	FOR(i,1,n1) { if(i!=1) printf(" "); printf("%d",par1[i]); } puts("");
	FOR(i,1,n2) { if(i!=1) printf(" "); printf("%d",par2[i]); } puts("");
}

int main() {
	run();
	return 0;
}