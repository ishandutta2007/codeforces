#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int l[N], cost[N];
int n;
set<int > gcds;
vector<pair<int, int> > v;
map<int, int> M;
int NWD(int a, int b)
{
	return b? NWD(b, a % b): a;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &l[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &cost[i]);
		v.clear();
		v.push_back({l[i], cost[i]});
		for(auto &w: gcds)
		{
			v.push_back({NWD(w, l[i]), M[w] + cost[i]});
		}		
		for(int j = 0; j < v.size(); j++)
		{
			if(!M.count(v[j].first))
			{
				M[v[j].first] = v[j].second;
				gcds.insert(v[j].first);
			}
			else
			{
				M[v[j].first] = min(M[v[j].first], v[j].second);
			}
		}		
	}
	if(!M.count(1))
	{
		printf("-1\n");
	}
	else
		printf("%d\n", M[1]);
	return 0;
}