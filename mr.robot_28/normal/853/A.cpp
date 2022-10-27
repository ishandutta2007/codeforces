#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector <int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	set <pair <int, int> > s;
	int j = k + 1;
	for(int i = 0; i < min(k + 1, n); i++)
	{
		s.insert({-c[i], i});
	}
	vector <int> ans(n);
	int timer = k + 1;
	int sum = 0;
	while(s.size() > 0)
	{
		int v = s.begin() -> second;
		ans[v] = timer;
		sum += (ans[v] - v - 1) * c[v];
		timer++;
		s.erase(s.begin());
		if(j < n)
		{
			s.insert({-c[j], j});
			j++;
		}
	}
	cout << sum << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}