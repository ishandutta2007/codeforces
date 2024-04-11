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

const int N=401000;
int a[N],b[N],mark[N],n,q,t[N];
ll dp[N],s[N],c[N];

struct node {
	node *l,*r;
	ll s;
}pool[201000*25],*cur=pool,*T[N];

node *newnode() {
	return cur++;
}

node* build(int l,int r) {
	node *p=newnode();
	if (l==r) {
	} else {
		int md=(l+r)>>1;
		p->l=build(l,md);
		p->r=build(md+1,r);
	}
	return p;
}
ll query(node *p,int l,int r,int tl,int tr) {
	if (tl>tr) return 0;
	if (tl==l&&tr==r) return p->s;
	else {
		int md=(l+r)>>1;
		if (tr<=md) return query(p->l,l,md,tl,tr);
		else if (tl>md) return query(p->r,md+1,r,tl,tr);
		else return query(p->l,l,md,tl,md)+query(p->r,md+1,r,md+1,tr);
	}
}
node* modify(node *p,int l,int r,int x,int v) {
	node *q=cur++; *q=*p; q->s+=v;
	if (l!=r) {
		int md=(l+r)>>1;
		if (x<=md) q->l=modify(p->l,l,md,x,v);
		else q->r=modify(p->r,md+1,r,x,v);
	}
	return q;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d",a+i,b+i);
		mark[a[i]]=-i;
		mark[b[i]]=i;
	}
	T[0]=build(1,2*n);
	rep(i,1,2*n+1) {
		if (mark[i]>0) {
			int id=mark[i];
			dp[id]=(1+query(T[i-1],1,2*n,a[id]+1,i-1))%mod;
			T[i]=modify(T[i-1],1,2*n,a[id],dp[id]);
			s[i]=(s[i-1]+dp[id])%mod;
		} else {
			s[i]=s[i-1];
			T[i]=T[i-1];
		}
	}
	scanf("%d",&q);
	rep(i,1,q+1) scanf("%d",t+i);
	sort(t+1,t+q+1,[&](int x,int y) {
		return b[x]>b[y];
	});
	int ans=s[b[t[1]]-1]+1,o=a[t[1]];
	rep(i,2,q+1) {
		int id=t[i];
		//printf("zz %d %d %d\n",o,ans,a[id]);
		if (o>a[id]) continue;
		ans=(ans+1+query(T[b[id]-1],1,2*n,o+1,b[id]-1))%mod;
		//ans=(ans+query(b[id]-1)-query(o)+1)%mod;
		o=a[id];
	}
	printf("%d\n",ans);
}