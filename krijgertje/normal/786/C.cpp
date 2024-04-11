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

const int MAXN=100000;
const int MAXS=250;

// n=100000
// for k<=400, bruteforce
// => at most 250 segments left
// => increase k by 1 => update each segment

int n;
int x[MAXN];
int mark[MAXN],curmark;
int cnt[MAXN];

int l[MAXS],r[MAXS],ns;
int curs[MAXS];
int cnts[MAXS][MAXN];
int ret[MAXN+1];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x[i]),--x[i];
	//n=MAXN; REP(i,n) x[i]=rand()%n;
	memset(cnt,0,sizeof(cnt));
	memset(mark,-1,sizeof(mark)); curmark=0;
	memset(ret,-1,sizeof(ret));

	int k=1;
	for(;k<=n;++k) {
		int cur=k; ret[k]=0;
		REP(i,n) {
			if(mark[x[i]]!=curmark) mark[x[i]]=curmark,cnt[x[i]]=0;
			if(cur==k&&cnt[x[i]]==0) { ++ret[k]; cur=0; ++curmark; mark[x[i]]=curmark; }
			if(cnt[x[i]]++==0) ++cur;
		}
		++curmark;
		if(ret[k]<=MAXS) break;
	}
	if(k<=n) {
		{
			ns=1; l[0]=0,r[0]=0,curs[0]=1; ++cnts[0][x[0]];
			FOR(i,1,n) {
				if(curs[ns-1]==k&&cnts[ns-1][x[i]]==0) { l[ns++]=i; curs[ns-1]=0; }
				if(cnts[ns-1][x[i]]++==0) ++curs[ns-1];
				r[ns-1]=i;
			}
		}
		//printf("ns=%d\n",ns); REP(i,ns) printf("%d..%d=%d\n",l[i],r[i],curs[i]);
		for(++k;k<=n;++k) {
			REP(i,ns) {
				if(i!=0) while(l[i]<=r[i-1]) {
					if(r[i]==l[i]-1) { ++l[i],++r[i]; continue; }
					if(--cnts[i][x[l[i]++]]==0) --curs[i];
				}
				while(r[i]+1<n&&(curs[i]<k||cnts[i][x[r[i]+1]]>0)) {
					if(cnts[i][x[++r[i]]]++==0) ++curs[i];
					//printf("increased right of %d to %d (%d)\n",i,r[i],curs[i]);
				}
			}
			while(ns>=2&&r[ns-2]==n-1) --ns;
			//printf("k=%d:",k); REP(i,ns) printf(" %d..%d",l[i],r[i]); puts("");
			ret[k]=ns;
		}
	}



	FORE(i,1,n) { if(i!=1) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}