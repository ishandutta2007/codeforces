#include<bits/stdc++.h>
using namespace std;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5;
#define int long long
int n,a[N],dp[N],x,y,p,k,ans;
char s[N];
signed main() {
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--) {
		cin >> n >> p >> k;
		cin >> s+1;
		cin >> x >> y;
		rf(i,n,n-k+1) dp[i] = (s[i] == '0') * x;
		rf(i,n-k,1) dp[i] = dp[i+k] + (s[i] == '0') * x;
		ans = 0xfeeddeadbeef;
		fr(i,p,n) ans = min(ans,dp[i] + (i-p) * y);
		cout << ans << endl;
	}
	return 0;
}