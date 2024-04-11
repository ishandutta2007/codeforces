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
int n,p,L[N],R[N],a[N];
int mn[20][N],gd[20][N];
int gcd(int x,int y) {
	return !y ? x : gcd(y,x % y);
}
I build() {
	fr(i,1,n) mn[0][i] = i,gd[0][i] = a[i];
	fr(i,1,18) fr(j,1,n+1-(1<<i)) {
		if(a[mn[i-1][j]] < a[mn[i-1][j+(1<<i-1)]])
			mn[i][j] = mn[i-1][j];
		else mn[i][j] = mn[i-1][j+(1<<i-1)];
		gd[i][j] = gcd(gd[i-1][j],gd[i-1][j+(1<<i-1)]);
	}
}
inline int getgcd(int l,int r) {
	int k = log2(r-l+1);
	return gcd(gd[k][l],gd[k][r-(1<<k)+1]);
}
inline int getmin(int l,int r) {
	int k = log2(r-l+1);
	if(a[mn[k][l]] < a[mn[k][r-(1<<k)+1]]) return mn[k][l];
	return mn[k][r-(1<<k)+1];
}
LL solve(int l,int r) {
	if(l > r) return p;
	int mid = getmin(l,r);
	if(L[mid] < l && R[mid] > r) return 1ll * (r-l+2) * min(a[mid],p);
	if(L[mid] < l) return 1ll * (R[mid]-l+1) * min(a[mid],p) + solve(R[mid]+1,r);
	if(R[mid] > r) return 1ll * (r-L[mid]+1) * min(a[mid],p) + solve(l,L[mid]-1);
	return 1ll * (R[mid]-L[mid]) * min(a[mid],p) + solve(l,L[mid]-1) + solve(R[mid]+1,r);
}
int main() {
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--) {
		cin >> n >> p;
		fr(i,1,n) cin >> a[i];
		build();
		fr(i,1,n) {
			int l = 1,r = i;
			while(l < r) {
				int mid = l + r >> 1;
				if(getgcd(mid,i) == a[i]) r = mid;
				else l = mid+1;
			}
			L[i] = l;
			l = i,r = n;
			while(l < r) {
				int mid = l + r + 1 >> 1;
				if(getgcd(i,mid) == a[i]) l = mid;
				else r = mid-1;
			}
			R[i] = l;
		}
		printf("%lld\n",solve(1,n) - 2*p);
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