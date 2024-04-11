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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n;
int a[100000];
int before[100000];
int after[100000];
bool atleastone[100000];
int poscnt[100000];
int ret[100000];

int lis[100000],nlis;
int addlis(int x) {
	int l=-1,h=nlis;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(lis[m]<x) l=m; else h=m;
	}
	lis[h]=x; if(h==nlis) nlis++;
	return h+1;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	nlis=0; REP(i,n) before[i]=addlis(a[i]);
	nlis=0; for(int i=n-1;i>=0;--i) after[i]=addlis(100000-a[i]);

	int maxlis=nlis;
	REP(i,n) atleastone[i]=before[i]+after[i]-1==maxlis;
	memset(poscnt,0,sizeof(poscnt));
	REP(i,n) if(atleastone[i]) ++poscnt[before[i]-1];
	REP(i,n) if(!atleastone[i]) ret[i]=1; else if(poscnt[before[i]-1]==1) ret[i]=3; else ret[i]=2;
	//REP(i,n) printf("%d: %d/%d %c (%d)\n",i,before[i],after[i],atleastone[i]?'V':'X',poscnt[before[i]-1]);
	REP(i,n) printf("%d",ret[i]); puts("");
}

int main() {
	run();
	return 0;
}