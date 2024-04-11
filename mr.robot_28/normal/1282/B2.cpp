#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, p, k;
		cin >> n >> p >> k;
		vector <int> A(n);
		vector <int> sum(k);
		for(int i = 0;  i < n; i++)
		{
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		int i = 0;
		int cnt = 0;
		for(i = k - 1; i < n; i += k)
		{
			if(A[i] > p)
			{
				break;
			}
			p -= A[i];
			cnt += k;
		}
		i = max(0, i - k + 1);
		for(int j = 0; j < i; j++)
		{
			sum[j % k] += A[j];
		}
		int d = 0;
		if(i == 0)
		{
			d = -1;
		}
		while(i < n)
		{
			if(i != 0)
			{
				p += sum[(i - 1 + k) % k];
			}
			if(d != -1)
			{
				sum[d % k] -= A[d];
				p -= A[d];
			}
			d++;
			sum[i % k] += A[i];
			p -= sum[i % k];
			if(p >= 0)
			{
				cnt++;
			}
			else
			{
				break;
			}
			i++;
		}
		cout << cnt << "\n";
	}
	return 0;
}