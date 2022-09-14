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
typedef struct R { int nxt[26]; } R;

int n;
int c[MAXN];
char s[MAXN+1];
int head[MAXN],nxt[2*MAXM],to[2*MAXM];
R r[MAXN]; int ndiff[MAXN];

int ret[MAXN],nret,retval;

int merge(int &a,int b) {
	if(a==-1) { a=b; return 0; }
	int ret=1;
	REP(i,26) if(r[b].nxt[i]!=-1) ret+=merge(r[a].nxt[i],r[b].nxt[i]);
	return ret;
}

void dfs(int at,int par) {
	REP(i,26) r[at].nxt[i]=-1; ndiff[at]=1;
	for(int x=head[at];x!=-1;x=nxt[x]) {
		if(to[x]==par) continue;
		dfs(to[x],at);
		int sub=merge(r[at].nxt[s[to[x]]-'a'],to[x]);
		ndiff[at]+=ndiff[to[x]]-sub;
		//printf("\t%d: += %d-%d\n",at,ndiff[to[x]],sub);
	}
	if(ndiff[at]+c[at]>retval) retval=ndiff[at]+c[at],nret=0;
	if(ndiff[at]+c[at]==retval) ret[nret++]=at;
	//printf("%d: %d+%d = %d\n",at,ndiff[at],c[at],ndiff[at]+c[at]);
}


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&c[i]);
	scanf("%s",s);
	REP(i,n) head[i]=-1;
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		nxt[2*i+0]=head[a]; head[a]=2*i+0; to[2*i+0]=b;
		nxt[2*i+1]=head[b]; head[b]=2*i+1; to[2*i+1]=a;
	}
	
	retval=-1,nret=0;
	dfs(0,-1);
	printf("%d\n%d\n",retval,nret);
}


int main() {
	run();
	return 0;
}