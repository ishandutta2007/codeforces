#include<iostream>
#include<vector>
#include<queue>

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

using namespace std;
vector<pair<int,int> >G[2<<17];
int N,M;
int X[2<<17],dir[2<<17];
bool dfs(int u)
{
	for(pair<int,int>e:G[u])
	{
		int v=e.first;
		if(dir[v]==0)
		{
			dir[v]=3-dir[u];
			if(!dfs(v))return false;
		}
		else if(dir[v]==dir[u])return false;
	}
	return true;
}
vector<int>DAG[2<<17];
int deg[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	atcoder::dsu uf(N);
	for(int i=0;i<M;i++)
	{
		int t,u,v;
		cin>>t>>u>>v;
		u--,v--;
		G[u].push_back(make_pair(v,t));
		G[v].push_back(make_pair(u,t));
		uf.merge(u,v);
	}
	int pos=0;
	for(vector<int>vs:uf.groups())
	{
		int root=vs[0];
		dir[root]=1;
		if(!dfs(root))
		{
			cout<<"NO\n";
			return 0;
		}
		for(int v:vs)
		{
			for(pair<int,int>e:G[v])
			{
				int w=e.first;
				if(dir[v]==1)
				{
					if(e.second==1)DAG[w].push_back(v),deg[v]++;
					else DAG[v].push_back(w),deg[w]++;
				}
				else
				{
					if(e.second==1)DAG[v].push_back(w),deg[w]++;
					else DAG[w].push_back(v),deg[v]++;
				}
			}
		}
		queue<int>P;
		int cnt=0;
		for(int v:vs)if(!deg[v])P.push(v);
		while(!P.empty())
		{
			int u=P.front();P.pop();
			X[u]=pos++;
			cnt++;
			for(int v:DAG[u])if(!--deg[v])P.push(v);
		}
		if(cnt<vs.size())
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=0;i<N;i++)cout<<(dir[i]==1?"R ":"L ")<<X[i]<<"\n";
}