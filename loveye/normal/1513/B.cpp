#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5,MOD = 1e9 + 7;
int n,a[N];
bool vis[N];
int main() {
	int t;cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) cin >> a[i],vis[i] = 1;
		fr(i,0,30) {
			int cnt = 0;
			fr(j,1,n) if(a[j] >> i & 1) ++cnt;
			if(cnt == n) continue;
			fr(j,1,n) if(a[j] >> i & 1) vis[j] = 0;
		}
		int cnt = 0;
		fr(i,1,n) if(vis[i]) ++cnt;
		LL res = 1;
		fr(i,1,n-2) res = res * i % MOD;
		printf("%lld\n",1ll * cnt * (cnt-1) % MOD * res % MOD);
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}