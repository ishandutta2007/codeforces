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

const int N = 2e5 + 5;
int n;
int fir[N],to[N],nxt[N],eds,du[N];
void addedge(int u,int v) {
	to[++eds] = v;
	nxt[eds] = fir[u];
	fir[u] = eds;
	++du[v];
	//cerr << u << ' ' << v << endl;
}
int q[N],h,t,dp[N];
int main() {
	int T; cin >> T;
	while(T--) {
		cin >> n;
		fr(i,1,n) {
			int k,v; cin >> k;
			fo(j,0,k) cin >> v,addedge(v,i);
		}
		h = 1,t = 0;
		fr(i,1,n) {
			if(!du[i]) q[++t] = i;
			dp[i] = 1;
		}
		while(h <= t) {
			int u = q[h++];
			//cerr << u << endl;
			foredge(i,u,v) {
				dp[v] = max(dp[v],dp[u] + (u > v));
				if(--du[v] == 0) q[++t] = v;
			}
		}
		int ans = *max_element(dp+1,dp+n+1);
		fr(i,1,n) if(du[i]) ans = -1;
		cout << ans << endl;
		eds = 0; fr(i,1,n) fir[i] = 0,du[i] = 0;
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