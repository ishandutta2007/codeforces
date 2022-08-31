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

const int N=1010000;
int mt[N],c[N],a[N],t[N],x[N],ret[N],n,T;
VI vt,vx;
vector<pair<int,PII> > opt[N];
void modify(int x,int s) {
	for (;x<=n;x+=x&-x) {
		if (mt[x]!=T) mt[x]=T,c[x]=0;
		c[x]+=s;
	}
} 
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) {
		if (mt[x]!=T) mt[x]=T,c[x]=0;
		s+=c[x];
	}
	return s;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d",a+i,t+i,x+i);
		vt.pb(t[i]); vx.pb(x[i]);
	}
	sort(all(vt)); sort(all(vx));
	vx.erase(unique(all(vx)),vx.end());
	int m=SZ(vx);
	rep(i,0,n) {
		x[i]=lower_bound(all(vx),x[i])-vx.begin()+1;
		t[i]=lower_bound(all(vt),t[i])-vt.begin()+1;
		opt[x[i]].pb(mp(t[i],mp(a[i],i)));
	}
	rep(i,1,m+1) {
		T=i;
		for (auto q:opt[i]) {
			if (q.se.fi==1) modify(q.fi,1);
			else if (q.se.fi==2) modify(q.fi,-1);
			else ret[q.se.se]=query(q.fi);
		}
	}
	rep(i,0,n) if (a[i]==3) {
		printf("%d\n",ret[i]);
	}
}