#include <bits/stdc++.h>
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector <vector <int> > cnt(k, vector <int> (26, 0));
		for(int i = 0; i < n / 2; i++)
		{
			cnt[i % k][s[i] - 'a']++;
		}
		for(int j = n - 1; j >= n / 2; j--)
		{
			cnt[j % k][s[j] - 'a']++;
		}
		int ans = 0;
		for(int i = 0; i < k / 2; i++)
		{
			int ma = 0;
			int sum = 0;
			for(int j = 0; j < 26; j++)
			{
				ma = max(ma, cnt[i][j] + cnt[k - 1 - i][j]);
				sum += cnt[i][j] + cnt[k - 1 - i][j];
			}
			ans += sum - ma;
		}
		if(k % 2 == 1)
		{
			int ma = 0;
			int sum = 0;
			for(int j = 0; j < 26; j++)
			{
				ma = max(ma, cnt[k / 2][j]);
				sum += cnt[k / 2][j];
			}
			ans += sum - ma;
		}
		cout << ans << "\n";
	}
    return 0;
}