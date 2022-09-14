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

const int MAXLEN=100000;

ll have;
char s[MAXLEN+1]; int slen;

typedef struct Node {
	int start,end;
	int childs[4];
	int suffix;
	Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
} Node;

vector<Node> nodes;
int addnode(int start,int end) {
	nodes.push_back(Node(start,end));
	return SZ(nodes)-1;
}

int create() {
	int root=addnode(0,0);
	int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
	for(int i=0;i<slen;++i) {
		++rem; prev=-1;
		while(rem>0) {
			int tonode=nodes[atnode].childs[s[atedge]-'A'];
			int tostart=tonode==-1?-1:nodes[tonode].start;
			if(tonode!=-1&&nodes[tonode].start+atlen>=nodes[tonode].end) {
				atedge+=nodes[tonode].end-nodes[tonode].start;
				atlen-=nodes[tonode].end-nodes[tonode].start;
				atnode=tonode;
				continue;
			}
			if(tonode==-1) { //atlen should be 0
				int leaf=addnode(i,slen);
				nodes[atnode].childs[s[atedge]-'A']=leaf;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
			} else if(s[tostart+atlen]==s[i]) {
				++atlen;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				break;
			} else {
				int branch=addnode(tostart,tostart+atlen);
				nodes[tonode].start+=atlen;
				int leaf=addnode(i,slen);
				nodes[atnode].childs[s[atedge]-'A']=branch;
				nodes[branch].childs[s[tostart+atlen]-'A']=tonode;
				nodes[branch].childs[s[i]-'A']=leaf;
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
	/*if(nodes[node].end!=slen)*/ printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
	for(int i=0;i<4;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}

int cst[4][4]; // cst[i][j]==length of shortest word not in s that starts with i and ends with j
int bst[5][4][4];

void update(int a,int b,int cur) { /*printf("%d,%d -> %d\n",a,b,cur);*/ if(cur<cst[a][b]) cst[a][b]=cur; }
void dfs(int node,int a,int len) {
	//printf("dfs(%d,%d,%d) (%d..%d)\n",node,a,len,nodes[node].start,nodes[node].end);
	int clen=nodes[node].end-nodes[node].start;
	if(clen>1) {
		int x=s[nodes[node].start+1]-'A';
		REP(b,4) update(a,b,len+2+(b==x?1:0));
	} else REP(i,4) {
		if(nodes[node].childs[i]!=-1) dfs(nodes[node].childs[i],a,len+1);
		else REP(b,4) update(a,b,len+2+(b!=i?1:0));
	}
}



void run() {
	scanf("%I64d%s",&have,s); slen=strlen(s);

	REP(i,4) REP(j,4) cst[i][j]=INT_MAX;
	int root=create();
	//print(root,0);
	REP(i,4) dfs(nodes[root].childs[i],i,0);


	REP(i,4) REP(j,4) bst[1][i][j]=cst[i][j];
	FORE(len,2,4) REP(i,4) REP(j,4) { bst[len][i][j]=INT_MAX; REP(k,4) if(bst[len-1][i][k]+cst[k][j]-1<bst[len][i][j]) bst[len][i][j]=bst[len-1][i][k]+cst[k][j]-1; }

	//FORE(len,1,4) { printf("%d:\n",len); REP(i,4) { REP(j,4) printf("%d ",bst[len][i][j]); puts(""); } }

	ll ret=1;
	REP(i,4) REP(j,4) REP(k,4) FORE(cyc,1,4) FOR(pre,i==j?0:1,cyc) FOR(suf,j==k?0:1,cyc) {
		ll rem=have-1;
		if(pre>0) rem-=bst[pre][i][j]-1;
		if(suf>0) rem-=bst[suf][j][k]-1;
		if(rem<0) continue;
		ll times=rem/(bst[cyc][j][j]-1);
		ll cur=pre+times*cyc+suf+1;
		//if(cur>=4) printf("%d-(%d)->%d:%lld*%d->(%d)->%d: %lld\n",i,pre,j,times,cyc,suf,k,cur);
		if(cur>ret) ret=cur;
	}
	printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}