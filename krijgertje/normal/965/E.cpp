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
const int MAXTOTLEN=100000;
struct TNode { int nxt[26]; int bal,par,dep; };


int n;
char s[MAXTOTLEN+1];
int off[MAXN+1],len[MAXN];

TNode t[MAXTOTLEN+1]; int nt,troot;
int maket(int par) { int ret=nt++; memset(t[ret].nxt,-1,sizeof(t[ret].nxt)); t[ret].bal=0; t[ret].par=par; t[ret].dep=par==-1?0:t[par].dep+1; return ret; }

int q[MAXTOTLEN+1],qhead,qtail;

bool canmake(int at) { while(at!=-1) { if(t[at].bal<=0) return false; at=t[at].par; } return true; }
void make(int at) { while(at!=-1) { --t[at].bal; at=t[at].par; } }

void run() {
	scanf("%d",&n);
	off[0]=0; REP(i,n) { scanf("%s",s+off[i]); len[i]=strlen(s+off[i]); off[i+1]=off[i]+len[i]; }

	nt=0; troot=maket(-1);
	REP(i,n) {
		int at=troot; ++t[at].bal;
		REP(j,len[i]) {
			int x=s[off[i]+j]-'a';
			if(t[at].nxt[x]==-1) t[at].nxt[x]=maket(at);
			at=t[at].nxt[x]; ++t[at].bal;
		}
	}

	qhead=qtail=0;
	REP(i,26) if(t[troot].nxt[i]!=-1) q[qhead++]=t[troot].nxt[i];
	int ret=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		if(!canmake(at)) continue;
		make(at); ret+=t[at].dep;
		REP(i,26) if(t[at].nxt[i]!=-1) q[qhead++]=t[at].nxt[i];
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}