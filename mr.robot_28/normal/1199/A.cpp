#include <bits/stdc++.h>
using namespace std;
signed main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i =0; i < n; i++)
	{
		bool flag = true;
		for(int j = max(i - x, 0); j < i; j++)
		{
			if(A[j] <= A[i])
			{
				flag = false;
			}
		}
		for(int j = i + 1; j <= min(n - 1, i + y); j++)
		{
			if(A[j] <= A[i])
			{
				flag = false;
			}
		}
		if(flag)
		{
			cout << i + 1;
			return 0;
		}
	}
    return 0;
}