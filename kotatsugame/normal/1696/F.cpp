#include<iostream>
#include<vector>
#include<algorithm>
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
int T,N;
int ID[100][100];
vector<vector<int> >Gs[100];
string S[100][100];
vector<int>G[100];
bool vis[100];
vector<vector<int> >depth;
void dfs(int u,int p,int d)
{
	if(d==depth.size())depth.emplace_back();
	depth[d].push_back(u);
	for(int v:G[u])if(v!=p)dfs(v,u,d+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<N;i++)
		{
			for(int j=1;j<=N-i;j++)cin>>S[i-1][i+j-1];
		}
		bool out=false;
		for(int k=0;k<N;k++)
		{
			atcoder::dsu uf(N);
			for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)if(S[i][j][k]=='1')uf.merge(i,j);
			Gs[k]=uf.groups();
			for(int i=0;i<Gs[k].size();i++)sort(Gs[k][i].begin(),Gs[k][i].end());
			sort(Gs[k].begin(),Gs[k].end());
			for(int i=0;i<Gs[k].size();i++)
			{
				for(int ui=0;ui<Gs[k][i].size();ui++)
				{
					int u=Gs[k][i][ui];
					ID[k][u]=i;
					for(int vi=ui+1;vi<Gs[k][i].size();vi++)
					{
						int v=Gs[k][i][vi];
						if(S[u][v][k]=='0')out=true;
					}
				}
			}
		}
		if(out)
		{
			cout<<"No\n";
			continue;
		}
		bool fn=false;
		for(int id0=0;id0<Gs[0].size();id0++)if(ID[0][0]!=id0)
		{
			for(int j=0;j<N;j++)
			{
				G[j].clear();
				vis[j]=false;
			}
			vis[0]=true;
			queue<pair<int,int> >Q;
			bool ok=true;
			for(int u:Gs[0][id0])
			{
				if(vis[u])
				{
					ok=false;
					break;
				}
				vis[u]=true;
				Q.push(make_pair(u,0));
			}
			while(!Q.empty()&&ok)
			{
				int u=Q.front().first,p=Q.front().second;
				G[p].push_back(u);
				G[u].push_back(p);
				Q.pop();
				int id=ID[u][p];
				for(int v:Gs[u][id])
				{
					if(!vis[v])
					{
						vis[v]=true;
						Q.push(make_pair(v,u));
					}
					else if(v!=p)
					{
						ok=false;
						break;
					}
				}
			}
			for(int i=0;ok&&i<N;i++)if(!vis[i])ok=false;
			for(int st=0;ok&&st<N;st++)
			{
				depth.clear();
				dfs(st,-1,0);
				for(int i=0;i<depth.size();i++)sort(depth[i].begin(),depth[i].end());
				sort(depth.begin(),depth.end());
				if(Gs[st]!=depth)ok=false;
			}
			if(ok)
			{
				cout<<"Yes\n";
				for(int u=0;u<N;u++)for(int v:G[u])if(u<v)cout<<u+1<<" "<<v+1<<"\n";
				fn=true;
				break;
			}
		}
		if(!fn)cout<<"No\n";
	}
}