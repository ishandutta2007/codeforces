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

const int MAXQ=300000;
const int MAXLOGQ=18;
const int MAXLEN=300000;
const int MAXT=MAXLEN+(MAXLOGQ+1);

int nq;
char s[MAXLEN+1];
int qtype[MAXQ],qoff[MAXQ+1],qlen[MAXQ];

int qnxt[MAXQ];
int tnxt[MAXT][26],tcnt[MAXT],tfail[MAXT],td[MAXT];

int z[MAXT],zhead,ztail;

typedef struct AHOC {
	int head,cnt,id;
	int root;

	void clear() { head=-1,cnt=0; }
	void add(int q) { qnxt[q]=head; head=q; ++cnt; }
	void rebuild() {
		REP(k,26) tnxt[root][k]=-1; tcnt[root]=0; td[root]=0; tfail[root]=-1;
		for(int q=head;q!=-1;q=qnxt[q]) {
			int at=root;
			REP(i,qlen[q]) {
				int j=qoff[q]+i,k=s[j]-'a';
				if(tnxt[at][k]==-1) { tnxt[at][k]=j; REP(kk,26) tnxt[j][kk]=-1; tcnt[j]=0; td[j]=td[at]+1; tfail[j]=-1; }
				at=tnxt[at][k];
			}
			tcnt[at]+=qtype[q]==1?+1:-1;
		}
		//printf("halfway %d:\n",id); print(root);
		zhead=ztail=0; z[zhead++]=root; tfail[root]=root;
		while(ztail<zhead) {
			int at=z[ztail++];
			REP(k,26) if(tnxt[at][k]!=-1) z[zhead++]=tnxt[at][k],tfail[tnxt[at][k]]=at==root?root:tnxt[tfail[at]][k]; else tnxt[at][k]=at==root?root:tnxt[tfail[at]][k];
		}
		FOR(i,1,ztail) tcnt[z[i]]+=tcnt[tfail[z[i]]];
		//printf("rebuild %d:\n",id); print(root);
	}
	void print(int at) {
		REP(k,26) if(tnxt[at][k]!=-1&&td[tnxt[at][k]]==td[at]+1) {
			REP(i,td[at]) printf(" "); printf("%c = %d (%d:%d)\n",'a'+k,tcnt[tnxt[at][k]],tnxt[at][k],tfail[tnxt[at][k]]);
			print(tnxt[at][k]);
		}
	}
	int calc(int q) {
		if(cnt==0) return 0;
		int at=root,ret=tcnt[at];
		REP(i,qlen[q]) {
			int k=s[qoff[q]+i]-'a';
			at=tnxt[at][k]; ret+=tcnt[at];
		}
		//printf("\t%d: %d\n",id,ret);
		return ret;
	}
} AHOC;

AHOC ahoc[MAXLOGQ+1];
void init() {
	REPE(i,MAXLOGQ) ahoc[i].id=i,ahoc[i].root=MAXLEN+i,ahoc[i].clear();
}
void promote(int i) {
	if(ahoc[i+1].cnt==0) { swap(ahoc[i].head,ahoc[i+1].head),swap(ahoc[i].cnt,ahoc[i+1].cnt),swap(ahoc[i].root,ahoc[i+1].root); return; }
	while(ahoc[i].head!=-1) { int q=ahoc[i].head; ahoc[i].head=qnxt[q]; ahoc[i+1].add(q); }
	ahoc[i].clear(); ahoc[i+1].rebuild();
}
void mod(int q) {
	int i=0; while(ahoc[i].cnt==(1<<i)) promote(i++);
	ahoc[0].add(q); ahoc[0].rebuild();
}
int calc(int q) {
	int ret=0; REPE(i,MAXLOGQ) ret+=ahoc[i].calc(q); return ret;
}

void run() {
	scanf("%d",&nq); qoff[0]=0;
	init();
	REP(i,nq) {
		scanf("%d%s",&qtype[i],s+qoff[i]); qlen[i]=strlen(s+qoff[i]); qoff[i+1]=qoff[i]+qlen[i];
		if(qtype[i]==1) mod(i);
		if(qtype[i]==2) mod(i);
		if(qtype[i]==3) { int ret=calc(i); printf("%d\n",ret); fflush(stdout); }
	}
}

int main() {
	run();
	return 0;
}