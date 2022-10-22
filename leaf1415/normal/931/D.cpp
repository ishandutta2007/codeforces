#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> G[100005];
int cnt[100005];

void dfs(int v, int depth)
{
	cnt[depth]++;
	for(int i = 0; i < G[v].size(); i++){
		dfs(G[v][i], depth+1);
	}
}

int main(void)
{
	cin >> n;
	int p;
	for(int i = 2; i <= n; i++){
		cin >> p;
		G[p].push_back(i);
	}
	
	dfs(1, 0);
	int ans = 0;
	for(int i = 0; i < 100005; i++){
		ans += cnt[i] % 2;
	}
	cout << ans << endl;
	return 0;
}