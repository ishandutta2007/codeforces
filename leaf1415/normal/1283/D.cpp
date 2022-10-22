#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define llint long long

using namespace std;

llint n, m;
llint a[200005];
vector<llint> ans;
map<llint, llint> mp;

void bfs()
{
	queue<llint> Q;
	for(int i = 1; i <= n; i++) Q.push(a[i]);
	
	while(ans.size() < m){
		llint x = Q.front();
		Q.pop();
		for(int i = -1; i <= 1; i+=2){
			llint y = x+i;
			if(mp.count(y)) continue;
			if(ans.size() >= m) continue;
			ans.push_back(y);
			mp[y] = mp[x] + 1;
			Q.push(y);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) mp[a[i]] = 0;
	
	bfs();
	
	llint sum = 0;
	for(int i = 0; i < ans.size(); i++) sum += mp[ans[i]];
	cout << sum << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}