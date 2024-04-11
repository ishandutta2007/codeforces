#include <bits/stdc++.h>

using namespace std;

int main() {
	#define int long long
	int n, h, m;
	cin >> n >> h >> m;
	vector <pair <int, pair <int,int> > > A;
	for(int i = 0; i < m; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		A.push_back({x - 1, {y - 1, d}});
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int max = h;
		for(int j = 0; j < m; j++)
		{
			if(A[j].first <= i && A[j].second.first >= i)
			{
				if(max > A[j].second.second)
				{
					max = A[j].second.second;
				}
			}
		}
		sum += max * max;
	}
	cout << sum;
	return 0;
}