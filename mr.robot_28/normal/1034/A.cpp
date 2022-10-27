#include<bits/stdc++.h>
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	bool flag = false;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t= a[0];
	for(int i = 0; i < n - 1; i++)
	{
		t = __gcd(t, a[i + 1]);
		if(a[i] != a[i + 1]){
			flag = true;
		}
	}
	if(!flag)
	{
		cout << -1;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		a[i] /= t;
	}
	vector <int> p(1e7 * 1.5 + 1, -1);
	for(int i = 2; i <= 1e7 * 1.5; i++)
	{
		if(p[i] == -1)
		{
			int j = i;
			while(j <= 1e7 * 1.5)
			{
				p[j] = i;
				j += i;
			}
		}
	}
	vector <int> cnt;
	for(int i = 0; i < n; i++)
	{
		int e = a[i];
		while(e != 1)
		{
			int t = p[e];
			int c = 0;
			while(e % t == 0)
			{
				c++;
				e = e / t;
			}
			if(c != 0){
				cnt.push_back(t);
			}
		}
	}
	int ans = 0;
	sort(cnt.begin(), cnt.end());
	for(int i = 0; i < cnt.size(); i++)
	{
		int j = i;
		while(j < cnt.size() && cnt[j] == cnt[i])
		{
			j++;
		}
		ans = max(ans, j - i);
		i = j - 1;
	}
	cout << n - ans;
    return 0;
}