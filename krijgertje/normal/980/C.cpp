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

int n,lim;
int a[MAXN];

int leader[256];


void run() {
	scanf("%d%d",&n,&lim); REP(i,n) scanf("%d",&a[i]);
	
	REP(i,256) leader[i]=-1;
	REP(i,n) if(leader[a[i]]==-1) {
		int gmn=max(0,a[i]-lim+1);
		int at=a[i]; while(leader[at]==-1&&at-1>=gmn) --at;
		if(leader[at]!=-1&&a[i]<=leader[at]+lim-1) {
			//printf("%d: a=%d at=%d leader[at]=%d\n",i,a[i],at,leader[at]);
			int id=leader[at];
			FORE(j,at+1,a[i]) leader[j]=id;
		} else {
			if(leader[at]!=-1) ++at;
			assert(leader[at]==-1);
			int id=at;
			FORE(j,at,a[i]) leader[j]=id;
		}
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",leader[a[i]]); } puts("");
}

int main() {
	run();
	return 0;
}