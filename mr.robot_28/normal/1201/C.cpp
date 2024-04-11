#include<bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int cnt = 0;
	for(int i = n / 2; i < n; i++)
	{
		if(i == n / 2)
		{
			cnt = 1;
		}
		else if(A[i] != A[i - 1])
		{
			if(cnt * (A[i] - A[i - 1]) <= k)
			{
				k = k - cnt * (A[i] - A[i - 1]);
			}
			else
			{
				cout << A[i - 1]+ k / cnt;
				return 0;
			}
			cnt++;
		}
		else
		{
			cnt++;
		}
	}
	int ans = A[n - 1] + k / ((n + 1)/ 2);
	cout << ans;
	return 0;
}