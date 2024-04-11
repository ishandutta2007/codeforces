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
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
#include <stack>
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
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

typedef struct Node {
	int id,cnt,maxprio;

	bool red; int parent,left,right;
	Node(int id,int prio):id(id),cnt(1),maxprio(prio) { red=false; parent=left=right=-1; }
} Node;

int root=-1;
vector<Node> nodes;

void update(int at) {
	int left=nodes[at].left,right=nodes[at].right;
	if(left==-1||right==-1) return;
	nodes[at].cnt=nodes[left].cnt+nodes[right].cnt;
	nodes[at].maxprio=max(nodes[left].maxprio,nodes[right].maxprio);
}

void up(int at) {
	int p=nodes[at].parent;
	if(at==nodes[p].left) {
		int n1=nodes[at].left,n2=nodes[at].right,n3=nodes[p].right,g=nodes[p].parent;
		nodes[at].right=p; nodes[p].parent=at;
		nodes[p].left=n2; if(n2!=-1) nodes[n2].parent=p;
		nodes[at].parent=g; if(g==-1) root=at; else if(nodes[g].left==p) nodes[g].left=at; else nodes[g].right=at;
	} else {
		int n1=nodes[p].left,n2=nodes[at].left,n3=nodes[at].right,g=nodes[p].parent;
		nodes[at].left=p; nodes[p].parent=at;
		nodes[p].right=n2; if(n2!=-1) nodes[n2].parent=p;
		nodes[at].parent=g; if(g==-1) root=at; else if(nodes[g].left==p) nodes[g].left=at; else nodes[g].right=at;
	}
	update(p);
	update(at);
}

void insert(int at,int id,int prio,int maxskip) {
	while(nodes[at].cnt!=1) {
		++nodes[at].cnt;
		if(prio>nodes[at].maxprio) nodes[at].maxprio=prio;
			
		int left=nodes[at].left,right=nodes[at].right;
		assert(left!=-1&&right!=-1);
		if(prio>nodes[right].maxprio&&maxskip>=nodes[right].cnt) {
			maxskip-=nodes[right].cnt;
			at=left;
		} else {
			at=right;
		}
	}
	{
		//printf("\tended at %d\n",at);
		int left=SZ(nodes); nodes.PB(Node(nodes[at].id,nodes[at].maxprio));
		int right=SZ(nodes); nodes.PB(Node(id,prio));
		nodes[at].id=-1;
		if(prio>nodes[at].maxprio&&maxskip>=1) swap(left,right);
		++nodes[at].cnt;
		if(prio>nodes[at].maxprio) nodes[at].maxprio=prio;
		nodes[left].parent=nodes[right].parent=at,nodes[at].left=left,nodes[at].right=right;
		nodes[left].red=nodes[right].red=true;
		if(nodes[at].red==false) return;
		int N,N1=left,N2=right,P=at,G=nodes[P].parent,U=nodes[G].left!=P?nodes[G].left:nodes[G].right;
		if(nodes[U].red) {
			//printf("\trecoloring\n");
			nodes[P].red=nodes[U].red=false; nodes[G].red=true; N=G;
		} else {
			//printf("\treordering\n");
			up(P); nodes[P].red=true;
			if(nodes[N1].parent==P) nodes[N1].red=false;
			if(nodes[N2].parent==P) nodes[N2].red=false;
			N=P;
		}
		while(true) {
			//printf("\tat %d\n",N);
			int P=nodes[N].parent;
			if(P==-1) { nodes[N].red=false; return; }
			if(nodes[P].red==false) return;
			int G=nodes[P].parent,U=nodes[G].left!=P?nodes[G].left:nodes[G].right;
			if(nodes[U].red) {
				//printf("\trecoloring\n");
				nodes[P].red=nodes[U].red=false; nodes[G].red=true; N=G;
			} else {
				//printf("\treordering\n");
				if(nodes[G].left==P&&nodes[P].right==N||nodes[G].right==P&&nodes[P].left==N) {
					up(N); swap(N,P);
				}
				up(P); nodes[P].red=false; nodes[G].red=true; return;
			}
		}
	}
}

void output(int at,vector<int> &order) {
	if(nodes[at].left!=-1) output(nodes[at].left,order);
	if(nodes[at].id!=-1) order.PB(nodes[at].id);
	if(nodes[at].right!=-1) output(nodes[at].right,order);
}

void print(int at,int depth) {
	REP(i,depth) printf(" "); printf("id=%d, cnt=%d, maxprio=%d [at=%d,red=%d,parent=%d,left=%d,right=%d]\n",nodes[at].id,nodes[at].cnt,nodes[at].maxprio,at,nodes[at].red,nodes[at].parent,nodes[at].left,nodes[at].right);
	if(nodes[at].left!=-1) print(nodes[at].left,depth+1);
	if(nodes[at].right!=-1) print(nodes[at].right,depth+1);
}

vector<int> solve(int n,vector<int> prio,vector<int> c) {
	nodes.clear();
	nodes.PB(Node(1,prio[0])); root=0;
	//print(root,0); puts("");
	FOR(i,1,n) {
		insert(root,i+1,prio[i],c[i]);
		//print(root,0); puts("");
	}
	
	vector<int> order;
	output(root,order);
	return order;	
}

void run() {
	int n; scanf("%d",&n);
	vector<int> prio(n),c(n); REP(i,n) scanf("%d%d",&prio[i],&c[i]);
	
	vector<int> order=solve(n,prio,c);
	REPSZ(i,order) { if(i!=0) printf(" "); printf("%d",order[i]); } puts("");
}

int main() {
//	freopen ("input.txt","r",stdin);
//	freopen ("output.txt","w",stdout);
//	int n; scanf("%d",&n); REP(i,n)
	run(); return 0;
}