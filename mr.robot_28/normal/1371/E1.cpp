#include<bits/stdc++.h>
 
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int pr, n;
	cin >> n >> pr;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <int> p(n + 1, -1);
	for(int i = 2; i <= n; i++)
	{
		if(p[i] == -1)
		{
			int j = i * 2;
			while(j <= n)
			{
				p[j] = i;
				j += i;
			}
		}
	}
	vector <int> ans;
	vector <int> cnt(n + 1), cnt1(n + 1);
	for(int x = 0; x < 2000; x++)
	{
		bool flag = true;
		for(int j = 1; j <= n; j++)
		{
			cnt[j] = 0;
			cnt1[j - 1] = 0;
		}
		for(int j = 0; j < n; j++){
			if(a[j] - x > n - 1)
			{
				flag = false;
			}
			cnt1[min(n - 1, max(0, a[j] - x))]++;
		}
		if(!flag)
		{
			continue;
		}
		int c = 0;
		for(int j = 0; j < n; j++)
		{
			c += cnt1[j];
			if(c == 0)
			{
				flag = false;
				break;
			}
			cnt[c]++;
			c--;
		}
		if(!flag)
		{
			continue;
		}
		for(int j = n; j >= 1; j--){
			if(p[j] != -1)
			{
				cnt[j / p[j]] += cnt[j];
				cnt[p[j]] += cnt[j];
			}
		}
		if(cnt[pr] == 0)
		{
			ans.push_back(x);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
    return 0;
}