#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
struct node {
	node *s[2],*f;
	vector<pair<char,node*> > son;
	int val,d,dp;
	int mark;
	int add;
	bool isr() { return !f||(f->s[0]!=this && f->s[1]!=this);}
	bool dir() { return f->s[1]==this;}
	void setc(node *c,int d) { s[d]=c;if (c) c->f=this;}
	void seta(int a) {
		add+=a; d+=a; val+=a;
	}
	void push() {
		if (add) {
			rep(i,0,2) if (s[i]) s[i]->seta(add);
			add=0;
		}
	}
	void upd() {
		val=d; assert(add==0);
		rep(i,0,2) if (s[i]) val=min(val,s[i]->val);

	}
}nd[N];
stack<node*> sta;
void rot(node *x) {
	node *p=x->f;bool d=x->dir();
	if (!p->isr()) p->f->setc(x,p->dir()); else x->f=p->f;
	p->setc(x->s[!d],d);x->setc(p,!d);
	p->upd();
}
void splay(node *x) {
	node *q=x;
	while (1) { sta.push(q);if (q->isr()) break; q=q->f; }
	while (!sta.empty()) sta.top()->push(),sta.pop();
	while (!x->isr()) {
		if (x->f->isr()) rot(x);
		else if (x->dir()==x->f->dir()) rot(x->f),rot(x);
		else rot(x),rot(x);
	}
	x->upd();
}
node *expose(node *x) {
	node *q=NULL;
	for (;x;x=x->f) splay(x),x->s[1]=q,(q=x)->upd();
	return q;
}

int p[N],n,k,ret[N];
char s[10];

void dfs(node *u) {
	expose(u); splay(u);
	if (u!=nd) u->d=u->dp=nd[p[u-nd]].dp+1;
	u->upd();
	if (u->mark) {
		//puts("set ff");
		u->seta(1); u->push();
		if (u->val<u->dp) {
			u->dp=u->val;
			u->d=min(u->d,u->val+1);
		}
		u->dp=min(u->dp,u->val);
		ret[u->mark]=u->dp;
	}
	//printf("%d %d %d\n",u-nd,u->dp,u->d);
	sort(all(u->son));
	for (auto p:u->son) dfs(p.se);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%s",p+i,s);
		nd[p[i]].son.pb(mp(s[0],nd+i));
		nd[i].f=nd+p[i];
		nd[i].d=nd[i].dp=1<<30; nd[i].upd();

	}
	scanf("%d",&k);
	rep(i,1,k+1) {
		int x;
		scanf("%d",&x);
		nd[x].mark=i;
	}
	dfs(nd);
	rep(i,1,k+1) printf("%d%c",ret[i]," \n"[i==k]);
}
/////  change n to 1e6