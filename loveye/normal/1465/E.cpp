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

const int N = 1e5 + 5;
int n;
LL t;
char s[N];
int cnt[30];
#define id(x) (x-'a')
int main() {
	cin >> n >> t >> s+1;
	t -= 1 << id(s[n]);
	t += 1 << id(s[n-1]);
	fr(i,1,n-2) ++cnt[id(s[i])];
	fr(i,0,25) t += 1ll * (1 << i) * cnt[i];
	rf(i,25,0) {
		while(cnt[i] && t >= (1 << i+1))
			t -= 1 << i+1,--cnt[i];
	}
	cout << (t ? "No" : "Yes") << endl;
	return 0;
}