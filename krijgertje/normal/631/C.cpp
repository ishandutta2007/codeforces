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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
int x[MAXN];
int dir[MAXM],cnt[MAXM];

int stck[MAXM],nstck;
int ret[MAXN];

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,m) scanf("%d%d",&dir[i],&cnt[i]);
	nstck=0; REP(i,m) { while(nstck>0&&cnt[i]>=cnt[stck[nstck-1]]) --nstck; stck[nstck++]=i; }
	memset(ret,-1,sizeof(ret));
	FOR(i,cnt[stck[0]],n) ret[i]=x[i];
	int l=0,r=cnt[stck[0]],at=cnt[stck[0]]; sort(x+l,x+r);
	REP(i,nstck) {
		int cur=cnt[stck[i]]-(i==nstck-1?0:cnt[stck[i+1]]);
		REP(j,cur) if(dir[stck[i]]==1) ret[--at]=x[--r]; else ret[--at]=x[l++];
	}
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}