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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

#define y1 y2333
const int N=201000,inf=1000000000;
struct item {
	int x,y1,y2,ty;
	item() {}
	item(int x,int y1,int y2,int ty):x(x),y1(y1),y2(y2),ty(ty) {}
};
bool operator < (const item &a,const item &b) {
	return mp(a.x,a.ty)<mp(b.x,b.ty);
} 
vector<item> vec;
int n,x1,y1,x2,y2,f[N];
ll len[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
struct node {
	node *s[2];
	int id,st,cnt;
}pool[14010000],*cur=pool,*rt;
node* add(node *q,int l,int r,int x,int id,int y2) {
	node *p=cur++; if (q) *p=*q; p->st=0;
	if (l==r) p->id=id,p->cnt=1;
	else {
		int md=l+(r-l)/2;
		if (x<=md) p->s[0]=add(p->s[0],l,md,x,id,y2);
		else p->s[1]=add(p->s[1],md+1,r,x,id,y2);
		p->cnt=(p->s[0]?p->s[0]->cnt:0)+(p->s[1]?p->s[1]->cnt:0);
		p->id=max((p->s[0]?p->s[0]->id:0),(p->s[1]?p->s[1]->id:0));
	}
	return p;
}
node* del(node *q,int l,int r,int x,int id) {
	node *p=cur++; if (q) *p=*q; p->st=0;
	if (l==r) p->id=0,p->cnt=0;
	else {
		int md=l+(r-l)/2;
		if (x<=md) p->s[0]=del(p->s[0],l,md,x,id);
		else p->s[1]=del(p->s[1],md+1,r,x,id);
		p->cnt=(p->s[0]?p->s[0]->cnt:0)+(p->s[1]?p->s[1]->cnt:0);
		p->id=max((p->s[0]?p->s[0]->id:0),(p->s[1]?p->s[1]->id:0));
	}
	return p;
}
void merge(node *p) {
	if (p->st) return; p->st=1;
	if (p->s[0]&&p->s[0]->id&&p->s[1]&&p->s[1]->id) f[find(p->s[0]->id)]=find(p->s[1]->id);
	rep(i,0,2) if (p->s[i]) merge(p->s[i]);
}
int query(node *p,int l,int r,int tl,int tr,int id) {
	if (!p||!p->id) return 0;
	if (l==tl&&r==tr) {
		f[find(p->id)]=find(id); merge(p);
		return p->cnt;
	} else {
		int md=l+(r-l)/2;
		if (tr<=md) return query(p->s[0],l,md,tl,tr,id);
		else if (tl>md) return query(p->s[1],md+1,r,tl,tr,id);
		else return query(p->s[0],l,md,tl,md,id)+query(p->s[1],md+1,r,md+1,tr,id);
	}
}
int main() {
	scanf("%d",&n);
	rt=cur++;
	rep(i,1,n+1) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if (x1==x2) vec.pb(item(x1,y1,y2,i));
		else {
			vec.pb(item(x1,y1,x2,-i));
			vec.pb(item(x2,y1,0,i+n));
			len[i]=x2-x1+1;
		}
	}
	rep(i,1,n+1) f[i]=i;
	sort(all(vec));
	for (auto p:vec)
		if (p.ty<0) rt=add(rt,-inf,inf,p.y1,-p.ty,p.y2);
		else if (p.ty<=n) len[p.ty]=p.y2-p.y1+1-query(rt,-inf,inf,p.y1,p.y2,p.ty);
		else rt=del(rt,-inf,inf,p.y1,p.ty-n);
	rep(i,1,n+1) if (find(i)!=i) len[find(i)]+=len[i];
	ll ans=0;
	rep(i,1,n+1) if (find(i)==i) ans=max(ans,len[i]);
	printf("%lld\n",ans-1);
}