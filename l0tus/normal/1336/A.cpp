#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> ppi;
const int MN = 2e5+5;

vector<int> G[MN];
priority_queue<pii> PQ;
int p[MN],d[MN],sz[MN],I[MN];
ll ans;

void dfs(int s, int r)
{
	sz[s] = 1;
	for(int e:G[s]){
		if(e==r) continue;
		p[e] = s;
		d[e] = d[s]+1;
		dfs(e,s);
		sz[s] += sz[e];
	}
	if(s!=1&&I[s]==1) PQ.emplace(d[s],s);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,K;
    cin >> N >> K;
    int u,v;
    for(int i=1; i<N; i++){
    	cin >> u >> v;
    	G[u].push_back(v);
    	G[v].push_back(u);
    	I[u]++;
    	I[v]++;
    }
    dfs(1,1);
    int x,s,e;
    //cout << PQ.size();
    for(int i=1; i<=K; i++){
    	tie(x,s) = PQ.top();
    	PQ.pop();
    	ans += x;
    	e = p[s];
    	I[e]--;
    	if(e!=1&&I[e]==1) PQ.emplace(d[e]-sz[e]+1,e);
    }
    cout << ans;
}