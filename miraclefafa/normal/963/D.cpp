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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
struct node {
	node *go[30],*p;
	vector<node*> son;
	vector<PII> q;
	int val,cnt;
}pool[N],*cur=pool,*rt;
char s[N],t[N];
int n;

node* newnode() {
	node *p=cur++;
	p->val=p->cnt=0; p->p=0;
	p->son.clear();
	return p;
}
node *append(node *p,int w) {
	node *np=newnode();np->val=p->val+1;
	for (;p&&!p->go[w];p=p->p) p->go[w]=np;
	if (!p) np->p=rt;
	else {
		node *q=p->go[w];
		if (q->val==p->val+1) np->p=q;
		else {
			node *nq=newnode();
			nq->val=p->val+1;
			memcpy(nq->go,q->go,sizeof(q->go));
			nq->p=q->p;
			np->p=q->p=nq;
			for (;p&&p->go[w]==q;p=p->p) p->go[w]=nq;
		}
	}
	return np;
}
void init() {
	cur=pool;
	rt=newnode();
	node *np=rt;
	rep(i,1,n+1) {
		np=append(np,s[i]-'a');
		np->cnt=i;
	}
	for (node *p=pool;p!=cur;p++) if (p->p) p->p->son.pb(p);
}
int q,c,ret[N];
int tot=0;
vector<PII> seq;
void dfs(node *p) {
	int pl=tot++;
	if (p->cnt) seq.pb(mp(pl,p->cnt));
	rep(i,0,SZ(p->son)) dfs(p->son[i]);
	if (!p->q.empty()) {
		VI c;
		for (auto it=lower_bound(all(seq),mp(pl,-1));it!=seq.end();it++) c.pb(it->se);
		sort(all(c));
		map<int,int> val;
		for (auto w:p->q) {
			if (w.fi>SZ(c)) ret[w.se]=-1;
			else {
//				rep(j,0,SZ(c)) printf("%d ",c[j]); puts("");
				if (val.count(w.fi)) {
					ret[w.se]+=val[w.fi];
					continue;
				}
				int mval=1e9;
				rep(i,0,SZ(c)) if (i+w.fi-1<SZ(c)) mval=min(mval,c[i+w.fi-1]-c[i]); else break;
				val[w.fi]=mval;
				ret[w.se]+=mval;
			}
		}
	}
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	init();
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%s",&c,t);
		int m=strlen(t);
		node *p=rt;
		rep(j,0,m) {
			int w=t[j]-'a';
			if (!p->go[w]) { ret[i]=-1; break; }
			else p=p->go[w];
		}
		if (ret[i]!=-1) {
			ret[i]=m;
			p->q.pb(mp(c,i));
		}
	}
	dfs(rt);
	rep(i,0,q) printf("%d\n",ret[i]);
}