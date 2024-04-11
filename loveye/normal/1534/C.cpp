#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 4e5 + 5,MOD = 1e9 + 7;
int t,n,a[N],b[N],p[N];
bool vis[N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) cin >> a[i];
		fr(i,1,n) cin >> b[i],p[a[i]] = b[i];
		fr(i,1,n) vis[i] = 0;
		int cnt = 0;
		fr(i,1,n) if(!vis[i]) {
			int cur = i;
			do vis[cur] = 1,cur = p[cur];
			while(!vis[cur]);
			++cnt;
		}
		LL ans = 1;
		fr(i,1,cnt) ans = ans * 2 % MOD;
		cout << ans << endl;
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