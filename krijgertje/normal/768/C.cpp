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
const int MAXBIT=9;

int n,times,mask;
int a[MAXN];
int cnt[2][1<<(MAXBIT+1)];

void run() {
	scanf("%d%d%d",&n,&times,&mask); REP(i,n) scanf("%d",&a[i]);
	int at=0; memset(cnt,0,sizeof(cnt)); REP(i,n) ++cnt[at][a[i]];
	REP(t,times) {
		int par=0; memset(cnt[1-at],0,sizeof(cnt[1-at]));
		REP(i,1<<(MAXBIT+1)) {
			int now=(cnt[at][i]+1-par)/2;
			cnt[1-at][i^mask]+=now; cnt[1-at][i]+=cnt[at][i]-now; par=(par+cnt[at][i])%2;
		}
		at=1-at;
	}
	int mn=INT_MAX,mx=INT_MIN; REP(i,1<<(MAXBIT+1)) if(cnt[at][i]>0) { if(i<mn) mn=i; if(i>mx) mx=i; }
	printf("%d %d\n",mx,mn);
}

int main() {
	run();
	return 0;
}