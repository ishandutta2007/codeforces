#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;

vector<pair<int , int> > mx[maxn];

int par[maxn] , ans[maxn] , dp[maxn];

inline void ok(int v , int u)
{
	mx[v].pb({dp[u] , u});

	sort(mx[v].begin() , mx[v].end());
	reverse(mx[v].begin() , mx[v].end());

	while(2 < (int)mx[v].size())
		mx[v].pop_back();
}

inline void crawl(int p , int v)
{
	if(p == -1)
		return;

	int tmp = dp[p];

	ok(p , v);
	for(int i = 0; i < (int)mx[p].size(); i++)
		dp[p] = max(dp[p] , mx[p][i].first + i);

	if(tmp != dp[p])
		crawl(par[p] , p);
}

int main()
{
	par[0] = -1;
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &par[i]);
		par[i]--;
		dp[i] = 1;

		crawl(par[i] , i);

		ans[i] = mx[0][0].first;
	}

	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	cout << endl;

}