#include <bits/stdc++.h>
using namespace std;
#define double long double
#define int long long
const double eps = 1e-13;
const double pi = 3.1415926535897932384;
int crossproduct(pair <int, int> a, pair <int, int> b)
{
	return a.first * b.second - a.second * b.first;
}
int dotproduct(pair <int, int> a, pair <int, int> b)
{
	return a.first * b.first + a.second * b.second;
}
bool cmp(pair <pair <int, int> , int> a1, pair <pair <int, int> , int> b1)
{
	pair <int, int> a = a1.first;
	pair <int, int> b = b1.first;
	if(a.first == b.first && a.first == 0)
	{
		return a.second > b.second;
	}
	if(a.first * b.first < 0)
	{
		return a.first > b.first;
	}
	if(a.first == 0)
	{
		if(a.second > 0)
		{
			return true;
		}
		else
		{
			return b.first < 0;
		}
	}
	if(b.first == 0)
	{
		if(b.second > 0)
		{
			return false;
		}
		else
		{
			return a.first > 0;
		}
	}
	return crossproduct(a, b) < 0;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <pair <int, int>, int> > x(n);
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first.first >> x[i].first.second;
		x[i].second = i;
	}
	sort(x.begin(), x.end(), cmp);
	double fi = 1e9;
	int idx1 = 0, idx2 = 1;
	for(int i = 0; i < n; i++)
	{
		double fi1 = atan2(fabs(crossproduct(x[i].first, x[(i + 1) % n].first)), dotproduct(x[i].first, x[(i + 1) % n].first));
		if(fi1 < 0)
		{
			fi1 += pi;
		}
		if(fabs(fi1) < eps && dotproduct(x[i].first, x[(i + 1) % n].first) < 0)
		{
			fi1 = pi;
		}
		if(fi1 < fi)
		{
			fi = fi1;
			idx1 = x[i].second;
			idx2 = x[(i + 1) % n].second;
		}
	}
	cout << idx1 + 1 << " " << idx2 + 1;
	return 0;
}