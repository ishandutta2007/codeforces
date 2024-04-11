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

const int N = 2e5 + 5;
int n,a[N];
char s[N],t[N];
int BIT[N];
int cnt[N],nxt[N],sav[N],pos[N];
void add(int x,int v) {
	for(;x <= n;x += x & -x) BIT[x] += v;
}
int ask(int x) {
	int res = 0;
	for(;x;x -= x & -x) res += BIT[x];
	return res;
}
int main() {
	cin >> n >> s+1;
	fr(i,1,n) t[i] = s[n+1-i];
	rf(i,n,1) {
		nxt[i] = sav[s[i]];
		sav[s[i]] = i;
		++cnt[s[i]];
	}
	fr(i,1,n) {
		if(!pos[t[i]]) pos[t[i]] = sav[t[i]];
		else pos[t[i]] = nxt[pos[t[i]]];
		a[pos[t[i]]] = i;
	}
	LL ans = 0;
	rf(i,n,1) {
		ans += ask(a[i]);
		add(a[i],1);
	}
	cout << ans << endl;
	return 0;
}