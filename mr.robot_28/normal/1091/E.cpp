#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
#define int long long
const int  CONST = 998244353;
vector <int> A;
int sum = 0;
int is(int val)
{
	vector <int> C(A.size() + 1);
	for(int i = 0; i < A.size(); i++)
	{
		++C[A[i]];
	}
	++C[val];
	int less = 0;
	int left = 0, right = 0;
	int n = A.size();
	for(int k = 0, i = 0; k <= n; k++)
	{
        int vl = (i == k && (i == n || A[i] < val)) ? val : A[i++];
		left += vl;
		--C[vl];
		right -= min(vl, k);
		less += C[k];
		right += n - k - less;
		if(left > right + (k + 1) * k)
		{
			return (i == k) ? 1 : -1;
		}
	}
	return 0;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	A.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	sort(A.begin(), A.end(), greater <int> ());
	int parity = sum & 1;
	int l = 0, r = (n - parity) / 2, L = -1;
	while(l <= r)
	{
		int midd  = (r + l) / 2;
		if(is(2 * midd + parity) == -1)
		{
			l = midd + 1;
		}
		else
		{
			L = midd;
			r = midd - 1;
		}
	}
	l = L;
	r = (n - parity) / 2;
	int R = -1;
	while(l <= r)
	{
		int midd = (r + l) / 2;
		if(is(2 * midd + parity) == 1)
		{
			r = midd - 1;
		}
		else
		{
			R = midd;
			l = midd + 1;
		}
	}
	if(L == -1 || R == -1)
	{
	cout << -1;
	}
	else
	{
		for(int i = L; i <= R; i++)
		{
			cout << i * 2 + parity << " ";
		}
	}
	return 0;
}