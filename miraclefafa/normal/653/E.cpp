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

const int N=301000;
set<int> unv,e[N];
int n,m,k,a[N],b[N],cp,t,q[N];
void add(int u) {
	q[t++]=u; unv.erase(u);
}
void gao(int u) {
	t=0;
	add(u);
	rep(i,0,t) {
		u=q[i];
		int pre=1;
		while (1) {
			auto x=unv.upper_bound(pre);
			if (x==unv.end()) break;
			int v=*x; pre=v;
			if (e[u].count(v)) continue;
			add(v);
		}
	}
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m) {
		scanf("%d%d",a+i,b+i);
		e[a[i]].insert(b[i]);
		e[b[i]].insert(a[i]);
	}
	rep(i,2,n+1) unv.insert(i);
	rep(i,2,n+1) if (unv.count(i)) {
		cp++;
		gao(i);
		bool fg=0;
		rep(j,0,t) if (!e[1].count(q[j])) fg=1;
		if (!fg) {
			puts("impossible");
			return 0;
		}
	}
	if (k<cp||k>n-1-SZ(e[1])) {
		puts("impossible");
		return 0;
	}
	puts("possible");
}