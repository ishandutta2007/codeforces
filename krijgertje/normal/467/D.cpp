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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXHAVE=100000;
const int MAXDICT=100000;
const int MAXWORD=2*MAXDICT;
const int MAXHAVECHARS=100000;
const int MAXDICTCHARS=500000;

typedef struct W { int fst,val1,val2,bst,idx; } W;
bool operator<(const W &a,const W &b) { if(a.val1!=b.val1) return a.val1<b.val1; return a.val2<b.val2; }

int ndict,nword;
W w[MAXWORD];
int wnxt[MAXDICT];
int wto[MAXDICT];
int wmap[MAXWORD];

int nt,root;
int twrd[MAXDICTCHARS+1];
int tnxt[MAXDICTCHARS+1][26];
char buff[MAXDICTCHARS+1];
int gett() { int ret=nt++; twrd[ret]=-1; REP(i,26) tnxt[ret][i]=-1; return ret; }
int readt() {
	scanf("%s",buff);
	int at=root,len=strlen(buff),nr=0;
	REP(i,len) { int x=tolower(buff[i])-'a'; if('a'+x=='r') ++nr; if(tnxt[at][x]==-1) tnxt[at][x]=gett(); at=tnxt[at][x]; }
	//printf("%s -> %d %d\n",buff,nr,len);
	if(twrd[at]!=-1) return twrd[at];
	int ret=twrd[at]=nword++; w[ret].val1=nr; w[ret].val2=len; w[ret].fst=-1; w[ret].bst=-1; w[ret].idx=ret; return ret;
}

int nhave;
int havestart[MAXHAVE],havelen[MAXHAVE];
char have[MAXHAVECHARS+1];

int q[MAXWORD],qhead,qtail;

void run() {
	scanf("%d",&nhave);
	REP(i,nhave) { havestart[i]=i==0?0:havestart[i-1]+havelen[i-1]; scanf("%s",have+havestart[i]); havelen[i]=strlen(have+havestart[i]); }

	scanf("%d",&ndict);
	nt=nword=0; root=gett();
	REP(i,ndict) {
		int a=readt(),b=readt(); //printf("%d->%d\n",a,b);
		wnxt[i]=w[b].fst; w[b].fst=i; wto[i]=a;
	}
	//REP(i,nword) printf("%d: %d %d\n",w[i].idx,w[i].val1,w[i].val2);

	sort(w,w+nword); REP(i,nword) wmap[w[i].idx]=i; REP(i,ndict) wto[i]=wmap[wto[i]];
	REP(i,nword) if(w[i].bst==-1) {
		qhead=qtail=0; q[qhead++]=i; w[i].bst=i;
		while(qtail<qhead) {
			int at=q[qtail++];
			for(int x=w[at].fst;x!=-1;x=wnxt[x]) if(w[wto[x]].bst==-1) { q[qhead++]=wto[x]; w[wto[x]].bst=i; }
		}
	}
	//REP(i,nword) { printf("%d: %d %d (%d):",w[wmap[i]].idx,w[wmap[i]].val1,w[wmap[i]].val2,w[w[wmap[i]].bst].idx); for(int x=w[wmap[i]].fst;x!=-1;x=wnxt[x]) printf(" %d",w[wto[x]].idx); puts(""); }

	ll ret1=0,ret2=0;
	REP(i,nhave) {
		int at=root,nr=0; for(int j=0;j<havelen[i];++j) { int x=tolower(have[havestart[i]+j])-'a'; if('a'+x=='r') ++nr; at=at==-1?-1:tnxt[at][x]; }
		//printf("have %d\n",at==-1?-1:twrd[at]);
		if(at==-1||twrd[at]==-1) { ret1+=nr; ret2+=havelen[i]; } else { int cur=w[wmap[twrd[at]]].bst; ret1+=w[cur].val1; ret2+=w[cur].val2; }
	}
	cout<<ret1<<" "<<ret2<<endl;
}

int main() {
	run();
	return 0;
}