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

const int MAXN=300000;

int n,need[2];
int cap[MAXN];

int retcnt[2];
int ret[2][MAXN];

pair<int,int> o[MAXN];

bool solve() {
	REP(i,n) o[i]=MP(-cap[i],i); sort(o,o+n); REP(i,n) o[i].first=-o[i].first;
	//printf("o: "); REP(i,n) printf(" %d",o[i].first); puts("");
	REP(fst,2) {
		int a=need[fst],b=need[1-fst];
		int at=0;
		REP(i,n) if((ll)(i+1)*o[i].first>=a) {
			if(at<i) at=i;
			while(at<n&&(ll)(at-i)*o[at].first<b) ++at;
			if(at>=n) break;
			retcnt[fst]=i+1,retcnt[1-fst]=at-i;
			REPE(j,i) ret[fst][j]=o[j].second; FORE(j,i+1,at) ret[1-fst][j-(i+1)]=o[j].second;
			return true;
		}
	}
	return false;
}

void run() {
	scanf("%d%d%d",&n,&need[0],&need[1]); REP(i,n) scanf("%d",&cap[i]);
	if(!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	printf("%d %d\n",retcnt[0],retcnt[1]);
	REP(i,2) { REP(j,retcnt[i]) { if(j!=0) printf(" "); printf("%d",ret[i][j]+1); } puts(""); }
}

int main() {
	run();
	return 0;
}