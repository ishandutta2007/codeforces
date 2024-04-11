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

int n,maxt;
int t[2000],v[2000];

int fst[101],nxt[2000];
int cur[1000],ncur;

void run() {
	scanf("%d%d",&n,&maxt); REP(i,n) scanf("%d%d",&t[i],&v[i]);
	FORE(i,1,100) fst[i]=-1;
	REP(i,n) { nxt[i]=fst[t[i]]; fst[t[i]]=i; }
	
	int ret=0;
	FORE(i,1,maxt) {
		ncur=0; for(int x=fst[i];x!=-1;x=nxt[x]) cur[ncur++]=v[x]; if(ncur%2==1) cur[ncur++]=0;
		sort(cur,cur+ncur);
		if(i==maxt) { if(ncur>0) ret=cur[ncur-1]; break; }
		for(int j=0;j<ncur;j+=2) {
			v[n]=cur[j]+cur[j+1]; nxt[n]=fst[i+1]; fst[i+1]=n; ++n;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}