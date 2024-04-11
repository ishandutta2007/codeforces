#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

vector<int> g[101010];

vector<int> sta;
vector<int> cyc;

int u[101010];
int cp[101010];

int dfs(int x, int e){
	if (u[x]){
		while (1){
			cyc.push_back(sta.back());
			sta.pop_back();
			if (cyc.back()==x) break;
		}
		return 1;
	}
	else{
		u[x]=1;
		sta.push_back(x);
		for (int nx:g[x]){
			if (nx!=e){
				if (dfs(nx, x)) return 1;
			}
		}
		sta.pop_back();
		return 0;
	}
}

int dist(int a, int b, int k){
	return min(max(a, b)-min(a, b), k-max(a, b)+min(a, b));
}

const int N=1<<17;

int ces=0;
int tes=0;

int st[2*N][3];

int togglest(int i, int stl, int str, int l, int r){
	if (stl>r||str<l) return 0;
	if (st[i][2]){
		if (i*2<2*N) {
			swap(st[i*2][0], st[i*2][1]);
			st[i*2][2]^=1;
		}
		if (i*2+1<2*N) {
			swap(st[i*2+1][0], st[i*2+1][1]);
			st[i*2+1][2]^=1;
		}
		st[i][2]=0;
	}
	if (l<=stl&&str<=r){
		swap(st[i][0], st[i][1]);
		st[i][2]=1;
		return st[i][1]-st[i][0];
	}
	else{
		int m=(stl+str)/2;
		int re=0;
		re+=togglest(i*2, stl, m, l, r);
		re+=togglest(i*2+1, m+1, str, l, r);
		st[i][0]=st[i*2][0]+st[i*2+1][0];
		st[i][1]=st[i*2][1]+st[i*2+1][1];
		return re;
	}
}

void init(int i, int stl, int str){
	if (i>=2*N) return;
	st[i][0]=str-stl+1;
	int m=(stl+str)/2;
	init(i*2, stl, m);
	init(i*2+1, m+1, str);
}

void togglecpath2(int a, int b){
	if (a>b){
		togglecpath2(a, (int)cyc.size());
		togglecpath2(0, b);
		return;
	}
	ces+=togglest(1, 0, N-1, a, b-1);
}

void togglecpath1(int a, int b){
	if (a==b) return;
	a=cp[a];
	b=cp[b];
	int d1=dist((a+1)%(int)cyc.size(), b, cyc.size());
	int d2=dist((a-1+(int)cyc.size())%(int)cyc.size(), b, cyc.size());
	if (d1<d2){
		togglecpath2(a, b);
	}
	else if(d2<d1){
		togglecpath2(b, a);
	}
	else{
		if (cyc[(a+1)%(int)cyc.size()]<cyc[(a-1+(int)cyc.size())%(int)cyc.size()]){
			togglecpath2(a, b);
		}
		else{
			togglecpath2(b, a);
		}
	}
}

struct Node {
	Node* c[2], *p;
	int id, rev;
	int lt, c0, c1, tg;
	int isr() {
		return !p||(p->c[0]!=this&&p->c[1]!=this);
	}
	int dir() {
		return p->c[1]==this;
	}
	void setc(Node* s, int d) {
		c[d]=s;
		if (s) s->p=this;
	}
	void push() {
		if (rev) {
			swap(c[0], c[1]);
			if (c[0]) c[0]->rev^=1;
			if (c[1]) c[1]->rev^=1;
			rev=0;
		}
		if (lt){
			if (c[0]) c[0]->toggle();
			if (c[1]) c[1]->toggle();
			lt=0;
		}
	}
	void toggle(){
		swap(c0, c1);
		lt^=1;
		tg^=1;
	}
	void upd(){
		c1=tg;
		c0=1-tg;
		if (c[0]) {
			c0+=c[0]->c0;
			c1+=c[0]->c1;
		}
		if (c[1]){
			c0+=c[1]->c0;
			c1+=c[1]->c1;
		}
	}
	Node(int i) : id(i) {
		c[0]=0;
		c[1]=0;
		c0=1;
		c1=0;
		tg=0;
		lt=0;
		p=0;
		rev=0;
	}
};
Node*ns[101010];
struct LinkCut {
	void rot(Node* x) {
		Node* p=x->p;
		int d=x->dir();
		if (!p->isr()) {
			p->p->setc(x, p->dir());
			if (p->p) p->p->upd();
		}
		else {
			x->p=p->p;
			if (x->p) x->p->upd();
		}
		p->setc(x->c[!d], d);
		if (p) p->upd();
		x->setc(p, !d);
		if (x) x->upd();
	}
	void pp(Node* x) {
		if (!x->isr()) pp(x->p);
		x->push();
	}
	void splay(Node* x) {
		pp(x);
		while (!x->isr()) {
			if (x->p->isr()) rot(x);
			else if(x->dir()==x->p->dir()) {
				rot(x->p);
				rot(x);
			}
			else {
				rot(x);
				rot(x);
			}
		}
	}
	Node* expose(Node* x) {
		Node* q=0;
		for (;x;x=x->p) {
			splay(x);
			x->c[1]=q;
			x->upd();
			q=x;
		}
		return q;
	}
	void evert(Node* x) {
		x=expose(x);
		x->rev^=1;
		x->push();
	}
	void link(Node* x, Node* y) {
		evert(x);
		evert(y);
		splay(y);
		x->setc(y, 1);
		x->upd();
	}
	void cut(Node* x, Node* y) {
		evert(x);
		expose(y);
		splay(x);
		x->c[1]=0;
		x->upd();
		y->p=0;
	} 
	int rootid(Node* x) {
		expose(x);
		splay(x);
		while(x->c[0]) {
			x=x->c[0];
			x->push();
		}
		splay(x);
		return x->id;
	}
} lc;


int cid[101010];
int isc[101010];

void dfs2(int x, int p, int c){
	cid[x]=c;
	for (int nx:g[x]){
		if (nx!=p&&isc[nx]==0){
			lc.link(ns[nx], ns[x]);
			dfs2(nx, x, c);
		}
	}
}

void toggletree(int a, int b){
	lc.evert(ns[a]);
	lc.expose(ns[b]);
	lc.splay(ns[a]);
	ns[a]->toggle();
	tes+=ns[a]->c1-ns[a]->c0;
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for (int i=0;i<n;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		ns[i]=new Node(i);
	}
	dfs(1, 0);
	for (int i=0;i<(int)cyc.size();i++){
		cp[cyc[i]]=i;
		isc[cyc[i]]=1;
	}
	for (int c:cyc){
		dfs2(c, 0, c);
	}
	init(1, 0, N-1);
	for (int qq=0;qq<m;qq++){
		int a,b;
		scanf("%d %d", &a, &b);
		if (a==b) goto loppu;
		if (cid[a]!=cid[b]){
			togglecpath1(cid[a], cid[b]);
			if (a!=cid[a]){
				toggletree(cid[a], a);
				toggletree(cid[a], cid[a]);
			}
			if (b!=cid[b]){
				toggletree(cid[b], b);
				toggletree(cid[b], cid[b]);
			}
		}
		else{
			toggletree(cid[a], a);
			toggletree(cid[a], b);
		}
		loppu:;
		int cc=n;
		cc-=min((int)cyc.size()-1, ces);
		cc-=tes;
		printf("%d\n", cc);
	}
}