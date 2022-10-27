# include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	if(a.first.first == b.first.first)
	{
		return a.first.second > b.first.second;
	}
	return a.first.first < b.first.first;
}
double inter(pair <int, int> a, pair <int, int> b)
{
	double k1 = a.first;
	double c1 = a.second;
	double k2 = b.first;
	double c2 = b.second;
	return (c2 - c1) / (k1 - k2);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <pair <int, int>, int> > p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i].first.first >> p[i].first.second >> p[i].second;
	}
	sort(p.begin(), p.end(), cmp);
	vector <pair <int, int> > st;
	st.push_back(make_pair(0, 0));
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int c = p[i].first.first * p[i].first.second - p[i].second;
		if(st.size() != 0)
		{
			int l = st.size(), r = 0;
			while(l - r > 1)
			{
				int midd = (r + l) / 2;
				if(inter(st[midd], st[midd - 1]) <= double(p[i].first.second))
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			c = max(c, st[l - 1].first * p[i].first.second - p[i].second + p[i].first.first * p[i].first.second + st[l - 1].second);
			ans = max(ans, st[l - 1].first * p[i].first.second - p[i].second + p[i].first.first * p[i].first.second + st[l - 1].second);
		}
		pair <int, int> line = make_pair(-p[i].first.first, c);
		ans = max(ans, c);
		while(st.size() > 1 && inter(st[st.size() - 2], st[st.size() - 1]) <= inter(st[st.size() - 2], line))
		{
			st.pop_back();
		}
		st.push_back(line);
	}
	cout << ans;
	return 0;
}