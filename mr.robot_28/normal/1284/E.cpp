#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int dotproduct(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - x2 * y1;
}
bool cmp(pair <int, int> a, pair <int, int> b)
{
	bool t1 = false;
	bool t2 = false;
	if(a.first < 0 || a.first == 0 && a.second < 0)
	{
		t1 = true;
	}
	if(b.first < 0 || b.first == 0 && b.second < 0)
	{
		t2 = true;
	}
	if(t1 == t2)
	{
		return dotproduct(a.first, a.second, b.first, b.second) >0;
	}
	else
	{
		return t1 < t2;
	}
}
int bino(int x, int y)
{
	int rez =1;
	for(int i = 0; i < y; i++)
	{
		rez *= x - i;
		rez /= i + 1;
	}
	return rez;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		vector <pair <int, int> > v;
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{
				v.push_back({A[j].first - A[i].first, A[j].second - A[i].second});
			}
		}
		sort(v.begin(), v.end(), cmp);
		int j = 0;
		for(int i = 0; i < v.size(); i++)
		{
			while(j < i + v.size() && dotproduct(v[i].first, v[i].second, v[(j) % v.size()].first,
			v[j % v.size()].second) >= 0)
			{
				j++;
			}
			sum -= bino(j - i - 1, 3);
		}
	}
	cout << sum + bino(n, 5) * 5;
	return 0;
}