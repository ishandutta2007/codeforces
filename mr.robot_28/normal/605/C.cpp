#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
vector <pair <double, double> > x;
double crossproduct(pair <double, double> a, pair <double, double> b, pair <double, double> c)
{
	return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first); 
}
bool cmp(pair <double, double> a, pair <double, double> b)
{
	if(a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	double p, q;
	cin >> n >> p >> q;
	x.resize(n + 2);
	double maxx = 0, maxy = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
		maxx = max(maxx, x[i].first);
		maxy = max(maxy, x[i].second);
	}
	x[n] = {maxx, 0};
	x[n + 1] = {0, maxy};
	sort(x.begin(), x.end(), cmp);
	vector <pair <double, double> > conv;
	for(int i = 0; i < x.size(); i++)
	{
		while(conv.size() > 1 && crossproduct(conv[conv.size() - 2], conv.back(), x[i]) >= 0)
		{
			conv.pop_back();
		}
		conv.push_back(x[i]);
	}
	double l = 0, r = 1e9;
	for(int i = 0; i < 70; i++)
	{
		double midd = (r + l) / 2;
		double x1 = p / midd;
		double y1 = q / midd;
		bool flag = true;
		for(int j = 0; j < conv.size() - 1; j++)
		{
			if(crossproduct(conv[j], conv[j + 1], {x1, y1}) > 0)
			{
				flag = false;
			}
		}
		if(flag)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	cout << fixed << setprecision(10) << l;
	return 0;
}