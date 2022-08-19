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
const ll mod=1000000007;
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int u,v,p,w,ty;
queue<PII> q;
map<int,int> hs;
map<int,PII> pre;
void add(int z,int way) {
	if (hs.count(z)) {
		if (hs[z]==ty) return;
		else {
			int c=z;
			VI ret;
			while (c!=u&&c!=v) {
				auto d=pre[c];
				ret.pb(d.se);
				c=d.fi;
			}
			reverse(all(ret));
			ret.pb(way);
			int b=w;
			while (b!=u&&b!=v) {
				auto d=pre[b];
				ret.pb(d.se);
				b=d.fi;
			}
			if (c==v) reverse(all(ret));
			int ww=u;
			printf("%d\n",SZ(ret));
			for (auto q:ret) {
				printf("%d ",q);
				if (q==1) ww=(ww+1)%p;
				else if (q==2) ww=(ww+p-1)%p;
				else ww=powmod(ww,p-2,p);
			}
			assert(ww==v);
			puts("");
			exit(0);
		}
	}
	q.push(mp(z,ty));
	hs[z]=ty;
	pre[z]=mp(w,way);
}
int main() {
	scanf("%d%d%d",&u,&v,&p);
	if (u==v) {
		puts("0");
		return 0;
	}
	hs[u]=1;
	hs[v]=2;
	q.push(mp(u,1)); q.push(mp(v,2));
	while (!q.empty()) {
		auto z=q.front(); q.pop();
		w=z.fi; ty=z.se;
		add((w+1)%p,ty==1?1:2);
		add((w+p-1)%p,ty==1?2:1);
		add(powmod(w,p-2,p),3);
	}
}