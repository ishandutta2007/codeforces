#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXTLEN=200000;
const int MAXN=200000;
const int MAXSSUMLEN=200000;
const int MAXTRIE=MAXSSUMLEN+1;
const int ALPH=26;
struct TrieNode { int nxt[ALPH]; int suff,cnt,sum; };

char t[MAXTLEN+1]; int tlen;
int n;
int soff[MAXN],slen[MAXN];
char s[MAXSSUMLEN+1];

int root,ntrie;
TrieNode trie[MAXTRIE];
int maketrienode() { int ret=ntrie++; memset(trie[ret].nxt,-1,sizeof(trie[ret].nxt)); trie[ret].suff=-1,trie[ret].cnt=trie[ret].sum=0; return ret; }

int q[MAXTRIE],qhead,qtail;

vector<int> calc() {
	ntrie=0;
	root=maketrienode();
	REP(i,n) { int at=root; REP(j,slen[i]) { int x=s[soff[i]+j]-'a'; int to=trie[at].nxt[x]; if(to==-1) { to=maketrienode(); trie[at].nxt[x]=to; } at=to; } ++trie[at].cnt; }

	qhead=qtail=0; q[qhead++]=root;
	while(qtail<qhead) {
		int at=q[qtail++];
		trie[at].sum=trie[at].cnt+(trie[at].suff==-1?0:trie[trie[at].suff].sum);
		REP(x,ALPH) {
			int to=trie[at].nxt[x]; if(to==-1) continue;
			int suff=trie[at].suff; while(suff!=-1&&trie[suff].nxt[x]==-1) suff=trie[suff].suff; if(suff!=-1) suff=trie[suff].nxt[x]; trie[to].suff=suff==-1?root:suff;
			q[qhead++]=to;
		}
	}
	//REP(i,ntrie) { printf("trie%d: cnt=%d sum=%d suff=%d nxt=",i,trie[i].cnt,trie[i].sum,trie[i].suff); REP(j,ALPH) if(trie[i].nxt[j]!=-1) printf(" %c:%d",'a'+j,trie[i].nxt[j]); puts(""); }
	vector<int> ret(tlen+1,0);
	int at=root; ret[0]=trie[at].sum;
	REP(i,tlen) {
		int x=t[i]-'a';
		while(trie[at].nxt[x]==-1&&trie[at].suff!=-1) at=trie[at].suff;
		if(trie[at].nxt[x]!=-1) at=trie[at].nxt[x];
		ret[i+1]=trie[at].sum;
	}
	return ret;
}

ll solve() {
	vector<int> a=calc();
	reverse(t,t+tlen); REP(i,n) reverse(s+soff[i],s+soff[i]+slen[i]);
	vector<int> b=calc(); reverse(b.begin(),b.end());
	//printf("a:"); REPSZ(i,a) printf(" %d",a[i]); puts("");
	//printf("b:"); REPSZ(i,b) printf(" %d",b[i]); puts("");
	ll ret=0; REPE(i,tlen) ret+=(ll)a[i]*b[i]; return ret;
}

void run() {
	scanf("%s",t); tlen=strlen(t);
	scanf("%d",&n);
	soff[0]=0; REP(i,n) { scanf("%s",s+soff[i]); slen[i]=strlen(s+soff[i]); soff[i+1]=soff[i]+slen[i]; }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}