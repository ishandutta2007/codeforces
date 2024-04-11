#include <bits/stdc++.h>

using namespace std;
signed main() {
	int n, m;
	cin >> n >> m;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> pred(n);
	int l = -1, r = m;
	while(r - l > 1)
	{
		bool flag = true;
		int midd = (r + l) / 2;
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
			{
				if((A[i] + midd) % m < A[i])
				{
					pred[i] = 0;
				}
				else
				{
					pred[i] = A[i];
				}
			}
			else
			{
				if(A[i] < pred[i - 1])
				{
					if(pred[i - 1] - A[i] <= midd)
					{
						pred[i] = pred[i - 1];
					}
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					if((A[i] + midd) % m >= pred[i - 1] && A[i] + midd >= m)
					{
						pred[i] = pred[i - 1];
					}
					else
					{
						pred[i] = A[i];
					}
				}
			}
		}
		if(flag)
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	cout << r;
	return 0;
}