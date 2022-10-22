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
int sum[N],a[N],n;
inline int highbit(int x) {
	while(x != (x & -x)) x ^= x & (-x);
	return x;
}
int main() {
		cin >> n;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		int ans = n+1;
		for(int i = 1;i <= n;++i)
			if(highbit(a[i-1]) == highbit(a[i]) && highbit(a[i]) == highbit(a[i+1])) {
				ans = 1;break;
			}
		if(ans == 1) {cout << ans << endl;return 0;}
		fr(i,1,n) sum[i] = sum[i-1] ^ a[i];
		fr(l,0,n) {
			fr(r,l+1,n) {
				if(l && (a[l] > (sum[r] ^ sum[l]))) ans = min(ans,r-l-1);
				if(r+1 <= n && (sum[r] ^ sum[l]) > a[r+1]) ans = min(ans,r-l-1);
				fr(k,r+1,n) if((sum[l] ^ sum[r]) > (sum[r] ^ sum[k]))
					ans = min(ans,k-r-1 + r-l-1);
			}
		}
		if(ans <= n) cout << ans << endl;
		else cout << -1 << endl;
	return 0;
}