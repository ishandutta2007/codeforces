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
int n,q[N],p[N],tot,m,lab[N],f[N],ord[N],s[N];
deque<int> e[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }

void merge(int u,int v,int seg) {
	seg++;
	rep(i,0,seg+1) {
		int f1=SZ(e[u])-1-i;
		int g1=i;
		f[find(e[u][f1])]=find(e[v][g1]);
	}
	rep(i,0,seg) e[u].pop_back();
	rep(i,seg+1,SZ(e[v])) e[u].pb(e[v][i]);
	e[u].push_front(e[v][0]);
	p[u]=p[u]+p[v]-2*(seg-1);
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",p+i); q[i]=p[i];
		rep(j,0,p[i]) e[i].pb(++tot);
		p[i]-=2;
	}
	rep(i,1,tot+1) f[i]=i;
	rep(i,0,n) ord[i]=i;
	sort(ord,ord+n,[&](int a,int b) {
		return p[a]>p[b];
	});
	per(i,0,n) s[i]=s[i+1]+p[ord[i]];
	rep(i,1,n) {
		int z=s[i+1];
		if (p[ord[0]]<p[ord[i]]) {
			swap(ord[0],ord[i]);
		}
		int u=p[ord[0]],v=p[ord[i]];
		if (u+v<=z) {
			merge(ord[0],ord[i],0);
		} else {
			if (u-v>z) merge(ord[0],ord[i],v);
			else {
				int f=(u+v-z)/2;
				if (u+v-2*f>z) f++;
				f=max(f,0); f=min(f,v);
				if (u==v) f=min(f,u-1);
				merge(ord[0],ord[i],f);
			}
		}
	}
	rep(i,1,tot+1) if (find(i)==i) lab[i]=++m;
	int z=0;
	printf("%d\n",m);
	rep(i,0,n) {
		rep(j,0,q[i]) printf("%d ",lab[find(z+1+j)]);
		z+=q[i];
		puts("");
	}
}