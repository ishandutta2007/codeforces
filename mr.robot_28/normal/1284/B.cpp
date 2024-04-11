#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > T;
	int ans = n * n;
	for(int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		vector <int> A(l);
		for(int j = 0; j < l; j++)
		{
			cin >> A[j];
		}
		bool flag = true;
		for(int j =1; j < l; j++)
		{
			if(A[j] > A[j - 1])
			{
				flag = false;
			}
		}
		if(flag)
		{
			T.push_back({A[0], A[l - 1]});
		}
	}
	sort(T.begin(), T.end());
	for(int j = 0; j < T.size(); j++)
	{
		int l = -1, r = T.size();
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(T[midd].first <= T[j].second)
			{
				l = midd;
			}
			else
			{
				r = midd;
			}
		}
		ans -= (l + 1);
	}
	cout << ans;
	return 0;
}