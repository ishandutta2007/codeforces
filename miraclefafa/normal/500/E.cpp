#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=201000;
struct node {
	int c;
	node *l,*r;
}pool[13010000],*cur=pool,*rt;
int cost[N][20],nxt[N][20],w[N],p[N];
int l,r,n,q;
void add(node *p,int l,int r,int x,int v) {
	if (l==r) { if (w[v]>w[p->c]) p->c=v;}
	else {
		int md=(l+r)>>1;
		if (!p->l) p->l=cur++;
		if (!p->r) p->r=cur++;
		if (x<=md) add(p->l,l,md,x,v);
		else add(p->r,md+1,r,x,v);
		if (w[p->l->c]>w[p->r->c]) p->c=p->l->c; else p->c=p->r->c;
	}
}
int query(node *p,int l,int r,int tl,int tr) {
	if (!p) return 0;
	if (l==tl&&r==tr) return p->c;
	else {
		int md=(l+r)>>1;
		if (tr<=md) return query(p->l,l,md,tl,tr);
		else if (tl>md) return query(p->r,md+1,r,tl,tr);
		else {
			int c1=query(p->l,l,md,tl,md),c2=query(p->r,md+1,r,md+1,tr);
			if (w[c1]>w[c2]) return c1; else return c2; 
		}
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",p+i,w+i),w[i]+=p[i];
	p[n+1]=2000000001;
	rt=cur++;
	rep(j,0,19) nxt[n+1][j]=n+1;
	per(i,1,n+1) {
		add(rt,0,2000000000,p[i],i);
		int c=query(rt,0,2000000000,p[i],w[i]);
		if (w[c]<=w[i]) {
			int s=lower_bound(p+1,p+n+2,w[i])-p;
			nxt[i][0]=s,cost[i][0]=p[s]-w[i];
		} else nxt[i][0]=c;
	}
	rep(j,1,19) rep(i,1,n+1) {
		nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		cost[i][j]=cost[i][j-1]+cost[nxt[i][j-1]][j-1];
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&l,&r); r++;
		int c=0,ps=l;
		per(j,0,19) if (nxt[ps][j]<r) c=c+cost[ps][j],ps=nxt[ps][j];
		printf("%d\n",c);
	}
}