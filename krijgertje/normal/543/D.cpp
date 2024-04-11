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
const int MAXM=MAXN-1;
const int MOD=1000000007;
const inline int mymult(int a,int b) { return (ll)a*b%MOD; }
const inline int myadd(int a,int b) { a+=b; if(a>=MOD) a-=MOD; return a; }

int n;
int fst[MAXN],lst[MAXN],prv[2*MAXM],nxt[2*MAXM],to[2*MAXM];

int upto[MAXN];
int wayspre[2*MAXM],wayspost[2*MAXM];

int ways[2*MAXM];

int xxx=0;
int calc(int x) {
	//printf("calc(%d->%d)\n",to[x^1],to[x]);
	int at=to[x];
	if(ways[x]!=-1) return ways[x];
	if(upto[at]==-1) {
		//printf("calc upto %d->%d\n",to[x],to[x^1]);
		upto[at]=x^1;
		int cur=1;
		for(int y=fst[at];y!=-1;y=nxt[y]) {
			wayspre[y]=cur;
			if(y==upto[at]) break;
			cur=mymult(cur,calc(y));
		}
		cur=1;
		for(int y=lst[at];y!=-1;y=prv[y]) {
			wayspost[y]=cur;
			if(y==upto[at]) break;
			cur=mymult(cur,calc(y));
		}
	} else if(upto[at]!=-2) {
		//printf("calc remainder %d->%d\n",to[upto[at]^1],to[upto[at]]);
		int cur=wayspre[upto[at]];
		for(int y=upto[at];y!=-1;y=nxt[y]) {
			wayspre[y]=cur;
			cur=mymult(cur,calc(y));
		}
		cur=wayspost[upto[at]];
		for(int y=upto[at];y!=-1;y=prv[y]) {
			wayspost[y]=cur;
			cur=mymult(cur,calc(y));
		}
		upto[at]=-2;
	}

	/*int want=1;
	for(int y=fst[at];y!=-1;y=nxt[y]) {
		if(y==(x^1)) continue;
		want=mymult(want,calc(y));
	} 
	want=myadd(want,1); */

	ways[x]=myadd(mymult(wayspre[x^1],wayspost[x^1]),1);
	//printf("calced(%d->%d) -> %d\n",to[x^1],to[x],ways[x]);
	return ways[x];
}

int ret[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) fst[i]=lst[i]=-1;
	REP(i,n-1) {
		int a=i+1,b; scanf("%d",&b); --b;
		prv[2*i+0]=lst[a]; lst[a]=2*i+0; nxt[2*i+0]=-1; if(prv[2*i+0]==-1) fst[a]=2*i+0; else nxt[prv[2*i+0]]=2*i+0; to[2*i+0]=b;
		prv[2*i+1]=lst[b]; lst[b]=2*i+1; nxt[2*i+1]=-1; if(prv[2*i+1]==-1) fst[b]=2*i+1; else nxt[prv[2*i+1]]=2*i+1; to[2*i+1]=a;
	}

	memset(ways,-1,sizeof(ways));
	memset(upto,-1,sizeof(upto));
	REP(i,n) {
		ret[i]=1;
		for(int x=fst[i];x!=-1;x=nxt[x]) ret[i]=mymult(ret[i],calc(x));
	}

	//REP(i,n) printf("%d\n",ret[i]);
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}