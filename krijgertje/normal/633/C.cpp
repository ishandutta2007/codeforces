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

const int MAXLEN=10000;
const int MAXM=100000;
const int MAXW=1000000;
typedef struct Node { int nxt[26]; int id; } Node;

int len; char s[MAXLEN+1];
int m; int pos[MAXM+1]; char p[MAXW+1];
Node nodes[MAXW+1]; int nnode;
int getnode() { int ret=nnode++; REP(i,26) nodes[ret].nxt[i]=-1; nodes[ret].id=-1; return ret; }
int dp[MAXLEN+1];

void run() {
	scanf("%d%s",&len,s);
	scanf("%d",&m); pos[0]=0; REP(i,m) { scanf("%s",p+pos[i]); pos[i+1]=pos[i]+strlen(p+pos[i]); }

	nnode=0; int root=getnode();
	REP(i,m) { int at=root; FOR(j,pos[i],pos[i+1]) { int x=tolower(p[j])-'a'; if(nodes[at].nxt[x]==-1) nodes[at].nxt[x]=getnode(); at=nodes[at].nxt[x]; } nodes[at].id=i; }

	memset(dp,-1,sizeof(dp)); dp[len]=-2;
	for(int i=len-1;i>=0;--i) {
		int at=root;
		if(dp[i+1]!=-1) for(int j=i;j>=0;--j) {
			int x=tolower(s[j])-'a';
			if(nodes[at].nxt[x]==-1) break;
			at=nodes[at].nxt[x];
			//printf("\t%d:%d\n",j,nodes[at].id);
			if(nodes[at].id!=-1) dp[j]=nodes[at].id;
		}
		//printf("dp[%d]=%d\n",i,dp[i]);
	}
	if(dp[0]==-1) { printf("no sol\n"); return; }
	for(int i=0;i!=len;i+=pos[dp[i]+1]-pos[dp[i]]) { if(i!=0) printf(" "); FOR(j,pos[dp[i]],pos[dp[i]+1]) printf("%c",p[j]); } puts("");
}

int main() {
	run();
	return 0;
}