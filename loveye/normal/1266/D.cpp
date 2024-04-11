#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
#define fi first
#define se second
#define mp make_pair

const int N = 1e5 + 5,M = 3e5 + 5;
int n,m,a[N],id[N];
vector<pair<pair<int,int>,int> > ans;
signed main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fr(i,1,n) id[i] = i;
	for(int i = 1,u,v,w;i <= m;++i) {
		cin >> u >> v >> w;
		a[u] += w; a[v] -= w;
	}
	sort(id+1,id+n+1,[](const int &i,const int &j) {
		return a[i] > a[j];
	});
	int l = 1,r = n;
	while(l < r) {
		while(l < r && a[id[l]] == 0) ++l;
		while(l < r && a[id[r]] == 0) --r;
		if(l < r) {
			int d = min(a[id[l]],-a[id[r]]);
			a[id[l]] -= d,a[id[r]] += d;
			ans.push_back(mp(mp(id[l],id[r]),d));
		}
	}
	cout << ans.size() << endl;
	for(auto p : ans) cout << p.fi.fi << ' ' << p.fi.se << ' ' << p.se << endl;
	return 0;
}//

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}