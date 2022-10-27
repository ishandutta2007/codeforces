#include <bits/stdc++.h>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int f1 = 0, f2 = -1;
		set <pair <long long, long long> > st;
		long long s1 = 0;
		int sign = 1;
		for(int i = 0; i < n; i++)
		{
			int x = a[i];
			if(f2 != -1)
			{
				f1 += 2;
				sign = 1;
				s1 = 0;
				st.clear();
				if(f2 < x)
				{
					st.insert({x - f2, x - f2});
				}
			}
			else if(st.size() != 0)
			{
		//		cout << i << "\n";
				f1++;
				if(sign == -1)
				{
					long long t = s1 - x;
					while(st.size() != 0 && st.begin() -> second <= t)
					{
						st.erase(st.begin());
					}
					if(st.size() != 0 && st.begin() -> first <= t)
					{
						pair <long long, long long> v = {t + 1, st.begin() -> second};
						st.erase(st.begin());
						st.insert(v);
					}
				}
				else
				{
					long long t = x - s1;
					while(st.size() != 0 && st.rbegin() -> first >= t)
					{
						st.erase(*st.rbegin());
					}
					if(st.size() != 0 && st.rbegin() -> second >= t)
					{
						pair <long long, long long> v = {st.rbegin() -> first, t - 1};
						st.erase(*st.rbegin());
						st.insert(v);
					}
				}
				s1 = x - s1;
				sign *= -1;
			}
			else
			{
				sign = -1;
				s1 = x;
				long long t = x - 1;
				if(i != 0)
				{
				 t = min(a[i - 1] - 1, x - 1);
				}
				else
				{
					t = -1;
				}
				if(1 <= t)
				{
					st.insert({1, t});
				}
			}
			f2 = -1;
			if(x % 2 == 0)
			{
				x /= 2;
				long long f = (x - s1) / sign;
				set <pair <long long, long long> > :: iterator it;
				it = st.lower_bound({f + 1, -1e18});
				bool flag = 0;
				if(it != st.begin())
				{
					it--;
					if(it -> first <= f && f <= it -> second)
					{
						flag = 1;
					}
				}
				if(flag)
				{
					f2 = x;
				}
				else
				{
					st.insert({f, f});
				}
			}
		}
		int ans;
		if(f2 != -1)
		{
			ans = f1 + 2;
		}
		else if(st.size() != 0)
		{
			ans = f1 + 1;
		}
		else
		{
			ans = f1;
		}
		cout << 2 * n - ans << "\n";
	}
	return 0;
}