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

const int N = 1e5 + 5,M = 6*N;
int nn,n,S,T;
struct Point {
	int x,y,id;
} p[N];
bool cmpx(const Point &a,const Point &b) {
	return a.x < b.x;
}
bool cmpy(const Point &a,const Point &b) {
	return a.y < b.y;
}
int fir[N],to[M],wei[M],nxt[M],cnt;
void addedge(int u,int v,int w) {
	//cerr << u << ' ' << v << ' ' << w << endl;
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	wei[cnt] = w;
	fir[u] = cnt;
}
int sx,sy,tx,ty;
LL d[N];
struct Node {
	LL d; int id;
	bool operator < (const Node &o) const {
		return d > o.d;
	}
};
priority_queue<Node> pq;
void Dijkstra() {
	memset(d,0x3f,sizeof d);
	pq.push((Node){d[S] = 0,S});
	while(!pq.empty()) {
		Node now = pq.top(); pq.pop();
		if(now.d != d[now.id]) continue;
		int u = now.id;
		foredge(i,u,v) if(d[v] > d[u] + wei[i])
			pq.push((Node){d[v] = d[u] + wei[i],v});
	}
}
int main() {
	cin >> nn >> n;
	cin >> sx >> sy >> tx >> ty;
	fr(i,1,n) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p+1,p+n+1,cmpx);
	fo(i,1,n) {
		addedge(p[i].id,p[i+1].id,p[i+1].x-p[i].x);
		addedge(p[i+1].id,p[i].id,p[i+1].x-p[i].x);
	}
	sort(p+1,p+n+1,cmpy);
	fo(i,1,n) {
		addedge(p[i].id,p[i+1].id,p[i+1].y-p[i].y);
		addedge(p[i+1].id,p[i].id,p[i+1].y-p[i].y);
	}
	S = n+1,T = n+2;
	fr(i,1,n) addedge(S,p[i].id,min(abs(sx-p[i].x),abs(sy-p[i].y)));
	fr(i,1,n) addedge(p[i].id,T,abs(tx-p[i].x) + abs(ty-p[i].y));
	addedge(S,T,abs(sx-tx) + abs(sy-ty));
	Dijkstra();
	cout << d[T] << endl;
	return 0;
}