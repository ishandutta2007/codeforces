#include<bits/stdc++.h>
using namespace std;

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

const int N = 5005;
int n,cur;
LL x[N],y[N];
vector<int> ans;
bool vis[N];
inline LL dis(int i,int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	cin >> n; cur = rand() % n + 1;
	fr(i,1,n) cin >> x[i] >> y[i];
	ans.push_back(cur);
	fo(i,1,n) {
		vis[cur] = 1;
		int nxt = cur;
		fr(j,1,n) if(!vis[j] && dis(cur,j) > dis(cur,nxt))
			nxt = j;
		cur = nxt;
		ans.push_back(cur);
	}
	if(ans.size() < n) cout << -1 << endl;
	else fo(i,0,n) cout << ans[i] << ' ';
	return 0;
}