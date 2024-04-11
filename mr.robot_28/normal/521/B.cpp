#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 9;
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	vector <pair <int, int> > a(m);
	set <pair <pair <int, int>, int> > w1;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
		w1.insert({{x, y}, i});
	}
	vector <int> p(m);
	vector <int> q(m, 0);
	for(int i = 0; i < m; i++)
	{
		set <pair <pair <int, int>, int> > :: iterator it;
		it = w1.lower_bound({{a[i].first - 1, a[i].second - 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[i].first - 1, a[i].second - 1))
		{
			p[i]++;
		}
		it = w1.lower_bound({{a[i].first, a[i].second - 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[i].first, a[i].second - 1))
		{
			p[i]++;
		}
		it = w1.lower_bound({{a[i].first + 1, a[i].second - 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[i].first + 1, a[i].second - 1))
		{
			p[i]++;
		}
	}
	for(int i = 0; i < m; i++)
	{
		set <pair <pair <int, int>, int> > :: iterator it;
		it = w1.lower_bound({{a[i].first - 1, a[i].second + 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[i].first - 1, a[i].second + 1))
		{
			if(p[it -> second] == 1)
			{
				q[i]++;
			}
		}
		it = w1.lower_bound({{a[i].first, a[i].second + 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[i].first, a[i].second + 1))
		{
			if(p[it -> second] == 1)
			{
				q[i]++;
			}
		}
		it = w1.lower_bound({{a[i].first + 1, a[i].second + 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[i].first + 1, a[i].second + 1))
		{
			if(p[it -> second] == 1)
			{
				q[i]++;
			}
		}
	}
	set <int> s;
	vector <bool> used(m);
	for(int i = 0; i < m; i++)
	{
		if(!q[i])
		{
			s.insert(i);
		}
	}
	int c = 0;
	int ans = 0;
	while(s.size() > 0)
	{
		int v, v1;
		if(c % 2 == 0)
		{
			v = *s.rbegin();
			s.erase(*s.rbegin());
		}
		else
		{
			v = *s.begin();
			s.erase(v);
		}
		used[v] = 1;
		ans = (1LL * ans * m + v) % mod;
		c++;
		if(p[v] == 1)
		{
			set <pair <pair <int, int>, int> > :: iterator it;
			it = w1.lower_bound({{a[v].first - 1, a[v].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v].first - 1, a[v].second - 1))
			{
				q[it -> second]--;
				if(q[it -> second] == 0 && !used[it -> second])
				{
					s.insert(it -> second);
				}
			}
			it = w1.lower_bound({{a[v].first, a[v].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v].first, a[v].second - 1))
			{
				q[it -> second]--;
				if(q[it -> second] == 0 && !used[it -> second])
				{
					s.insert(it -> second);
				}
			}
			it = w1.lower_bound({{a[v].first + 1, a[v].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v].first + 1, a[v].second - 1))
			{
				q[it -> second]--;
				if(q[it -> second] == 0 && !used[it -> second])
				{
					s.insert(it -> second);
				}
			}
		}
		p[v] = 0;
		set <pair <pair <int, int>, int> > :: iterator it;
		it = w1.lower_bound({{a[v].first - 1, a[v].second + 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[v].first - 1, a[v].second + 1) && !used[it -> second])
		{
			p[it -> second]--;
			if(p[it -> second] == 1)
			{
				v1 = it -> second;
				it = w1.lower_bound({{a[v1].first - 1, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first - 1, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			it = w1.lower_bound({{a[v1].first, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			it = w1.lower_bound({{a[v1].first + 1, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first + 1, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			}
		}
		it = w1.lower_bound({{a[v].first, a[v].second + 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[v].first, a[v].second + 1) && !used[it -> second])
		{
			p[it -> second]--;
			if(p[it -> second] == 1)
			{
				v1 = it -> second;
				it = w1.lower_bound({{a[v1].first - 1, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first - 1, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			it = w1.lower_bound({{a[v1].first, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			it = w1.lower_bound({{a[v1].first + 1, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first + 1, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			}
		}
		it = w1.lower_bound({{a[v].first + 1, a[v].second + 1}, 0});
		if(it != w1.end() && it -> first == make_pair(a[v].first + 1, a[v].second + 1) && !used[it -> second])
		{
			p[it -> second]--;
			if(p[it -> second] == 1)
			{
				v1 = it -> second;
				it = w1.lower_bound({{a[v1].first - 1, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first - 1, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			it = w1.lower_bound({{a[v1].first, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			it = w1.lower_bound({{a[v1].first + 1, a[v1].second - 1}, 0});
			if(it != w1.end() && it -> first == make_pair(a[v1].first + 1, a[v1].second - 1) && !used[it -> second])
			{
				q[it -> second]++;
					s.erase(it -> second);
			}
			}
		}
	}
	assert(c == m);
	cout << ans;
    return 0;
}