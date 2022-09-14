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

const int MOD=1000000007;
char s[300004]; int n;
int idx[300004];

typedef struct Node {
	int start,end;
	int childs[29];
	int suffix;
	int cnt[3];
	Node(int start,int end):start(start),end(end) { memset(childs,-1,sizeof(childs)); suffix=-1; memset(cnt,0,sizeof(cnt)); }
} Node;

vector<Node> nodes;
int addnode(int start,int end) {
	nodes.push_back(Node(start,end));
	return SZ(nodes)-1;
}

int create() {
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

void print(int node,int depth) {
	for(int i=0;i<depth;++i) printf("  ");
	printf("'"); for(int i=nodes[node].start;i<nodes[node].end;++i) printf("%c",s[i]); printf("'");
	if(nodes[node].end!=n) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); printf(" <%d,%d,%d>",nodes[node].cnt[0],nodes[node].cnt[1],nodes[node].cnt[2]); puts("");
	for(int i=0;i<29;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}

int res[300001];

void go(int node,int len) {
	if(nodes[node].end==n) {
		int i=idx[nodes[node].start];
		if(i!=-1) ++nodes[node].cnt[i];
	} else {
		int clen=nodes[node].end-nodes[node].start;
		REP(i,29) {
			int to=nodes[node].childs[i];
			if(to==-1) continue;
			go(to,len+clen);
			REP(j,3) nodes[node].cnt[j]+=nodes[to].cnt[j];
		}
		if(clen!=0) {
			int cur=1; REP(j,3) cur=(ll)cur*nodes[node].cnt[j]%MOD;
			//printf("%d..%d %d\n",len+1,len+clen,cur);
			res[len+1]+=cur; if(res[len+1]>=MOD) res[len+1]-=MOD;
			res[len+clen+1]-=cur; if(res[len+clen+1]<0) res[len+clen+1]+=MOD;
		}
	}
}

int slen[3];

void run() {
	memset(idx,-1,sizeof(idx)); n=0;
	scanf("%s",s); for(int i=n;s[i]!='\0';++i) idx[i]=0; slen[0]=strlen(s); n=strlen(s); s[n++]='{'; idx[n-1]=0; 
	scanf("%s",s+n); for(int i=n;s[i]!='\0';++i) idx[i]=1; slen[1]=strlen(s+n); n=strlen(s); s[n++]='|'; idx[n-1]=1;
	scanf("%s",s+n); for(int i=n;s[i]!='\0';++i) idx[i]=2; slen[2]=strlen(s+n); n=strlen(s); s[n++]='}'; idx[n-1]=2;
	//printf("%s\n",s);

	int root=create();
	memset(res,0,sizeof(res));
	go(root,0);
	//print(root,0);
	int reslen=min(slen[0],min(slen[1],slen[2]));
	FORE(i,1,reslen) { res[i]+=res[i-1]; if(res[i]>=MOD) res[i]-=MOD; }
	FORE(i,1,reslen) { if(i!=1) printf(" "); printf("%d",res[i]); } puts("");
}

int main() {
	run();
	return 0;
}