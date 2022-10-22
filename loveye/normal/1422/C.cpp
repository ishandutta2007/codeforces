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

const int MOD = 1e9 + 7,N = 1e5 + 5,inv9 = (MOD+1) / 9;
char s[N];
int n;
LL pw[N];
LL f(int x) {return (pw[x+1]-1) * inv9 % MOD;}
int main() {
	cin >> s+1;
	n = strlen(s+1);
	pw[0] = 1; fr(i,1,n) pw[i] = pw[i-1] * 10 % MOD;
	LL sum = 0,ans = 0;
	fr(i,1,n) {
		sum = (sum * 10 + s[i]-'0') % MOD;
		(ans += sum * f(n-i-1)) %= MOD;
	}
	sum = 0;
	rf(i,n,1) {
		(sum = sum + pw[n-i] * (s[i]-'0')) %= MOD;
		(ans += sum * (i-1)) %= MOD;
	}
	cout << ans << endl;
	return 0;
}