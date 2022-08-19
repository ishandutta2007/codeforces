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
set<PII> f[N],g[N];
ll t[N];
int x,y,n,m,k;
void add(int x,int y,int id) {
	f[x+y].insert(mp(x,id));
	g[x+m-y].insert(mp(x,id));
}
int go(int &x,int &y,int dir,ll &t) {
	if (dir==0) {
		auto it=g[x+m-y].upper_bound(mp(x,-1));
		assert(it!=g[x+m-y].end());
		int st=it->fi-x,id=it->se;
		x+=st,y+=st; t+=st;
		f[x+y].erase(mp(x,id));
		g[x+m-y].erase(mp(x,id));
		return id;
	} else if (dir==2) {
		auto it=g[x+m-y].lower_bound(mp(x,-1));
		assert(it!=g[x+m-y].begin());
		--it;
		int st=x-it->fi,id=it->se;
		x-=st,y-=st; t+=st;
		f[x+y].erase(mp(x,id));
		g[x+m-y].erase(mp(x,id));
		return id;		
	} else if (dir==3) {
		auto it=f[x+y].upper_bound(mp(x,-1));
		assert(it!=f[x+y].end());
		int st=it->fi-x,id=it->se;
		x+=st,y-=st; t+=st;
		f[x+y].erase(mp(x,id));
		g[x+m-y].erase(mp(x,id));
		return id;
	} else {
		auto it=f[x+y].lower_bound(mp(x,-1));
		assert(it!=f[x+y].begin());
		--it;
		int st=x-it->fi,id=it->se;
		x-=st,y+=st; t+=st;
		f[x+y].erase(mp(x,id));
		g[x+m-y].erase(mp(x,id));
		return id;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	rep(i,0,k) {
		scanf("%d%d",&x,&y);
		t[i]=-1;
		add(x,y,i);
	}
	rep(i,0,n+1) {
		add(i,0,-1);
		add(i,m,-1);
	}
	rep(i,1,m) add(0,i,-1),add(n,i,-1);
	int dir=0,x=0,y=0;
	ll mt=0;
	while (1) {
		int id=go(x,y,dir,mt);
//		printf("%d %d\n",x,y);
		if ((x==0||x==n)&&(y==0||y==m)) {
			break;
		}
		if (id!=-1) t[id]=mt;
		else {
			if (x==n||x==0) dir=dir^1;
			else dir=dir^3;
		}
	}
	rep(i,0,k) printf("%lld\n",t[i]);
}