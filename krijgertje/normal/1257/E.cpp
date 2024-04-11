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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=200000;

int na,nb,nc;
int a[MAXN];
int b[MAXN];
int c[MAXN];

int n;
int who[MAXN];

int pref[MAXN+1]; // give problems < i to first person
int suff[MAXN+1]; // give problems >= i to last person

int solve() {
	n=na+nb+nc;
	REP(i,n) who[i]=-1; REP(i,na) who[a[i]]=0; REP(i,nb) who[b[i]]=1; REP(i,nc) who[c[i]]=2;
	//printf("who:"); REP(i,n) printf(" %d",who[i]); puts("");

	pref[0]=0; REP(i,n) pref[i+1]=pref[i]+(who[i]==1?1:0);
	int rema=na; REP(i,n) pref[i]+=rema,rema-=(who[i]==0?1:0);
	suff[n]=0; for(int i=n-1;i>=0;--i) suff[i]=suff[i+1]+(who[i]==1?1:0);
	int remc=nc; for(int i=n-1;i>=0;--i) suff[i+1]+=remc,remc-=(who[i]==2?1:0);
	//printf("pref:"); REPE(i,n) printf(" %d",pref[i]); puts("");
	//printf("suff:"); REPE(i,n) printf(" %d",suff[i]); puts("");
	
	int ret=INT_MAX,bestpref=INT_MAX;
	REPE(i,n) {
		bestpref=min(bestpref,pref[i]);
		int cur=bestpref+suff[i];
		//printf("%d: bestpref=%d suff=%d -> cur=%d\n",i,bestpref,suff[i],cur);
		ret=min(ret,cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&na,&nb,&nc);
	REP(i,na) scanf("%d",&a[i]),--a[i];
	REP(i,nb) scanf("%d",&b[i]),--b[i];
	REP(i,nc) scanf("%d",&c[i]),--c[i];
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}