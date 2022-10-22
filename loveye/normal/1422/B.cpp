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

const int N = 105;
int t,n,m,a[N][N];
LL b[4];
int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		fr(i,1,n) fr(j,1,m) cin >> a[i][j];
		LL ans = 0;
		fr(i,1,n+1>>1) fr(j,1,m+1>>1) {
			b[0] = a[i][j];
			b[1] = a[n+1-i][j];
			b[2] = a[i][m+1-j];
			b[3] = a[n+1-i][m+1-j];
			sort(b,b+4);
			if(n+1-i == i || m+1-j == j) ans += b[3]-b[0];
			else ans += b[1] - b[0] + b[2] - b[1] + b[3] - b[1];
//			cerr << '!' << endl;
		}
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