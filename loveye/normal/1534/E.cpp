#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 505,M = N * N;
int n,k,c[N],id[N];
int fr[N],d[N];
int G[N][N];
bool cmp(const int &i,const int &j) {return c[i] < c[j];}
vector<int> vv;
signed main() {
	cin >> n >> k;
	fr(i,0,n) fr(j,0,n) if(~(k - (j-i)) & 1) {
		int a = (k - (j-i)) / 2;
		int b = k - a;
		if(a <= i && b <= n-i && a >= 0 && b >= 0)
			G[i][j] = 1;
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		fr(v,1,n) if(G[u][v] && !d[v]) {
			fr[v] = u;
			d[v] = d[u] + 1,q.push(v);
		}
	}
	if(!d[n]) return cout << -1 << endl,0;
	int cur = n;
	while(cur) vv.push_back(cur),cur = fr[cur];
	vv.push_back(0);
	fr(i,1,n) id[i] = i;
	int ans = 0,x;
	while(vv.size() > 1) {
		int u = vv.back(); vv.pop_back();
		int v = vv.back();
		int a = (k - (v-u)) / 2;
		int b = k - a;
		//cerr << u << ' ' << v << endl;
		//cerr << a << ' ' << b << endl;
		cout << "? ";
		fr(i,1,b) c[id[i]] = 1,cout << id[i] << ' ';
		fr(i,1,a) c[id[n+1-i]] = 0,cout << id[n+1-i] << ' ';
		cout << endl;
		cin >> x; ans ^= x;
		sort(id+1,id+n+1,cmp);
	}
	cout << "! " << ans << endl;
	return 0;
}