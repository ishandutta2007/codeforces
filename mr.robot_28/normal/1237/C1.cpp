#include <bits/stdc++.h>
using namespace std;
#define int long long
int dist(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
	return (a.first.first - b.first.first) * (a.first.first - b.first.first) + (a.first.second - b.first.second) * (a.first.second - b.first.second) + (a.second - b.second) * (a.second - b.second);
}
signed main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <pair <pair <int, int>, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		A[i] = {{x, y}, z};
	}
	vector <bool> used(n, false);
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			int mx = 1e18;
			int im = -1;
			for(int j = i + 1; j < n; j++)
			{
				if(!used[j])
				{
					if(dist(A[i], A[j]) < mx)
					{
						mx = dist(A[i], A[j]);
						im = j;
					}
				}
			}
			used[im] = true;
			cout << i + 1 << " " << im + 1 << "\n";
		}
	}
  	return 0;
}