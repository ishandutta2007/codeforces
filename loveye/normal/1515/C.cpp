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
int n,a[N],m,x,h[N],ans[N];
struct Node {
	int id,s;
	inline bool operator < (const Node &o) const {
		return s > o.s;
	}
};
priority_queue<Node> pq;
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m >> x;
		while(!pq.empty()) pq.pop();
		fr(i,1,m) pq.push((Node){i,0});
		fr(i,1,n) {
			cin >> h[i];
			Node now = pq.top(); pq.pop();
			now.s += h[i];
			ans[i] = now.id;
			pq.push(now);
		}
		cout << "YES" << endl;
		fr(i,1,n) cout << ans[i] << ' ';
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