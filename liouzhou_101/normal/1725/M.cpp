#include <cstring>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#define ll long long
#define maxn 402000
using namespace std;

#include <cassert>
#include <vector>
#include <utility>

	template<typename CostType>
	class ShortestPath
	{
	private:
		int n;
		std::vector<std::vector<std::pair<int, CostType>>> edge;
	public:
		explicit ShortestPath(int n) : n(n), edge(n)
		{
			assert(n >= 1);
		}
		void AddEdge(int from, int to, CostType cost)
		{
			//printf("tjb : %d %d %d\n",n,from,to);
			assert(0 <= from && from < n && 0 <= to && to < n && cost >= 0);
			edge[from].push_back({ to, cost });
		}
		// Return an array d of length n such that for every vertex x,
		// d[x] is the shortest path from source to x.
		// If no path from source to x, then d[x] = -1.
		std::vector<CostType> Solve(int source)
		{
			assert(0 <= source && source < n);
			std::vector<int> heap(n * 2);
			std::vector<int> pos(n);
			std::vector<CostType> dis(n, -1);
			int size = 0;

			auto min = [&](int x, int y)
			{
				return dis[x] < dis[y] ? x : y;
			};
			auto set = [&](int id, int x)
			{
				heap[id] = x;
				pos[x] = id;
			};
			auto update = [&](int id)
			{
				int x = heap[id];
				CostType d = dis[x];
				for (id >>= 1; id && dis[heap[id]] >= d; id >>= 1)
					heap[id] = x;
			};
			auto push = [&](int x)
			{
				set(size * 2 + 1, x);
				if (size)
				{
					set(size * 2, heap[size]);
					update(size * 2 + 1);
				}
				size += 1;
			};
			auto pop = [&]()
			{
				size -= 1;
				if (size)
				{
					int id = pos[heap[1]];
					if ((id >> 1) == size)
					{
						set(size, heap[id ^ 1]);
						id = size;
					}
					else
					{
						set(id, heap[size] == heap[size * 2] ? heap[size * 2 + 1] : heap[size * 2]);
						pos[heap[size]] = size;
					}
					for (int tmp; id != 1; heap[id >>= 1] = tmp)
						tmp = min(heap[id], heap[id ^ 1]);
				}
			};
			auto top = [&]()
			{
				return heap[1];
			};
			auto decrease = [&](int x)
			{
				update(pos[x]);
			};

			dis[source] = 0;
			push(source);
			while (size)
			{
				int x = top();
				pop();
				CostType d = dis[x];
				for (const auto& [y, w] : edge[x])
				{
					if (!pos[y])
					{
						dis[y] = d + w;
						push(y);
					}
					else if (dis[y] > d + w)
					{
						dis[y] = d + w;
						decrease(y);
					}
				}
			}
			return dis;
		}
	};


priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> taken;
int n,m;
int fir[maxn], en[maxn*2], nex[maxn*2], opt[maxn*2];
ll	dis[maxn];
int dl[maxn*2];
bool view[maxn];
int len[maxn*2];
int tot;
void tjb(int x,int y,int r){
	en[++tot] = y;
	len[tot] = r;
	nex[tot]=fir[x];
	fir[x]=tot;

}

int main()
{
	tot = 0;
	scanf("%d%d",&n,&m);
	
	ShortestPath<long long> ans(2*n+2);
	for(int i=1;i<=n;++i){
		dis[i] = -1;
		view[i] = false;
		fir[i] = 0;
	//	ans.a
		ans.AddEdge(i,i+n,0);
	//	tjb(i,i+n,0);
	}
	dis[1] = 0;
	for(int i=1;i<=m;++i){
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		ans.AddEdge(x,y,r);
		ans.AddEdge(y+n,x+n,r);
	}
	vector<long long>ret = ans.Solve(1);
	for(int i=2;i<=n;++i){
		printf("%lld", ret[i+n]);
		if(i==n)printf("\n"); else printf(" ");
	}
	return 0;
}