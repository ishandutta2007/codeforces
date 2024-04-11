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
const int MAXW=100000;
const int MOD=1000000007;

typedef struct S { int x,l,r,dx; } S;
bool operator<(const S &a,const S &b) { return a.x<b.x; }

int h,w,n;
S s[MAXN];

int init[MAXW];
int nxt[MAXN][2];
int dp[MAXN];
vector<pair<int,int> > sval[4*MAXW];

int better(int a,int b) { if(a==-1) return b; if(b==-1) return a; return s[a].x>=s[b].x?a:b; }
int sget(int x,int l,int r,int IDX,int X) {
	while(SZ(sval[x])>0&&sval[x][SZ(sval[x])-1].first<X) sval[x].pop_back();
	//printf("sget(%d=%d..%d,%d,%d):",x,l,r,IDX,X); REPSZ(i,sval[x]) printf(" %d=%d",sval[x][i].first,sval[x][i].second); puts("");
	int mine=SZ(sval[x])>0?sval[x][SZ(sval[x])-1].second:-1;
	if(l==r) return mine;
	int m=l+(r-l)/2;
	int other=IDX<=m?sget(2*x+1,l,m,IDX,X):sget(2*x+2,m+1,r,IDX,X);
	return better(mine,other);
}
void sset(int x,int l,int r,int L,int R,int X,int VAL) {
	if(L<=l&&r<=R) {
		while(SZ(sval[x])>0&&sval[x][SZ(sval[x])-1].first<=X) sval[x].pop_back();
		sval[x].push_back(MP(X,VAL));
		//printf("sset(%d=%d..%d,%d..%d,%d,%d):",x,l,r,L,R,X,VAL); REPSZ(i,sval[x]) printf(" %d=%d",sval[x][i].first,sval[x][i].second); puts("");
	} else {
		int m=l+(r-l)/2;
		if(L<=m) sset(2*x+1,l,m,L,R,X,VAL);
		if(m+1<=R) sset(2*x+2,m+1,r,L,R,X,VAL);
	}
}


inline void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
void run() {
	scanf("%d%d%d",&h,&w,&n);
	REP(i,n) scanf("%d%d%d%d",&s[i].x,&s[i].l,&s[i].r,&s[i].dx),--s[i].l,--s[i].r;
	sort(s,s+n);

	int ei=0;
	REP(i,n) {
		//printf("processing segment at height %d\n",s[i].x);
		int q0=s[i].l!=0?s[i].l-1:s[i].r+1,q1=s[i].r!=w-1?s[i].r+1:s[i].l-1;
		nxt[i][0]=sget(0,0,w-1,q0,s[i].x); nxt[i][1]=sget(0,0,w-1,q1,s[i].x);
		//printf("-> %d %d\n",nxt[i][0],nxt[i][1]);
		sset(0,0,w-1,s[i].l,s[i].r,s[i].x+s[i].dx,i);
	}
	REP(x,w) init[x]=sget(0,0,w-1,x,h+1);
	//printf("init:"); REP(x,w) printf(" %d",init[x]); puts("");

	REP(i,n) dp[i]=0; int ret=0;
	REP(x,w) if(init[x]==-1) ++ret; else ++dp[init[x]];
	for(int i=n-1;i>=0;--i) REP(j,2) { int to=nxt[i][j]; if(to==-1) inc(ret,dp[i]); else inc(dp[to],dp[i]); }
	printf("%d\n",ret);
	
}

int main() {
	run();
	return 0;
}