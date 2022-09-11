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

const int MAXWORDS=100000;
const int MAXLETTERS=100000;
const int MAXLENSUM=100000;

int nwords,nletters;
int off[MAXWORDS+1],len[MAXWORDS],s[MAXLENSUM];

bool ok;
int state[MAXLETTERS];
vector<int> impl[MAXLETTERS];
int q[MAXLETTERS],qhead,qtail;
int ret[MAXLETTERS],nret;

void seterr() {
	//printf("err\n");
	ok=false;
}
void setval(int a,bool val) {
	//printf("%d=%s\n",a+1,val?"YES":"NO");
	if(state[a]!=-1&&state[a]!=(val?1:0)) seterr(); else state[a]=(val?1:0);
}
void addimpl(int a,int b) {
	//printf("%d=>%d\n",a+1,b+1);
	impl[a].PB(b);
}

void solve(int l,int r,int pos) {
	while(l<=r&&pos>=len[l]) ++l; if(l>=r) return;
	FORE(i,l,r) if(pos>=len[i]) { seterr(); return; }
	bool have=false;
	FORE(i,l+1,r) {
		int a=s[off[i-1]+pos],b=s[off[i]+pos];
		if(a==b) continue;
		if(a<b) addimpl(b,a); else if(have) seterr(); else setval(a,true),setval(b,false),have=true;
	}
	for(int at=l,to=at;at<=r;at=to) {
		while(to<=r&&s[off[at]+pos]==s[off[to]+pos]) ++to;
		solve(at,to-1,pos+1);
	}
}

void run() {
	scanf("%d%d",&nwords,&nletters);
	off[0]=0; REP(i,nwords) { scanf("%d",&len[i]); REP(j,len[i]) scanf("%d",&s[off[i]+j]); off[i+1]=off[i]+len[i]; }
	REP(i,off[nwords]) --s[i];

	ok=true; REP(i,nletters) state[i]=-1,impl[i].clear();
	solve(0,nwords-1,0);
	qhead=qtail=0; nret=0;
	REP(i,nletters) if(state[i]==1) q[qhead++]=i;
	while(qtail<qhead) {
		int at=q[qtail++]; ret[nret++]=at;
		REPSZ(i,impl[at]) { int to=impl[at][i]; if(state[to]==-1) state[to]=1,q[qhead++]=to; else if(state[to]!=1) seterr(); }
	}
	if(!ok) { printf("No\n"); return; }
	printf("Yes\n%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%d",ret[i]+1); } puts("");
}

int main() {
	run();
	return 0;
}