#include<bits/stdc++.h>
 
using namespace std;
#define int long long
int const1;
int n;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
int count_diff(vector <int> a, int delta)
{
	int counter = 0;
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = -delta; j <= delta; j += delta)
		{
			int to = a[i] + j;
			if(to < 0)
			{
				to += const1;
			}
			if(to >= const1)
			{
				to -= const1;
			}
			if(to > a[i])
			{
				int it = lower_bound(a.begin(), a.end(), to) - a.begin();
				if(it != a.size() && a[it] == to)
				{
					counter++;
				}
			}
		}
	}
	return counter;
}
pair <int, int> is_good(vector <int> a, int d)
{
	int n = a.size();
	int cnt = 0;
	int y = a[0];
	vector <int> :: iterator it;
	it = lower_bound(a.begin(), a.end(), y);
	while(it != a.end() && *it == y)
	{
		cnt++;
		y += d;
		if(y >= const1)
		{
			y -= const1;
		}
		it = lower_bound(a.begin(), a.end(), y);
	}
	y = a[0];
	it = lower_bound(a.begin(), a.end(), y);
	while(it != a.end() && *it == y)
	{
		cnt++;
		y -= d;
		if(y < 0)
		{
			y += const1;
		}
		it = lower_bound(a.begin(), a.end(), y);
	}
	return {cnt == n + 1,(d + y) % const1};
}
pair <int, int> solve(vector <int> a)
{
	if(a.size() == 0)
	{
		return {1, 1};
	}
	if(a.size() == 1)
	{
		return {a[0], 1};
	}
	int diff = a[1] - a[0];
	int k = n - count_diff(a, diff);
	int d = power(k, const1 - 2) * diff % const1;
	pair <int, int> t = is_good(a, d);
	if(t.first)
	{
		return {t.second, d};
	}
	else
	{
		return {-1, -1};
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> const1 >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	pair <int, int> ans = {-1, -1};
	if(n * 2 >= const1)
	{
		vector <int> c;
		for(int i = 0; i < const1; i++)
		{
			vector <int> :: iterator it;
			it = lower_bound(a.begin(), a.end(), i);
			if(it == a.end() || *it != i)
			{
				c.push_back(i);
			}
		}
		n = const1 - n;
		ans = solve(c);
		if(ans.first != -1)
		{
			ans.first = (ans.first + n * ans.second) % const1;
		}
	}
	else
	{
		ans = solve(a);
	}
	if(ans.first == -1)
	{
		cout << -1;
	}
	else
	{
		cout << ans.first << " " << ans.second;
	}
	return 0;
}