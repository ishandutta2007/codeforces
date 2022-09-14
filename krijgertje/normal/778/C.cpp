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

const int MAXN=300000;
const int MAXM=MAXN-1;

int n;
int chead[MAXN],cnxt[MAXM],cto[MAXM]; char csym[MAXM];

int nxt[MAXN][26];
int tmp[MAXN][26];
int mark[MAXN][26],curmark;
int sz[MAXN];
int res[MAXN];

int merge(int a,int b) { // merge a into b
	int ret=1;
	for(int x=chead[a];x!=-1;x=cnxt[x]) {
		int ato=cto[x]; int z=csym[x]-'a';
		if(nxt[b][z]!=-1) { ret+=merge(ato,nxt[b][z]); continue; }
		if(mark[b][z]!=curmark) mark[b][z]=curmark,tmp[b][z]=-1;
		if(tmp[b][z]!=-1) { ret+=merge(ato,tmp[b][z]); continue; }
		tmp[b][z]=ato;
	}
	return ret;
}
void go(int at,int d) {
	int heavy=-1;
	for(int x=chead[at];x!=-1;x=cnxt[x]) {
		int to=cto[x];
		go(to,d+1);
		if(heavy==-1||sz[to]>sz[heavy]) heavy=to;
	}
	int cur=0;
	if(heavy!=-1) {
		++curmark; ++cur;
		for(int x=chead[at];x!=-1;x=cnxt[x]) {
			int to=cto[x]; if(to==heavy) continue;
			cur+=merge(to,heavy);
		}
	}
	res[d]+=cur;
	//printf("%d (%d): %d\n",at+1,d+1,cur);
}

int q[MAXN],qhead,qtail;

void run() {
	scanf("%d",&n);
	REP(i,n) chead[i]=-1;
	REP(i,n-1) { int a,b; char c; scanf("%d%d %c",&a,&b,&c); --a,--b; cnxt[i]=chead[a]; chead[a]=i; cto[i]=b; csym[i]=c; }
	memset(nxt,-1,sizeof(nxt));
	REP(i,n) for(int x=chead[i];x!=-1;x=cnxt[x]) nxt[i][csym[x]-'a']=cto[x];
	qhead=qtail=0; q[qhead++]=0; while(qtail<qhead) { int at=q[qtail++]; for(int x=chead[at];x!=-1;x=cnxt[x]) q[qhead++]=cto[x]; } assert(qhead==n);
	REP(i,n) sz[i]=1; for(int i=n-1;i>=0;--i) { int at=q[i]; for(int x=chead[at];x!=-1;x=cnxt[x]) sz[at]+=sz[cto[x]]; }
	//REP(i,n) printf("%d ",sz[i]); puts("");
	memset(tmp,-1,sizeof(tmp));
	memset(mark,-1,sizeof(mark)); curmark=-1;
	REP(i,n) res[i]=0;
	go(0,0);
	int ret=INT_MAX,retd=-1; REP(i,n) { int cur=n-res[i]; if(cur<ret||cur==ret&&i<retd) ret=cur,retd=i; }
	printf("%d\n%d\n",ret,retd+1);
}

int main() {
	run();
	return 0;
}