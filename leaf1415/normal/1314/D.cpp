#include <iostream>
#include <map>
#include <utility>
#include <queue>
#include <algorithm>
#define llint long long
#define inf 1e9+7

using namespace std;
typedef pair<int, int> P;

llint n, m;
llint c[85][85];
vector<P> vec[85][85];
vector<int> used;

int dfs(int p)
{
	if(p == m-1){
		used.push_back(1);
		int sum = 0, cnt = 0;
		for(int i = 1; i < used.size(); i++){
			int u = used[i-1], v = used[i];
			for(int j = 0; j < vec[u][v].size(); j++){
				bool flag = true;
				for(int k = 0; k < used.size(); k++){
					if(vec[u][v][j].second == used[k]){
						flag = false;
						break;
					}
				}
				if(flag){
					sum += vec[u][v][j].first;
					cnt++;
					break;
				}
			}
		}
		used.pop_back();
		if(cnt < m) sum = inf;
		return sum;
	}
	
	int ret = inf;
	for(int i = 1; i <= n; i++){
		used.push_back(i);
		ret = min(ret, dfs(p+1));
		used.pop_back();
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	m /= 2;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(i == k || j == k) continue;
				vec[i][j].push_back(P(c[i][k] + c[k][j], k));
			}
			sort(vec[i][j].begin(), vec[i][j].end());
		}
	}
	used.push_back(1);
	cout << dfs(0) << endl;
	
	return 0;
}