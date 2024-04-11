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

typedef struct Node {
	int start,end;
	int childs[28];
	int suffix;
	Node() {}
	Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
} Node;

Node nodes[25000]; int nnodes;
int addnode(int start,int end) {
	assert(nnodes<25000);
	nodes[nnodes]=Node(start,end);
	return nnodes++;
}

int n;
char s[10003];

int create() {
	n=strlen(s);
	int root=addnode(0,0);
	int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
	for(int i=0;i<n;++i) {
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
				int leaf=addnode(i,n);
				nodes[atnode].childs[s[atedge]-'a']=leaf;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
			} else if(s[tostart+atlen]==s[i]) {
				++atlen;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				break;
			} else {
				int branch=addnode(tostart,tostart+atlen);
				nodes[tonode].start+=atlen;
				int leaf=addnode(i,n);
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
	return root;
}

int have[25000];
int cnt[25000];

void print(int node,int depth) {
	for(int i=0;i<depth;++i) printf("  ");
	printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'"); printf(" <%x>",have[node]);
	if(nodes[node].end!=n) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
	for(int i=0;i<28;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}


int alen,blen;
char sa[5001],sb[5001];

void dfs(int node) {
	have[node]=0; cnt[node]=0;
	if(nodes[node].start<=alen&&alen<nodes[node].end) have[node]|=1;
	else if(nodes[node].start<=alen+blen+1&&alen+blen+1<nodes[node].end) have[node]|=2;
	for(int i=0;i<28;++i) if(nodes[node].childs[i]!=-1) {
		dfs(nodes[node].childs[i]);
		have[node]|=have[nodes[node].childs[i]];
		cnt[node]+=cnt[nodes[node].childs[i]];
	}
	if(cnt[node]==0) cnt[node]=1;
}

int find(int node,int depth) {
	int ret=-1;
	if(have[node]==3&&cnt[node]==2) {
		int cur=depth+1;
		if(ret==-1||cur<ret) ret=cur;
	}
	for(int i=0;i<28;++i) if(nodes[node].childs[i]!=-1) {
		int cur=find(nodes[node].childs[i],depth+nodes[node].end-nodes[node].start);
		if(cur!=-1&&(ret==-1||cur<ret)) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%s%s",sa,sb);

	nnodes=0;
	alen=strlen(sa),blen=strlen(sb);
	REP(i,alen) s[i]=sa[i]; s[alen]='{'; REP(i,blen) s[alen+1+i]=sb[i]; s[alen+blen+1]='|'; s[alen+blen+2]='\0';
	int root=create();

	dfs(0);
//	print(root,0);
	int ret=find(0,0);
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}