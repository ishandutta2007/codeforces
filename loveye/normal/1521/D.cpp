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
int n,du[N];
set<int> s[N];
I addedge(int u,int v) {
	s[u].insert(v);
}
struct Edge {
	int u,v;
} e[N];
typedef pair<int,int> pii;
#define mp make_pair
int ans;
vector<int> adj[N];
vector<pii> out;
int vis[N];
int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		fr(i,1,n) du[i] = 0,adj[i].clear(),vis[i] = 0,s[i].clear();
		for(int i = 1,u,v;i < n;++i) {
			cin >> u >> v;
			addedge(u,v),addedge(v,u);
			e[i].u = u; e[i].v = v;
		}
		queue<int> q;
		fr(i,1,n) if(s[i].size() == 1) q.push(i);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if(!s[u].size()) continue;
			if(adj[u].size() == 2) {
				for(set<int>::iterator it = s[u].begin();it != s[u].end();++it) {
					s[*it].erase(u);
					if(s[*it].size() == 1) q.push(*it);
				}
				s[u].clear();
				continue;
			}
			int v = *s[u].begin();
			if(adj[v].size() <= 1) {
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
			s[u].erase(v);
			s[v].erase(u);
			if(s[v].size() == 1) q.push(v);
		}
		out.clear();
		fr(i,1,n-1) {
			int u = e[i].u,v = e[i].v,ok = 0;
			fo(j,0,adj[u].size()) if(adj[u][j] == v) {
				ok = 1;break;
			}
			if(!ok) out.push_back(mp(u,v));
		}
		int last = -1;
		fr(i,1,n) if(adj[i].size() == 1 && !vis[i]) {
			int cur = adj[i][0],pre = i,res;
			vis[cur] = vis[pre] = 1;
			if(last != -1) out.push_back(mp(last,pre));
			while(adj[cur].size() != 1) {
				res = adj[cur][0] ^ adj[cur][1] ^ pre;
				pre = cur,cur = res;
				vis[cur] = 1;
			}
			last = cur;
		}
		fr(i,1,n) if(adj[i].size() == 0) {
			if(last != -1) out.push_back(mp(last,i));
			last = i;
		}
		cout << (ans = out.size() / 2) << endl;
		fo(i,0,ans) {
			cout << out[i].first << ' ' << out[i].second << ' ';
			cout << out[i+ans].first << ' ' << out[i+ans].second << endl;
		}
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