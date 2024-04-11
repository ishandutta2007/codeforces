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

const int MAXLEN=500000;

typedef struct Node {
	int start,end;
	int childs[2];
	int suffix;
} Node;

Node nodes[2*MAXLEN]; int nnodes;
char s[MAXLEN+1]; int len;
int root;

int addnode(int start,int end) { nodes[nnodes].start=start; nodes[nnodes].end=end; memset(nodes[nnodes].childs,-1,sizeof(nodes[nnodes].childs)); nodes[nnodes].suffix=-1; return nnodes++; }
inline int convert(char c) { if(c=='(') return 0; if(c==')') return 1; assert(false); }
int build() {
	root=addnode(0,0);
	int atnode=root,atedge=0,atlen=0,rem=0,prev=-1;
	for(int i=0;i<len;++i) {
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
				int leaf=addnode(i,len);
				nodes[atnode].childs[convert(s[atedge])]=leaf;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
			} else if(s[tostart+atlen]==s[i]) {
				++atlen;
				if(prev!=-1) nodes[prev].suffix=atnode; prev=atnode;
				break;
			} else {
				int branch=addnode(tostart,tostart+atlen);
				nodes[tonode].start+=atlen;
				int leaf=addnode(i,len);
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
	if(nodes[node].end!=len) printf(" -> %d",node); if(nodes[node].suffix!=-1) printf(" [%d]",nodes[node].suffix); puts("");
	for(int i=0;i<2;++i) if(nodes[node].childs[i]!=-1) print(nodes[node].childs[i],depth+1);
}

int val[MAXLEN+1];
int p[MAXLEN];
bool pcmp(int a,int b) { if(val[a+1]!=val[b+1]) return val[a+1]<val[b+1]; return a<b; }

int smnval[4*MAXLEN];
void sinit(int x,int l,int r) {
	if(l+1==r) {
		smnval[x]=val[l+1];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m,r);
		smnval[x]=smnval[2*x+1];
		if(smnval[2*x+2]<smnval[x]) smnval[x]=smnval[2*x+2];
	}
	//printf("sinit[%d,%d) = %d\n",l,r,smnval[x]);
}
int sfind(int x,int l,int r,int L,int R,int VAL) {
	//FOR(i,L,R) if(val[i+1]<=VAL) return i; return R;
	//printf("\tsfind(%d in [%d,%d)) : [%d,%d)\n",VAL,L,R,l,r);
	if(smnval[x]>VAL) return R;
	if(l+1==r) {
		return l;
	} else {
		int m=l+(r-l)/2,ret;
		if(L<m&&(ret=sfind(2*x+1,l,m,L,R,VAL))!=R) return ret;
		if(m<R&&(ret=sfind(2*x+2,m,r,L,R,VAL))!=R) return ret;
		return R;
	}
}
int calc(int IDX,int VAL) {
	int l=-1,h=len;
	while(l+1<h) {
		int m=l+(h-l)/2;
		if(val[p[m]+1]<VAL||val[p[m]+1]==VAL&&p[m]<IDX) l=m; else h=m;
	}
	return h;
}
int calc(int L,int R,int VAL) {
	//int ret=0; FOR(i,L,R) if(val[i+1]==VAL) ++ret; return ret;
	int ret=calc(R,VAL)-calc(L,VAL);
	//printf("counting = %d in [%d,%d) = %d\n",VAL,L,R,ret);
	return ret;
}

ll ret;
void go(int at,int pval) {
	REP(i,2) if(nodes[at].childs[i]!=-1) {
		int to=nodes[at].childs[i];
		int end=sfind(0,0,len,nodes[to].start,nodes[to].end,val[nodes[to].start]-1-pval);
		//printf("finding <=%d in [%d,%d) = %d\n",val[nodes[to].start]-1-pval,nodes[to].start,nodes[to].end,end);
		ret+=calc(nodes[to].start,end,val[nodes[to].start]-pval);
		if(end==nodes[to].end) go(to,pval+val[nodes[to].end]-val[nodes[to].start]);
	}
}


void run() {
	scanf("%d%s",&len,s);
	//srand(time(NULL)); len=MAXLEN; REP(i,len) s[i]="()"[rand()%2];
	build();
	//print(root,0);
	val[0]=0; REP(i,len) val[i+1]=val[i]+(s[i]=='('?+1:-1);
	REP(i,len) p[i]=i; sort(p,p+len,pcmp);
	//REP(i,len) printf("%d ",p[i]); puts("");
	sinit(0,0,len);
	//REPE(i,len) printf("%d ",val[i]); puts("");
	ret=0; go(root,0); printf("%I64d\n",ret);
}

int main() {
	run();
	return 0;
}