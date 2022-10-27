#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> fenv;
void update(int a)
{
	while(a >= 0)
	{
		fenv[a]++;
		a = (a & (a + 1)) - 1;
	}
}
int query(int a)
{
	int ans = 0;
	while(a < fenv.size())
	{
		ans += fenv[a];
		a = (a | (a + 1));
	}
	return ans;
}
signed main()
{
	int n;
	cin >> n;
	fenv.resize(n, 0);
	vector <int> A(n);
	vector <pair <int, int> > B(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		B[i].first = A[i];
		if(A[i] > n)
		{
			A[i] = n + 1;
		}
		A[i]--;
		B[i].first--;
		B[i].second = i;
	}
	sort(B.begin(), B.end());
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		while(j < B.size() && B[j].first < i)
		{
			if(i > B[j].second)
			{
				ans --;
			}
			ans += query(B[j].second);
			j++;
		}
		update(min(A[i], n - 1));
	}
	while(j < B.size())
	{
		ans += query(B[j].second);
		ans--;
		j++;
	}
	cout << ans / 2;
	return 0;
}