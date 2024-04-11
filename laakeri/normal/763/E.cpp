#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

struct Node {
	Node* c[2], *p;
	int id, rev;
	int v, mv;
	int isr() {
		return !p||(p->c[0]!=this&&p->c[1]!=this);
	}
	int dir() {
		return p->c[1]==this;
	}
	void upd(){
		mv=v;
		if (c[0]) mv=min(mv, c[0]->mv);
		if (c[1]) mv=min(mv, c[1]->mv);
	}
	void setc(Node* s, int d) {
		c[d]=s;
		if (s) s->p=this;
		upd();
	}
	void push() {
		if (rev) {
			swap(c[0], c[1]);
			if (c[0]) c[0]->rev^=1;
			if (c[1]) c[1]->rev^=1;
			rev=0;
		}
	}
	Node(int i, int val) : id(i), v(val), mv(val) {
		c[0]=0;c[1]=0;p=0;rev=0;
	}
};
struct LinkCut {
	void rot(Node* x) {
		Node* p=x->p;int d=x->dir();
		if (!p->isr()) p->p->setc(x, p->dir());
		else x->p=p->p;
		p->setc(x->c[!d], d);x->setc(p, !d);
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
				rot(x->p);rot(x);
			}
			else {
				rot(x);rot(x);
			}
		}
	}
	Node* expose(Node* x) {
		Node* q=0;
		for (;x;x=x->p) {
			splay(x);x->c[1]=q;x->upd();q=x;
		}
		return q;
	}
	void evert(Node* x) {
		x=expose(x);x->rev^=1;x->push();
	}
	void link(Node* x, Node* y) {
		evert(x);evert(y);splay(y);x->setc(y, 1);
	}
	void expose(Node* x, Node* y) {
		evert(x);expose(y);splay(x);
	}
	void cut(Node* x, Node* y) {
		expose(x, y);x->c[1]=0;x->upd();y->p=0;
	} 
	int rootid(Node* x) {
		expose(x);splay(x);
		while(x->c[0]) {
			x=x->c[0];x->push();
		}
		splay(x);
		return x->id;
	}
	Node* getMin(Node* x) {
		if (x->v==x->mv) {
			splay(x);
			return x;
		}
		if (x->c[0]&&x->c[0]->mv==x->mv) return getMin(x->c[0]);
		else return getMin(x->c[1]);
	}
	Node* getMinP(Node* x, Node* y) {
		expose(x, y);
		return getMin(x);
	}
};

int ans[101010];
Node* nn[101010];

const int N=1<<17;

int st[2*N];

void add(int i, int v){
	for (i+=N;i;i/=2) st[i]+=v;
}

int sum(int a, int b){
	a+=N;
	b+=N;
	int s=0;
	while (a<=b){
		if (a%2) s+=st[a++];
		if (!(b%2)) s+=st[b--];
		a/=2;
		b/=2;
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		nn[i]=new Node(n*k+i, n*k+i);
	}
	int m;
	cin>>m;
	vector<pair<int, int> > es(m);
	for (int i=0;i<m;i++){
		cin>>es[i].F>>es[i].S;
		if (es[i].F<es[i].S) swap(es[i].F, es[i].S);
	}
	sort(es.begin(), es.end());
	int q;
	cin>>q;
	vector<pair<pair<int, int>, int> > qs(q);
	for (int i=0;i<q;i++){
		cin>>qs[i].F.S>>qs[i].F.F;
		qs[i].S=i;
	}
	sort(qs.begin(), qs.end());
	int i2=0;
	int cc=n;
	LinkCut lc;
	for (auto qq:qs){
		while (i2<m&&es[i2].F<=qq.F.F){
			int x=es[i2].F;
			int y=es[i2].S;
			if (lc.rootid(nn[x])==lc.rootid(nn[y])){
				Node* mn=lc.getMinP(nn[x], nn[y]);
				if (mn->mv<y){
					int a=es[mn->id].F;
					int b=es[mn->id].S;
					lc.cut(nn[a], mn);
					lc.cut(nn[b], mn);
					add(b, -1);
					
					Node* en=new Node(i2, y);
					lc.link(en, nn[x]);
					lc.link(en, nn[y]);
					add(y, 1);
				}
			}
			else{
				Node* en=new Node(i2, y);
				lc.link(en, nn[x]);
				lc.link(en, nn[y]);
				add(y, 1);
				cc--;
			}
			i2++;
		}
		ans[qq.S]=cc+sum(0, qq.F.S-1)-(qq.F.S-1)-(n-qq.F.F);
	}
	for (int i=0;i<q;i++) cout<<ans[i]<<'\n';
}