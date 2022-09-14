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

typedef struct Node {
	int start,end;
	int childs[3];
	int suffix;
	Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
} Node;

vector<Node> nodes;
int addnode(int start,int end) {
	nodes.push_back(Node(start,end));
	return SZ(nodes)-1;
}
inline int convert(char c) { if(c=='(') return 0; if(c==')') return 1; if(c=='#') return 2; assert(false); }

char s[2000001]; int n,norig;
int state[1000001],minbefore[1000000],minafter[1000000];

int create() {
	int root=addnode(0,0);
	int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
	for(int i=0;i<n;++i) {
		++rem; prev=-1;
		while(rem>0) {
			int tonode=nodes[atnode].childs[convert(s[atedge])];
			int tostart=tonode==-1?-1:nodes[tonode].start;
			if(tonode!=-1&&nodes[tonode].start+atlen>=nodes[tonode].end) {
				atedge+=nodes[tonode].end-nodes[tonode].start;
				atlen-=nodes[tonode].end-nodes[tonode].start;
				atnode=tonode;
				continue;
			}
			if(tonode==-1) { //atlen should be 0
				int leaf=addnode(i,n);
				nodes[atnode].childs[convert(s[atedge])]=leaf;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
			} else if(s[tostart+atlen]==s[i]) {
				++atlen;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				break;
			} else {
				int branch=addnode(tostart,tostart+atlen);
				nodes[tonode].start+=atlen;
				int leaf=addnode(i,n);
				nodes[atnode].childs[convert(s[atedge])]=branch;
				nodes[branch].childs[convert(s[tostart+atlen])]=tonode;
				nodes[branch].childs[convert(s[i])]=leaf;
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
	return root;
}

void print(int node,int depth) {
	for(int i=0;i<depth;++i) printf("  ");
	printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'");
	if(nodes[node].end!=n) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
	for(int i=0;i<3;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}

bool ok(int x) {
	if(state[norig]>=0) return state[x]<=minafter[x]&&state[x]-state[norig]<=minbefore[x];
	return state[x]+state[norig]<=minafter[x]&&state[x]<=minbefore[x];
}

int find(int node,int depth) {
	if(nodes[node].end==n&&nodes[node].start-depth<norig) {
		int ret=nodes[node].start-depth;
		if(ok(ret)) return ret;
	}
	for(int i=0;i<3;++i) if(nodes[node].childs[i]!=-1) { int cur=find(nodes[node].childs[i],depth+nodes[node].end-nodes[node].start); if(cur!=-1) return cur; }
	return -1;
}


void run() {
	scanf("%s",s); norig=strlen(s);
	REP(i,norig) s[norig+i]=s[i]; s[2*norig]='#'; n=2*norig+1; s[n]='\0'; //printf("%s\n",s);
	int root=create();
	//print(root,0);
	state[0]=0; REP(i,norig) state[i+1]=state[i]+(s[i]=='('?+1:-1);
	minbefore[0]=INT_MAX; FOR(i,1,norig) minbefore[i]=min(state[i-1],minbefore[i-1]);
	minafter[norig-1]=INT_MAX; for(int i=norig-2;i>=0;--i) minafter[i]=min(state[i+1],minafter[i+1]);

	int ret=find(root,0);
	//REP(i,norig) printf("%d ",state[i]); printf("[%d] -> %d=%d/%d/%d\n",state[norig],ret,minbefore[ret],state[ret],minafter[ret]);

	if(state[norig]<0) REP(i,-state[norig]) printf("(");
	printf("%.*s",norig,s+ret);
	if(state[norig]>0) REP(i,state[norig]) printf(")");
	puts("");
}

int main() {
	run();
	return 0;
}