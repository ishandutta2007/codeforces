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
const int MAXX=100000;

int n;
int x[MAXN];
int mndv[MAXX+1];
int cnt[MAXX+1];


void precalc() {
	REPE(i,MAXX) mndv[i]=-1;
	FORE(i,2,MAXX) if(mndv[i]==-1) { mndv[i]=i; if((ll)i*i<=MAXX) for(int j=i*i;j<=MAXX;j+=i) if(mndv[j]==-1) mndv[j]=i; }
}

void run() {
	precalc();
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) {
		while(x[i]!=1) {
			int p=mndv[x[i]]; while(x[i]%p==0) x[i]/=p; ++cnt[p];
		}
	}
	int ret=1; FORE(i,2,MAXX) if(cnt[i]>ret) ret=cnt[i]; printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}