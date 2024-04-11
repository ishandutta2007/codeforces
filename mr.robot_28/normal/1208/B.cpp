# include <bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	map <int, int> W;
	int cnt = 0;
	int l = 0, r = -1;
	int min = 1e9;
	for(int i = 0; i < n; i++)
	{
		W[A[i]]++;
		if(W[A[i]] == 2)
		{
			cnt++;
		}
	}
	if(cnt == 0)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		W[A[i]]--;
		if(W[A[i]] == 1)
		{
			cnt--;
		}
		if(cnt == 0)
		{
			r = i;
			break;
		}
	}
	while(l < n)
	{
		if(r - l + 1 < min)
		{
			min = r - l + 1;
		}
		W[A[l]]++;
		if(W[A[l]] == 2)
		{
			while(r < n && W[A[l]]!= 1)
			{
				r++;
				W[A[r]]--;
			}
			if(r == n)
			{
				break;
			}
		}
		if(r == l)
		{
			W[r]--;
			r++;
		}
		l++;
	}
	cout << min;
	return 0;
}