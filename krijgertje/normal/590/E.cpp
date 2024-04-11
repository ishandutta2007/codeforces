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

const int MAXN=750;
const int MAXLEN=10000000;

typedef struct Node { int nxt[2],anxt[2],str,pstr,fail,par; } Node;

int nfriend;
char s[MAXLEN+1];

int nnode,root;
Node node[MAXLEN+1];
int getnode(int par) { node[nnode].nxt[0]=node[nnode].nxt[1]=node[nnode].str=node[nnode].pstr=node[nnode].fail=-1,node[nnode].par=par; return nnode++; }
void printtree(int at,int d) {
	REP(i,2) if(node[at].nxt[i]!=-1) {
		REP(j,d) printf("  ");
		printf("%d=%c[->%d]",node[at].nxt[i],'a'+i,node[node[at].nxt[i]].fail);
		if(node[node[at].nxt[i]].str!=-1) printf("(%d)",node[node[at].nxt[i]].str);
		if(node[node[at].nxt[i]].pstr!=-1) printf("{%d}",node[node[at].nxt[i]].pstr);
		puts("");
		printtree(node[at].nxt[i],d+1);
	}
}

int nstr;
int frnd[MAXN];
int lst[MAXN];

int qhead,qtail,q[MAXLEN+1];

bool adj[MAXN][MAXN];
int lmatch[MAXN],rmatch[MAXN];
bool done[MAXN];
bool augment(int at) {
	if(done[at]) return false; else done[at]=true;
	REP(to,nstr) if(adj[at][to]&&(rmatch[to]==-1||augment(rmatch[to]))) { lmatch[at]=to; rmatch[to]=at; return true; }
	return false;
}

int ret[MAXN],nret;

void run() {
	nnode=nstr=nret=0,root=getnode(-1);
	scanf("%d",&nfriend);
	REP(i,nfriend) {
		scanf("%s",s);
		int at=root; for(int j=0;s[j]!='\0';++j) { if(node[at].nxt[s[j]-'a']==-1) node[at].nxt[s[j]-'a']=getnode(at); at=node[at].nxt[s[j]-'a']; }
		if(node[at].str==-1) frnd[nstr]=i+1,lst[nstr]=at,node[at].str=nstr++;
	}
	qhead=qtail=0; node[root].fail=root; q[qhead++]=root;
	while(qtail<qhead) {
		int at=q[qtail++];
		node[at].pstr=node[node[at].fail].str!=-1?node[node[at].fail].str:node[node[at].fail].pstr;
		REP(i,2) if(node[at].nxt[i]==-1) {
			node[at].anxt[i]=at==root?root:node[node[at].fail].anxt[i];
		} else {
			node[at].anxt[i]=node[at].nxt[i];
			node[node[at].nxt[i]].fail=at==root?root:node[node[at].fail].anxt[i];
			q[qhead++]=node[at].nxt[i];
		}
	}
	//printtree(root,0);
	memset(adj,false,sizeof(adj));
	REP(i,nstr) for(int at=lst[i];at!=root;at=node[at].par) for(int j=node[at].str!=-1?node[at].str:node[at].pstr;j!=-1&&!adj[j][i];j=node[lst[j]].pstr) adj[j][i]=true;
	REP(i,nstr) adj[i][i]=false;
	//if(nfriend>=10) REP(i,nstr) { REP(j,nstr) printf("%c",adj[i][j]?'V':'.'); puts(""); }
	REP(i,nstr) lmatch[i]=rmatch[i]=-1,done[i]=false;
	REP(i,nstr) if(augment(i)) REP(j,nstr) done[j]=false;
	//if(nfriend>=10) REP(i,nstr) printf("%d=%d / %d\n",i,lmatch[i],rmatch[i]);
	REP(i,nstr) if(lmatch[i]==-1) assert(!augment(i));
	//if(nfriend>=10) REP(i,nstr) printf("%d: %c %c\n",i,!done[i]?'X':'.',rmatch[i]!=-1&&done[rmatch[i]]?'X':'.');
	REP(i,nstr) if(done[i]&&(rmatch[i]==-1||!done[rmatch[i]])) ret[nret++]=frnd[i];
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}