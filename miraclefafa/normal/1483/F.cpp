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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int AC_SIGMA=26,AC_V=27,AC_N=1010000;
const int N=1010000;
struct AC_automaton {
	struct node {
		node *go[AC_V],*fail,*f,*lst;
		vector<node*> son;
		int fg,l,r,dep;
		//string token;
	}pool[AC_N],*cur,*root,*q[AC_N];
	node* newnode() {
		node *p=cur++;
		memset(p->go,0,sizeof(p->go)); p->fail=p->f=NULL; p->fg=0;
		return p;
	}
	void init() { cur=pool; root=newnode();}
	node* append(node *p,int w) {
		if (!p->go[w]) p->go[w]=newnode(),p->go[w]->f=p;
		//p->go[w]->token=p->token; p->go[w]->token.pb(w+'a');
		return p=p->go[w];
	}
	void build() {
		int t=1;
		q[0]=root;
		rep(i,0,t) rep(j,0,AC_SIGMA) if (q[i]->go[j]) {
			node *v=q[i]->go[j],*p=v->f->fail;
			while (p&&!p->go[j]) p=p->fail;
			if (p) v->fail=p->go[j]; else v->fail=root;
			q[t++]=q[i]->go[j];
		}
		//rep(i,0,t) if (q[i]->fail) q[i]->fg+=q[i]->fail->fg;
		rep(i,0,t) rep(j,0,AC_SIGMA) if (!q[i]->go[j]) {
			node *p=q[i]->fail;
			if (!p) q[i]->go[j]=root; else q[i]->go[j]=p->go[j];
		}
		root->fail=root;
		rep(i,0,t) {
			node *p=q[i];
			if (p->fg) p->lst=p; else p->lst=p->fail->lst;
		}
		rep(i,1,t) {
			node *p=q[i];
			p->fail->son.pb(p);
			p->dep=p->fail->dep+1;
			//printf("%s %d\n",p->token.c_str(),p->fg);
		}
		int tot=0;
		function<void(node*)> dfs=[&](node *p) {
			p->l=++tot;
			for (auto q:p->son) dfs(q);
			p->r=tot;
		};
		dfs(root);
	}
}T;
typedef AC_automaton::node ACnode;

int n;
char s[N];
string ss[N];
ACnode *pos[N];
int ret;
int main() {
	scanf("%d",&n);
	T.init();
	ACnode *rt=T.root;
	rep(i,1,n+1) {
		scanf("%s",s);
		int m=strlen(s);
		ss[i]=s;
		ACnode *p=rt;
		rep(j,0,m) p=T.append(p,s[j]-'a');
		p->fg=i;
	}
	T.build();
	rep(i,1,n+1) {
		int m=ss[i].size();
		ACnode *p=rt;
		pos[0]=p;
		rep(j,0,m) {
			int w=ss[i][j]-'a';
			p=p->go[w];
			pos[j+1]=p;
		}
		set<int> tab,ans;
		ACnode *cur=NULL;
		pos[m]=pos[m]->fail;
		per(j,0,m+1) {
			bool del=1;
			if (cur!=NULL) cur=cur->f;
			if (pos[j]->lst!=NULL) {
				if (cur==NULL||pos[j]->lst->dep>cur->dep) cur=pos[j]->lst,del=0;
			}
			if (cur!=NULL) {
				if (del==0) tab.insert(cur->fail->l);
				else tab.insert(cur->l);
			}
		}
		rep(j,0,m+1) {
			if (pos[j]->lst!=NULL) {
				ACnode *q=pos[j]->lst;
				auto it=tab.lower_bound(q->l);
				//printf("ff %d %s\n",j,q->token.c_str());
				if (it==tab.end()||*it>q->r) {
					ans.insert(q->l);
				}
			}
		}
		ret+=SZ(ans);
		//printf("zz %d\n",SZ(ans));
	}
	printf("%d\n",ret);
}