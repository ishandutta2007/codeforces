#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=201000;
struct event{
	int l,r,v,id,w;
}evt[N];
int h,w,n,u,l,r,s,tot;
map<int,int> dp;
bool cmp(event &a,event &b) {
	return a.v<b.v||(a.v==b.v&&a.id<b.id);
}
set<int> nd[4*N];
int query(int p,int l,int r,int x) {
	int v=nd[p].empty()?0:*nd[p].rbegin();
//	printf("%d %d %d %d\n",p,l,r,x);
	if (l!=r) {
		int md=(l+r)>>1;
		if (x<=md) v=max(v,query(p+p,l,md,x));
		else v=max(v,query(p+p+1,md+1,r,x));
	}
	return v;
}
void add(int p,int l,int r,int tl,int tr,int v) {
//	printf("add %d %d %d %d %d %d\n",p,l,r,tl,tr,v);
	if (tl==l&&tr==r) nd[p].insert(v);
	else {
		int md=(l+r)>>1;
		if (tr<=md) add(p+p,l,md,tl,tr,v);
		else if (tl>md) add(p+p+1,md+1,r,tl,tr,v);
		else add(p+p,l,md,tl,md,v),add(p+p+1,md+1,r,md+1,tr,v);
	}
}
void del(int p,int l,int r,int tl,int tr,int v) {
//	printf("del %d %d %d %d %d %d\n",p,l,r,tl,tr,v);
	if (tl==l&&tr==r) nd[p].erase(nd[p].lower_bound(v));
	else {
		int md=(l+r)>>1;
		if (tr<=md) del(p+p,l,md,tl,tr,v);
		else if (tl>md) del(p+p+1,md+1,r,tl,tr,v);
		else del(p+p,l,md,tl,md,v),del(p+p+1,md+1,r,md+1,tr,v);
	}
}
void upd(int &a,int b) {
	a+=b; if (a>=mod) a-=mod;
}
int main() {
	scanf("%d%d%d",&h,&w,&n);
	rep(i,1,n+1) {
		scanf("%d%d%d%d",&u,&l,&r,&s);
		evt[tot++]=(event){l,r,u,i,u};
		if (u+s<=h) evt[tot++]=(event){l,r,u+s+1,-i,u};
	}
	dp[0]=1;
	sort(evt,evt+tot,cmp);
	add(1,1,w,1,w,0);
	rep(i,0,tot) {
		if (evt[i].id>=0) {
			int u=evt[i].v;
			if (evt[i].l==1) upd(dp[u],dp[query(1,1,w,evt[i].r+1)]);
				else upd(dp[u],dp[query(1,1,w,evt[i].l-1)]);
			if (evt[i].r==w) upd(dp[u],dp[query(1,1,w,evt[i].l-1)]);
				else upd(dp[u],dp[query(1,1,w,evt[i].r+1)]);
//			printf("%d %d\n",u,dp[u]);
			add(1,1,w,evt[i].l,evt[i].r,evt[i].v);
		} else {
			del(1,1,w,evt[i].l,evt[i].r,evt[i].w);	
		}
	}
	int ret=0;
	rep(i,1,w+1) upd(ret,dp[query(1,1,w,i)]);
	printf("%d\n",ret);
}