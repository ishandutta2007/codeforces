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

const int MAXN=500000;
const int MAXDEPTH=MAXN;

int n,nq;
int par[MAXN];
char s[MAXN+1];

int head[MAXN],nxt[MAXN];

int d[MAXN];
int didx[MAXN];
int tin[MAXN],tout[MAXN],t;

int dorder[MAXN];
int dfst[MAXDEPTH+1],dcnt[MAXDEPTH];

int cnt[MAXN+1][26];

void dfs(int at) {
	tin[at]=t++;
	d[at]=par[at]==-1?0:d[par[at]]+1;
	didx[at]=dcnt[d[at]]++;
	for(int to=head[at];to!=-1;to=nxt[to]) dfs(to);
	tout[at]=t++;
}

void run() {
	scanf("%d%d",&n,&nq);
	par[0]=-1; FOR(i,1,n) scanf("%d",&par[i]),--par[i];
	scanf("%s",s);

	REP(i,n) head[i]=-1,dcnt[i]=0;
	REP(i,n) if(par[i]!=-1) { nxt[i]=head[par[i]]; head[par[i]]=i; }
	t=0; dfs(0);
	dfst[0]=0; REP(i,n) dfst[i+1]=dfst[i]+dcnt[i];
	REP(i,n) dorder[dfst[d[i]]+didx[i]]=i;

	REP(j,26) cnt[0][j]=0;
	REP(i,n) { REP(j,26) cnt[i+1][j]=cnt[i][j]; cnt[i+1][s[dorder[i]]-'a']++; }
	

	REP(qi,nq) {
		int x,d; scanf("%d%d",&x,&d); --x,--d;
		int l=dfst[d]-1,h=dfst[d+1]; // (l,h] first on depth d with tin>=tin[x]
		while(l+1<h) { int m=l+(h-l)/2; if(tin[dorder[m]]<tin[x]) l=m; else h=m; }
		int L=dfst[d]-1,H=dfst[d+1]; // [l,h) last on depth d with tout<=tout[x]
		while(L+1<H) { int M=L+(H-L)/2; if(tout[dorder[M]]>tout[x]) H=M; else L=M; }
		if(h>=dfst[d+1]||L<dfst[d]) { printf("Yes\n"); continue; } // no childs of x on depth d
		int a=h,b=L;
		int nodd=0; REP(i,26) if((cnt[b+1][i]-cnt[a][i])%2!=0) ++nodd;
		printf("%s\n",nodd<=1?"Yes":"No");
	}

}


int main() {
	run();
	return 0;
}