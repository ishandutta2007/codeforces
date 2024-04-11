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

int n,m;
int fst[3000];
int nxt[30000];
int to[30000];
int cnt[3000][3000];

void run() {
	memset(fst,-1,sizeof(fst)); memset(cnt,0,sizeof(cnt));
	scanf("%d%d",&n,&m);
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; nxt[i]=fst[a]; to[i]=b; ++cnt[a][b]; fst[a]=i; }
	int ret=0;
	REP(a,n) REP(c,n) if(a!=c) {
		int bd=0;
		for(int x=fst[a];x!=-1;x=nxt[x]) { bd+=cnt[to[x]][c]; }
		//printf("%d->x->%d: %d\n",a,c,bd);
		ret+=bd*(bd-1)/2;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}