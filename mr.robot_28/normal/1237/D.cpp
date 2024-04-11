#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> A;
vector <int> t;
inline void build(int v, int l, int r)
{
	if(l == r)
	{
		t[v] = A[l];
		return;
	}
	build(v * 2,l, (r + l) / 2);
	build(v * 2 + 1, (r + l) / 2 + 1, r);
	t[v] = min(t[v * 2], t[v * 2 + 1]);
}
inline int ans(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return t[v];
	}
	if(l > ar || r < al)
	{
		return 1e9;
	}
	return min(ans(v * 2, l, (r + l) / 2, al, ar), ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
}
signed main() 
{
	int n;
	cin >> n;
	A.resize(n * 3);
	t.resize(n * 12);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = n; i < n * 3; i++)
	{
		A[i] = A[i - n];
	}
	build(1, 0, n * 3- 1);
	int j = n * 3  - 1;
	vector <int> next(n * 3);
	for(int i = 0; i < n * 3; i++)
	{
		int l = i, r = 3 * n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(ans(1, 0, n * 3 - 1, i, midd) * 2 < A[i])
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		next[i] = l;
	}
	vector <int> an(n);
	int r = 3 * n - 1;
	for(int i = 3 * n - 1; i >= n; i--)
	{
		r = min(r, next[i]);
	}
	for(int i = n - 1; i >= 0; i--)
	{
		r = min(r, next[i]);
			an[i] = (r - i + 1);
	}
	for(int i = 0; i < n;i++)
	{
		if(an[i] + i == 3 * n)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << an[i] << " ";
		}
	}
  	return 0;
}