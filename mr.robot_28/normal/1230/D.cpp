#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;
vector <vector <int> > g;
vector <int> A, cnt, sum;
vector <bool> used;
void dfs(int v)
{
	used[v] = true;
	ans += sum[v];
	for(int i = 0; i < g[v].size(); i++)
	{
		if(!used[g[v][i]])
		{
			dfs(g[v][i]);
		}
	}
}
signed main() {
	int n;
	cin >> n;
	vector <pair <int, int> > B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> B[i].first;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i].second;
	}
	sort(B.begin(), B.end());
	for(int i = 0; i < n; ++i)
	{
		int as = B[i].second;
		int j = i + 1;
		while(j < n && B[j].first == B[i].first)
		{
			as += B[j].second;
			j++;
		}
		j--;
		cnt.push_back(j - i + 1);
		sum.push_back(as);
		A.push_back(B[i].first);
		i = j;
	}
	g.resize(A.size());
	for(int i = A.size() - 1; i >= 0; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			int k = A[i] | A[j];
			if(k == A[i])
			{
				g[i].push_back(j);
			}
		}
	}
	used.resize(A.size(), false);
	for(int i = A.size() - 1; i >= 0; i--)
	{
		if(cnt[i] >= 2 && !used[i])
		{
			dfs(i);
		}
	}
	cout << ans;
    return 0;
}