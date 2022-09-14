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

const int MAXH=200;
const int MAXW=200;
const int MAXN=MAXH*MAXW;
const int MAXLEN=1000000;

int h,w,n,nq;
char g[MAXH][MAXW];
int dx[10],dy[10];

int gnxt[MAXN];
bool been[MAXN];
int cmask[MAXN],croot[MAXN];
int thead[MAXN],tnxt[MAXN];

char s[MAXLEN+1]; int slen;
bool dfs(int at,int pos) {
	if(pos<0) return true;
	for(int x=thead[at];x!=-1;x=tnxt[x]) if(dfs(x,pos-(g[x/w][x%w]==s[pos]?1:0))) return true;
	return false;
}
bool test() {
	REP(rt,n) if(croot[rt]==rt) {
		int pos=slen-1;
		while(pos>=0&&(cmask[rt]&(1<<(s[pos]-'0')))!=0) --pos;
		if(dfs(rt,pos)) return true;
	}
	return false;
}

void run() {
	scanf("%d%d%d",&h,&w,&nq); n=h*w;
	REP(x,h) REP(y,w) scanf(" %c",&g[x][y]);
	REP(k,10) scanf("%d%d",&dx[k],&dy[k]);
	REP(x,h) REP(y,w) { int k=g[x][y]-'0'; int nx=x+dx[k],ny=y+dy[k];gnxt[x*w+y]=0<=nx&&nx<h&&0<=ny&&ny<w?nx*w+ny:x*w+y; }
	//REP(i,n) printf("%d -> %d\n",i,gnxt[i]);
	memset(been,false,sizeof(been)); memset(cmask,0,sizeof(cmask)); memset(croot,-1,sizeof(croot));
	REP(i,n) if(!been[i]) {
		int at=i; while(!been[at]) { been[at]=true; at=gnxt[at]; }
		if(croot[at]==-1) { int rt=at; while(croot[at]==-1) { croot[at]=rt; cmask[rt]|=1<<(g[at/w][at%w]-'0'); at=gnxt[at]; } }
		at=i; while(croot[at]==-1) { croot[at]=-2; at=gnxt[at]; }
	}
	//REP(i,n) if(croot[i]==i) { printf("%d: ",i); REP(j,10) printf("%c",(cmask[i]>>j&1)?'v':'.'); puts(""); }
	REP(i,n) thead[i]=-1; REP(i,n) if(croot[i]==-2) { int par=croot[gnxt[i]]==-2?gnxt[i]:croot[gnxt[i]]; tnxt[i]=thead[par]; thead[par]=i; }
	//REP(i,n) if(croot[i]==-2||croot[i]==i) { printf("%d:",i); for(int x=thead[i];x!=-1;x=tnxt[x]) printf(" %d",x); puts(""); }
	REP(qi,nq) {
		scanf("%s",s); slen=strlen(s);
		printf("%s\n",test()?"YES":"NO");
	}
}

int main() {
	run();
	return 0;
}