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

struct node {
	int type;
	ll val;
	vector<node*> son;
}pool[1001000],*cur=pool;
char buf[1010000],*pbuf=buf;
int _;
ll r;
char nexttok() {
	if (*pbuf==0) {
		scanf("%s",buf);
		pbuf=buf;
	}
	return *(pbuf++);
}
node *newnode() {
	node *p=cur++;
	p->type=-1;
	p->val=0;
	p->son.clear();
	return p;
}
node* build() {
	node *p=newnode();
	char s=nexttok();
	if (s=='*') {
		p->type=3; // leaf
	} else {
		assert(s=='(');
		node *q=build();
		s=nexttok();
		p->son.pb(q);
		assert(s=='S'||s=='P');
		if (s=='S') p->type=1; else p->type=2;
		while (1) {
			node *q=build();
			p->son.pb(q);
			s=nexttok();
			if (s==')') break;
		}
	}
	return p;
}

void gao(node *u) {
	if (u->type==3) {
		u->val=1;
	} else {
		if (u->type==1) {
			u->val=1ll<<60;
			for (auto v:u->son) {
				gao(v);
				u->val=min(u->val,v->val);
			}
		} else {
			u->val=0;
			for (auto v:u->son) {
				gao(v);
				u->val+=v->val;
			}
		}
	}
}

void gao2(node *u,bool fg) {
	if (u->type==3) {
		printf(" %lld",fg?r:0);
	} else {
		if (u->type==1) {
			bool mv=fg;
			for (auto v:u->son) {
				if (v->val==u->val) {
					gao2(v,mv);
					mv=0;
				} else gao2(v,0);
			}
		} else {
			for (auto v:u->son) {
				gao2(v,fg);
			}
		}
	}
}

void solve() {
	cur=pool;
	scanf("%lld",&r);
	node *rt=build();
	gao(rt);
	printf("REVOLTING");
	r*=rt->val;
	gao2(rt,1);
	puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}