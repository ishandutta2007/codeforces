#include<bits/stdc++.h>
using namespace std;

#define int long long
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

const int N = 2e5 + 5,M = 65;
int n,p,m,f[1 << 16];
LL a[N];
char s[N][M];
int calc(LL x,LL y) {
	x = a[x]; y = a[y];
	int cnt = 0,res = 0;
	while(y) {
		LL d = y & -y;
		if(x & d) res |= 1ll << cnt;
		y ^= d;
		++cnt;
	}
	return res;
}
int pct[1 << 16];
LL work(int x,LL s) {
	s = a[s];
	int cnt = 0; LL res = 0;
	while(s) {
		LL d = s & -s;
		if(x >> cnt & 1ll) res |= d,x ^= 1ll << cnt;
		s ^= d;
		++cnt;
	}
	assert(x == 0);
	return res;
}
mt19937 rnd(clock());
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> p;
	fo(i,1ll,1ll << p) pct[i] = pct[i>>1ll] + (i&1ll);
	fr(i,1ll,n) {
		cin >> (&s[i][0]);
		fo(j,0,m) if(s[i][j] == '1') a[i] |= 1ll << j;
	}
	int ans = 0; LL out = 0;
	fr(kase,1ll,40) {
		int S = rnd() % n + 1ll;
		fo(i,0,1ll << p) f[i] = 0;
		fr(i,1ll,n) f[calc(i,S)]++;
		for(int len = 1ll;len < 1ll << p;len <<= 1ll)
			for(int st = 0;st < 1ll << p;st += len << 1ll)
				fo(d,0,len) f[st+d] += f[st+d+len];
		fo(i,0,1ll << p) if(f[i] >= (n+1ll>>1ll) && ans < pct[i])
			ans = pct[i],out = work(i,S);
	}
	fo(i,0,m) cout << (out >> i & 1ll);
	cout << endl;
	return 0;
}