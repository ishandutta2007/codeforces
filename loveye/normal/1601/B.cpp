#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3e5 + 5,NN = N * 5,M = N * 19;
int n,a[N],b[N],isleaf[NN];
int fir[NN],to[M],nxt[M],eds,wei[M];
void addedge(int u,int v,int w) {
	//cout << u << ' ' << v << ' ' << w << endl;
	to[++eds] = v;
	wei[eds] = w;
	nxt[eds] = fir[u];
	fir[u] = eds;
}
void change(int k,int l,int r,int x,int y,int v) {
	if(x <= l && r <= y) {
		addedge(4*n + v,k,1);
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) change(k << 1,l,mid,x,y,v);
	if(y > mid) change(k << 1 | 1,mid+1,r,x,y,v);
}
void build(int k,int l,int r) {
	if(l == r) {
		isleaf[k] = l;
		addedge(k,4*n + l + b[l],0);
		return;
	}
	int mid = l + r >> 1;
	addedge(k,k << 1,0);
	addedge(k,k << 1 | 1,0);
	build(k << 1,l,mid);
	build(k << 1 | 1,mid+1,r);
}
int d[NN],from[NN];
void bfs() {
	deque<int> q;
	memset(d,0x3f,sizeof d);
	q.push_back(4*n + n);
	d[4*n + n] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop_front();
		foredge(i,u,v) if(d[v] > d[u] + wei[i]) {
			from[v] = u;
			d[v] = d[u] + wei[i];
			if(wei[i]) q.push_back(v);
			else q.push_front(v);
		}
	}
}
vector<int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	fr(i,1,n) cin >> a[i];
	fr(i,1,n) cin >> b[i];
	fr(i,1,n) change(1,0,n,i-a[i],i,i);
	memset(isleaf,-1,sizeof isleaf);
	build(1,0,n);
	bfs();
	if(d[4*n] > 1e9) return cout << -1 << endl,0;
	cout << d[4*n] << endl;
	int cur = 4*n;
	while(cur && cur != 4*n + n) {
		ans.push_back(cur);
		cur = from[cur];
	}
	//for(auto x : ans) cout << x << ' ';
	//cout << endl;
	rf(i,ans.size()-1,0) if(isleaf[ans[i]] != -1)
		cout << isleaf[ans[i]] << ' ';
	cout << endl;
	return 0;
}