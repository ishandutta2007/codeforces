#include<bits/stdc++.h>
using namespace std;
#define double long double
const double eps = 1e-9;
vector <int> x, y;
double dist(int i, int j)
{
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	x.resize(n);
	y.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
	}
	vector <pair <double, pair <int, int> > > str;
	vector <vector <unsigned long long> > mass(n, vector <unsigned long long> (n / 64 + 1, 0));
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			str.push_back({dist(i, j), {i, j}});
		}
	}
	sort(str.begin(), str.end());
	for(int i = str.size() - 1; i >= 0; i--)
	{
		double dist = str[i].first;
		int a = str[i].second.first;
		int b = str[i].second.second;
		for(int j = 0; j < (n / 64) + 1; j++)
		{
			if((mass[a][j] & mass[b][j]) != 0)
			{
				cout << fixed << setprecision(10) << dist / 2;
				return 0;
			}
		}
		int c = 64;
		int ost = a % c;
		mass[b][a / c] |= (1ll << ost);
		ost = b % c;
		mass[a][b / c] |= (1ll << ost);
	}
	return 0;
}