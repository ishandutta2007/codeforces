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

const int MAXN=1000;
const int MOD=1000000007;

int n;
char s[MAXN+1];
int x[26];

bool done[MAXN+1];
int ways[MAXN+1];
int mxlen[MAXN+1];
int mncnt[MAXN+1];

void go(int at) {
	done[at]=true; ways[at]=0,mxlen[at]=0,mncnt[at]=INT_MAX; int mnx=INT_MAX;
	if(at==n) { ways[at]=1; mxlen[at]=0; mncnt[at]=0; return; }
	FOR(to,at,n) {
		if(x[s[to]-'a']<mnx) mnx=x[s[to]-'a'];
		if(to-at+1>mnx) break;
		//printf("\t%d->%d\n",at,to+1);
		if(!done[to+1]) go(to+1);
		ways[at]=(ways[at]+ways[to+1])%MOD;
		mxlen[at]=max(mxlen[at],max(to-at+1,mxlen[to+1]));
		mncnt[at]=min(mncnt[at],1+mncnt[to+1]);
	}
	//printf("%d: %d %d %d\n",at,ways[at],mxlen[at],mncnt[at]);
}

void run() {
	scanf("%d%s",&n,s); REP(i,26) scanf("%d",&x[i]);
	memset(done,false,sizeof(done));
	go(0);
	printf("%d\n%d\n%d\n",ways[0],mxlen[0],mncnt[0]);
}

int main() {
	run();
	return 0;
}