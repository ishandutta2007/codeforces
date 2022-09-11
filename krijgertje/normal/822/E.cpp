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

int slen; char s[MAXN+1];
int tlen; char t[MAXN+1];
int nparts;

int prv[MAXN+1]; // prv[i] is the maximum matched length of s[0..i) with the previous number of parts
int nxt[MAXN+1]; // nxt[i] is the maximum matched length of s[0..i) with the next number of parts


const int MAXSTLEN=2*MAXN+2;
const int MAXLGSTLEN=17;
const int ALPH=28;
typedef struct SuffTree {
	typedef struct Node {
		int start,end;
		int childs[ALPH];
		int suffix;
		Node() {}
		Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
	} Node;

	char s[MAXSTLEN+1]; int slen;
	Node nodes[2*MAXSTLEN-1]; int nnodes,root;

	int addnode(int start,int end) {
		int ret=nnodes++;
		nodes[ret]=Node(start,end);
		return ret;
	}

	void build() {
		nnodes=0;
		root=addnode(0,0);
		int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
		for(int i=0;i<slen;++i) {
			++rem; prev=-1;
			while(rem>0) {
				int tonode=nodes[atnode].childs[s[atedge]-'a'];
				int tostart=tonode==-1?-1:nodes[tonode].start;
				if(tonode!=-1&&nodes[tonode].start+atlen>=nodes[tonode].end) {
					atedge+=nodes[tonode].end-nodes[tonode].start;
					atlen-=nodes[tonode].end-nodes[tonode].start;
					atnode=tonode;
					continue;
				}
				if(tonode==-1) { //atlen should be 0
					int leaf=addnode(i,slen);
					nodes[atnode].childs[s[atedge]-'a']=leaf;
					if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				} else if(s[tostart+atlen]==s[i]) {
					++atlen;
					if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
					break;
				} else {
					int branch=addnode(tostart,tostart+atlen);
					nodes[tonode].start+=atlen;
					int leaf=addnode(i,slen);
					nodes[atnode].childs[s[atedge]-'a']=branch;
					nodes[branch].childs[s[tostart+atlen]-'a']=tonode;
					nodes[branch].childs[s[i]-'a']=leaf;
					if(prev!=-1) nodes[prev].suffix=branch; prev=branch;
				}
				--rem;
				if(atnode==root) {
					if(atlen>0) --atlen;
					atedge++;
				} else {
					atnode=nodes[atnode].suffix;
				}
			}
		}
	}
	int sa[MAXSTLEN],lcp[MAXSTLEN]; int nsa;
	int rmqjump[MAXSTLEN][MAXLGSTLEN+1];
	int lg[MAXSTLEN+1];
	void createsa() {
		nsa=0; dfscreatesa(root,0,-1);
		FOR(i,1,nsa) rmqjump[i][0]=lcp[i];
		for(int k=1;(1<<k)<=nsa;++k) REPE(i,nsa-(1<<k)) rmqjump[i][k]=min(rmqjump[i][k-1],rmqjump[i+(1<<(k-1))][k-1]);
		lg[1]=0; FORE(i,2,nsa) { lg[i]=lg[i-1]; while((2<<lg[i])<=i) ++lg[i]; }
		//FORE(i,1,nsa) printf("%d: %d\n",i,lg[i]); REP(i,nsa) { printf("%d:",i); for(int k=0;i+(1<<k)<=nsa;++k) printf(" %d",rmqjump[i][k]); puts(""); }
	}
	void dfscreatesa(int node,int depth,int clcp) {
		if(nodes[node].end==slen) { int idx=nodes[node].start-depth; lcp[nsa]=clcp; sa[idx]=nsa++; }
		for(int i=0;i<ALPH;++i) if(nodes[node].childs[i]!=-1) { dfscreatesa(nodes[node].childs[i],depth+nodes[node].end-nodes[node].start,clcp); clcp=depth+nodes[node].end-nodes[node].start; }
	}
	int rmq(int a,int b) {
		//int ret=lcp[a]; FORE(i,a+1,b) if(lcp[i]<ret) ret=lcp[i]; return ret;
		int k=lg[b+1-a]; return min(rmqjump[a][k],rmqjump[b+1-(1<<k)][k]);
	}
	void dfsprint(int node,int depth) {
		for(int i=0;i<depth;++i) printf("  ");
		printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'");
		if(nodes[node].end!=slen) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
		for(int i=0;i<ALPH;++i) if(nodes[node].childs[i]!=-1) dfsprint(nodes[node].childs[i],depth+1);
	}
	void print() {
		printf("%s\n",s);
		dfsprint(root,0);
		REP(i,slen) printf("%d ",sa[i]); puts("");
		REP(i,slen) printf("%d ",lcp[i]); puts("");
	}
} SuffTree;
SuffTree st;

void precalc() {
	st.slen=0; REP(i,slen) st.s[st.slen++]=s[i]; st.s[st.slen++]='{'; REP(i,tlen) st.s[st.slen++]=t[i]; st.s[st.slen++]='|'; st.s[st.slen]='\0';
	st.build();
	st.createsa();
}

int lcp(char *a,char *b) {
	//int ret=0; while(*a!='\0'&&*b!='\0'&&*a==*b) ++ret,++a,++b; return ret;
	int ai=st.sa[a-s],bi=st.sa[b-t+slen+1];
	if(ai>bi) swap(ai,bi); return st.rmq(ai+1,bi);
}

void run() {
	scanf("%d%s%d%s%d",&slen,s,&tlen,t,&nparts);
	//slen=MAXN; REP(i,slen) s[i]='a'+rand()%2; s[slen]='\0'; tlen=MAXN; REP(i,tlen) t[i]='a'+rand()%2; t[tlen]='\0';	nparts=30;
	precalc();

	memset(prv,0,sizeof(prv));
	REP(part,nparts) {
		memset(nxt,0,sizeof(nxt));
		REP(i,slen) {
			int cur=lcp(s+i,t+prv[i]);
			int ni=i+cur,nv=prv[i]+cur;
			if(nv>nxt[ni]) nxt[ni]=nv;
		}
		REP(i,slen) if(nxt[i]>nxt[i+1]) nxt[i+1]=nxt[i];
		REPE(i,slen) prv[i]=nxt[i];
	}
	printf("%s\n",prv[slen]==tlen?"YES":"NO");
}

int main() {
	run();
	return 0;
}