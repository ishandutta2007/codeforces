#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int m;
	cin >> m;
	vector <pair <pair <int, int>, int> > T;
	for(int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			int p, x;
			cin >> p >> x;
			T.push_back({{p, x}, type});
		}
		else
		{
			int x;
			cin >> x;
			T.push_back({{0, x}, type});
		}
	}
	int t = 0;
	vector <int> ANS(n);
	vector <bool> used(n, false);
	for(int i = m - 1; i >= 0; i--)
	{
		if(T[i].second == 1)
		{
			if(!used[T[i].first.first - 1])
			{
				if(T[i].first.second < t)
				{
					ANS[T[i].first.first - 1] = t;
				}
				else
				{
					ANS[T[i].first.first - 1] = T[i].first.second;
				}
				used[T[i].first.first - 1] = true;
			}
		}
		else
		{
			t = max(t, T[i].first.second);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			if(A[i] < t)
			{
				ANS[i] = t;
			}
			else
			{
				ANS[i] = A[i];
			}
		}
		cout << ANS[i] << " ";
	}
    return 0;
}