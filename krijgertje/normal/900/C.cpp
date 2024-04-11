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

int n;
int p[MAXN];
int r[MAXN];

int bcnt[MAXN+1];
ll bsum[MAXN+1];

int res[MAXN];

void bmod(int idx,int val) { ++idx; while(idx<=n) { ++bcnt[idx],bsum[idx]+=val; idx+=idx&-idx; } }
pair<int,ll> bget(int idx) { ++idx; pair<int,ll> ret=MP(0,0LL); while(idx>0) { ret.first+=bcnt[idx]; ret.second+=bsum[idx]; idx-=idx&-idx; } return ret; }

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&p[i]),--p[i];
	REP(i,n) r[p[i]]=i;
	memset(bcnt,0,sizeof(bcnt)); memset(bsum,0,sizeof(bsum)); memset(res,0,sizeof(res));
	for(int i=n-1;i>=0;--i) {
		pair<int,ll> cur=bget(r[i]);
		if(cur.first==0) --res[i];
		if(cur.first==1) ++res[(int)cur.second];
		bmod(r[i],i);
	}
	int ans=-1; REP(i,n) if(ans==-1||res[i]>res[ans]) ans=i; printf("%d\n",ans+1);
}

int main() {
	run();
	return 0;
}