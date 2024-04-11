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
	int childs[27];
	int suffix;
	
	Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; }
} Node;

vector<Node> nodes;
int addnode(int start,int end) {
	nodes.push_back(Node(start,end));
	return SZ(nodes)-1;
}

int create(char* s) {
	int n=strlen(s);
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

const int MAXN=200000;

int n;
char s[MAXN+2];
char forbid[MAXN+2];

vector<int> cnt;
vector<int> len;

void dfs(int at,int par) {
	len[at]=(par==-1?0:len[par])+(nodes[at].end-nodes[at].start);
	cnt[at]=nodes[at].end==n&&forbid[n-len[at]]=='0'?1:0;
	REP(i,27) {
		int to=nodes[at].childs[i]; if(to==-1) continue;
		dfs(to,at);
		cnt[at]+=cnt[to];
	}
}

void print(int node,int depth) {
	for(int i=0;i<depth;++i) printf("  ");
	printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'");
	if(nodes[node].end!=n) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); printf(" <%d,%d>",cnt[node],len[node]); puts("");
	for(int i=0;i<27;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}


void run() {
	scanf("%d%s%s",&n,s,forbid);

	reverse(s,s+n); reverse(forbid,forbid+n);
	nodes.clear(); s[n]='{'; forbid[n]='1'; ++n; forbid[n]=s[n]='\0'; int rt=create(s);

	cnt=vector<int>(SZ(nodes),-1);
	len=vector<int>(SZ(nodes),-1);
	dfs(rt,-1);
	//print(rt,0);

	ll ret=0;
	REPSZ(at,nodes) {
		ll cur=(ll)(len[at]-(nodes[at].end==n?1:0))*cnt[at];
		if(cur>ret) ret=cur;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}