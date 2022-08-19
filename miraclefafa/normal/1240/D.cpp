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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;

struct node {
	map<int,node*> go;
	int cnt;
	node *p;
}pool[N],*cur,*rt;
int top,s[N],x,n,_;
ll ans;

node *newnode(node *f) {
	node *q=cur++;
	q->go.clear(); q->cnt=0; q->p=f;
	return q;
}

void solve() {
	scanf("%d",&n);
	cur=pool;
	rt=newnode(0);
	top=0;
	node *p=rt;
	p->cnt++;
	ans=0;
	rep(i,1,n+1) {
		scanf("%d",&x);
		if (top==0||s[top-1]!=x) {
			s[top++]=x;
			if (!p->go.count(x)) p->go[x]=newnode(p);
			p=p->go[x];
			ans+=p->cnt;
			p->cnt++;
		} else {
			--top;
			p=p->p;
			ans+=p->cnt;
			p->cnt++;
		}
//		printf("%d %d %d\n",i,ans,p-pool);
	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}