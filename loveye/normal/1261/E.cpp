#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1005;
int n,a[N],ans[N][N];
int vis[N],cnt;
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i,1,n) cin >> a[i];
	vis[1] = 1; vis[n+2] = 1;
	cnt = 1;
	fr(i,1,n) {
		fr(j,1,n) if(vis[j] && !vis[j+1]) {
			int l = j,r = j;
			while(!vis[r+1]) ++r;
			int rest = n+1-(r-l+1);
			if(rest >= a[i]) {
				fr(k,l,r-1) ans[k][i] = 0;
				ans[r][i] = 1; vis[r] = 1;
				int res = a[i]-1;
				fr(k,1,n+1) if(k < l || k > r) {
					if(res) --res,ans[k][i] = 1;
					else ans[k][i] = 0;
				}
			} else {
				int res = a[i];
				fr(k,1,n+1) if(k < l || k > r)
					--res,ans[k][i] = 1;
				fr(k,1,res) ans[l+k-1][i] = 1;
				vis[l+res] = 1;
				fr(k,res+1,r-l+1) ans[l+k-1][i] = 0;
			}
			break;
		}
	}
	cout << n+1 << endl;
	fr(i,1,n+1) {
		fr(j,1,n) cout << ans[i][j];
		cout << endl;
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