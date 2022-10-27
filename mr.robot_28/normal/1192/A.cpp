#include<bits/stdc++.h>
using namespace std;
const int N = 1510000;
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int UF[N];
map <pair <int, int> , int> Map, Map2;
int n;
struct point{
	int x, y;
}P[N];
vector <int> E[N], G[N];
int Num[N], cnt;
set <pair <int, int> > Set;
void DFS(int a)
{
	Num[a] = ++cnt;
	for(int i = 0; i < E[a].size(); i++)
	{
		int x = E[a][i];
		if(!Num[x])
		{
			DFS(x);
		}
	}
}
int vis[N], blocked[N] ,pos[N], w[N][9];
int BN[N], ReNum[N], Q[N], head, tail;
int find(int a)
{
	if(a == UF[a]) return a;
	else return UF[a] = find(UF[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a != b)
	{
		UF[a] = b;
	}
}
priority_queue <int> PQ;
void BFS()
{
	while(head < tail)
	{
		int x = Q[++head];
		for(int i = 0; i < G[x].size(); i++){
			int t = G[x][i];
			if(vis[t])
			{
				continue;
			}
			if(!blocked[t])
			{
				Q[++tail] = t;
				vis[t] = 1;
			}
			else if(!pos[t])
			{
				pos[t] = 1;
				PQ.push(ReNum[t]);
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j, sub;
	cin >> n >> sub;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		P[i] = {x, y};
		Map[{x, y}] = i;
		Set.insert({x, y});
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			int tx = P[i].x + dx[j], ty = P[i].y + dy[j];
			Set.insert({tx, ty});
			if(Map.count({tx, ty}))
			{
				E[i].push_back(Map[{tx, ty}]);
			}
		}
	}
	DFS(1);
	if(cnt != n)
	{
		cout << "NO";
		return 0;
	}
	int c = 0;
	set <pair <int, int> > :: iterator it;
	for(it = Set.begin(); it != Set.end(); it++)
	{
		Map2[*it] = ++c;
	}
	for(it = Set.begin(); it != Set.end(); it++)
	{
		int a = Map2[*it];
		for(int j = 1; j < 8; j+=2)
		{
			int tx = it -> first + dx[j], ty = it -> second + dy[j];
			if(Map2.count({tx, ty}))
			{
				G[a].push_back(Map2[{tx, ty}]);
			} 
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			int tx = P[i].x + dx[j], ty = P[i].y + dy[j];
			w[i][j] = Map2[{tx, ty}];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		BN[i] = Map2[{P[i].x, P[i].y}];
		ReNum[BN[i]] = i;
		blocked[BN[i]] = 1;
	}
	for(int i = 1; i <= c; i++)
	{
		UF[i] = i;
	}
	for(int i = 1; i <= c; i++)
	{
		for(int j = 0; j < G[i].size(); j++)
		{
			int x = G[i][j];
			if(!blocked[x] && !blocked[i])
			{
				merge(i, x);
			}
		}
	}
	Q[++tail] = 1;
	vis[1] = 1;
	BFS();
	vector <int> Res;
	while(!PQ.empty())
	{
		int a = PQ.top();
		PQ.pop();
		int x = BN[a], ck = 0;
		if(!pos[x] || !blocked[x])
		{
			continue;
		}
		int pv = -1;
		for(int i = 0; i < 8; i++)
		{
			int t = w[a][i];
			if(blocked[t])
			{
				pv = i;
			}
		}
		if(pv != -1)
		{
			int TP[9], cc = 0;
			for(int i  = 0; i < 8; i++)
			{
				TP[i] = 0;
			}
			for(int i = 0; i < 8; i++)
			{
				int t = w[a][(pv + i) % 8];
				if(blocked[t])
				{
					cc++;
				}
				else TP[(pv + i) % 8] = cc;
			}
			for(int i = 1; i < 8; i += 2)
			{
				for(int j = i + 2; j < 8; j += 2)
				{
					int t1 = w[a][i], t2 = w[a][j];
					if(!blocked[t1] && !blocked[t2] && TP[i] != TP[j] && find(t1) == find(t2))
					{
						ck = 1;
					}
				}
			}
			if(ck)
			{
				continue;
			}
		}
		Res.push_back(a);
		blocked[x] =0;
		Q[++tail] = x;
		vis[x] = 1;
		BFS();
		for(int i = 0; i < G[x].size(); i++)
		{
			int z= G[x][i];
			if(!blocked[z])
			{
				merge(x, z);
			}
		}
		for(int i = 0; i < E[a].size(); i++)
		{
			int z = E[a][i];
			PQ.push(z);
		}
	}
	cout << "YES\n";
	for(int i = Res.size() - 1; i >= 0; i--)
	{
		cout << Res[i] << "\n";
	}
	return 0;
}