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
int T,n,w,a[N],cnt[N];
int main() {
	cin >> T;
	while(T--) {
		cin >> n >> w;
		fr(i,1,n) cin >> a[i],++cnt[int(log2(a[i]))];
		int ans = 0;
		while(++ans) {
			int ok = 1,res = w;
			rf(i,30,0) {
				int c = min(res >> i,cnt[i]);
				cnt[i] -= c;
				res -= c << i;
				if(c) ok = 0;
			}
			if(ok) break;
		}
		cout << ans-1 << endl;
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