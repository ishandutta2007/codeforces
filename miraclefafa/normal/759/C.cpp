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

const int N=101000;
int n,p,t,num[N];
struct node {
	int fg,mv;
}nd[4*N];
void upd(int p) {
	nd[p].mv=max(nd[p+p].mv,nd[p+p+1].mv);
}
void setf(int p,int v) {
	nd[p].fg+=v; nd[p].mv+=v;
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
int query(int p,int l,int r) {
	if (l==r) return l;
	else {
		push(p);
		int md=(l+r)>>1;
		if (nd[p+p].mv>0) return query(p+p,l,md); else return query(p+p+1,md+1,r);
	}
}
void modify(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
//		printf("%d %d %d %d %d\n",p,tl,tr,v,nd[p].mv);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",&p,&t);
		p=n+1-p;
		if (t==1) {
			scanf("%d",&t);
			num[p]=t;
			modify(1,1,n,p,n,1);
		} else {
			modify(1,1,n,p,n,-1);
		}
		if (nd[1].mv<=0) puts("-1");
		else {
			int v=query(1,1,n);
			printf("%d\n",num[v]);
		}
	}
}