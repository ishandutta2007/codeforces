#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define MP make_pair
using namespace std;
const int maxn = 100000 + 10;
const int MOD = 1000000009;
const int dx[] = {-1, 0, 1};
int x[maxn], y[maxn];
map<pair<int, int>, int> ID;
set<int> Set;
bool vis[maxn];

bool available(int t)
{
	for(int i = 0; i < 3; i ++)
	{
		int nx = x[t] + dx[i];
		int ny = y[t] + 1;
		int id = ID[MP(nx, ny)];
		if(id && ! vis[id])
		{
			int cnt = 0;
			for(int j = 0; j < 3; j ++)
			{
				int nnx = nx + dx[j];
				int nny = y[t];
				int nid = ID[MP(nnx, nny)];
				if(nid && !vis[nid]) cnt ++;
			}
			if(cnt == 1) return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d%d",&x[i],&y[i]);
		ID[MP(x[i], y[i])] = i;
	}
	for(int i = 1; i <= n; i ++)
		if(available(i))
			Set.insert(i);
	ll ans = 0;
	bool turn = false;
	while(Set.size())
	{
		int t = turn ? *Set.begin() : *Set.rbegin();
		Set.erase(t);
		if(!available(t)) continue;
		turn = !turn;
		vis[t] = true;
		ans = (ans * n + t - 1) % MOD;
		for(int i = 0; i < 3; i ++)
		{
			int nx = x[t] + dx[i];
			int ny = y[t] - 1;
			int id = ID[MP(nx, ny)];
			if(id && !vis[id] && available(id))
                Set.insert(id);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}