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

const int MAXN=500;

int n;
int x[MAXN];

int mem[MAXN][MAXN][2];
int go(int a,int b,int c) {
	if(a>b) return 0;
	if(a==b) return c==0?1:0;
	int &ret=mem[a][b][c];
	if(ret==-1) {
		ret=INT_MAX;
		if(x[a]==x[b]) ret=go(a+1,b-1,1)+(c==0?1:0);
		FOR(i,a,b) {
			int cura=go(a,i,c)+go(i+1,b,0); if(cura<ret) ret=cura;
			int curb=go(a,i,0)+go(i+1,b,c); if(curb<ret) ret=curb;
		}
		//printf("%d..%d (%d) = %d\n",a,b,c,ret);
	}
	return ret;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	memset(mem,-1,sizeof(mem));
	int ret=go(0,n-1,0); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}