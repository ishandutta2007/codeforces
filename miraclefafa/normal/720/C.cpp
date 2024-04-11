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
int val[N];
int _,n,m,k;
int count() {
	int cnt=0;
	rep(i,0,n-1) rep(j,0,m-1)  {
		int id=i*m+j;
		cnt+=val[id]&val[id+m]&val[id+1];
		cnt+=val[id+m+1]&val[id+m]&val[id+1];
		cnt+=val[id]&val[id+m]&val[id+m+1];
		cnt+=val[id]&val[id+1]&val[id+m+1];
	}
	return cnt;
}
int check(int md) {
	rep(i,0,n*m) val[i]=i<md;
	return count();
}
int q[N],vis[N];
bool connected() {
	int t=0;
	rep(i,0,n*m) if (val[i]) {q[t++]=i; break;}
	rep(i,0,n*m) vis[i]=0;
	vis[q[0]]=1;
	rep(i,0,t) {
		int u=q[i];
		if (u%m>0&&val[u-1]&&!vis[u-1]) {
			q[t++]=u-1; vis[u-1]=1;
		}
		if (u%m<m-1&&val[u+1]&&!vis[u+1]) {
			q[t++]=u+1; vis[u+1]=1;
		}
		if (u/m>0&&val[u-m]&&!vis[u-m]) {
			q[t++]=u-m; vis[u-m]=1;
		}
		if (u/m<n-1&&val[u+m]&&!vis[u+m]) {
			q[t++]=u+m; vis[u+m]=1;
		}
	}
	rep(i,0,n*m) if (vis[i]!=val[i]) return 0;
	return 1;
}
bool gao(int n,int m,int t) {
	if (t>4*(n-1)*(m-1)) return 0;
	if (n==3||m==3) {
		int rem=4*(n-1)*(m-1)-t;
		if (rem==1||rem==2||rem==4||rem==5) return 0;
	} else {
		int rem=4*(n-1)*(m-1)-t;
		if (rem==1||rem==2||rem==4||rem==5||rem==8) return 0;
	}
	int l=0,r=n*m+1;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)>=t) r=md; else l=md;
	}
	int c=check(r);
	if (c==t) {
		return 1;
	}
	VI bl,em;
	rep(i,0,n*m) if (i/m<=1||abs(i/m-r/m)<=1) {
		if (val[i]) bl.pb(i); else em.pb(i);
	}
	while (c!=t) {
		if (c<t) {
			assert(!em.empty());
			int p=rand()%SZ(em);
			int v=em[p];
			val[v]=1;
			if (!connected()) {
				val[v]=0;
				continue;
			}
			em.erase(em.begin()+p);
			bl.pb(v);
			val[v]=1;
			c=count();
		} else {
			assert(!bl.empty());
			int p=rand()%SZ(bl);
			int v=bl[p];
			val[v]=0;
			if (!connected()) {
				val[v]=1;
				continue;
			}
			bl.erase(bl.begin()+p);
			em.pb(v);
			val[v]=0;
			c=count();			
		}
	}
	assert(t==count());
	assert(connected());
	return 1;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&n,&m,&k);
		if (!gao(n,m,k)) {
			puts("-1");
			puts("");
		} else {
			rep(i,0,n) {
				rep(j,0,m) if (val[i*m+j]) putchar('*'); else putchar('.');
				puts("");
			}
			puts("");
		}
	}
}