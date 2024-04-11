#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n, m;
vector<llint> vec[5005];
llint cnt[5005], far[5005];

llint dist(llint s, llint t)
{
	return ((t-1) - (s-1) + n) % n;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int a, b;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		vec[a].push_back(b);
	}
	
	for(int i = 1; i <= n; i++){
		cnt[i] = vec[i].size();
		llint mn = n+1;
		for(int j = 0; j < vec[i].size(); j++){
			llint d = dist(i, vec[i][j]);
			mn = min(mn, d);
		}
		far[i] = mn;
		if(cnt[i] == 0) far[i] = 0;
	}
	
	//for(int i = 1; i <= n; i++) cout << cnt[i] << " " << far[i] << endl;
	
	for(int i = 1; i <= n; i++){
		llint ans = 0;
		for(int j = 1; j <= n; j++){
			ans = max(ans, dist(i, j) + (cnt[j]-1)*n + far[j]);
		}
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}