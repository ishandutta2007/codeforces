#include <bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		int cnt = 0;
		int cnt1 = 0;
		int sum = 0;
		int cnt2 = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			if(A[i] == 0)
			{
				cnt++;
				A[i]++;
			}
			sum += A[i];
			if(A[i] > 0)
			{
				cnt1++;
			}
			else if(A[i] < -1)
			{
				cnt2++;
			}
		}
		if(sum == 0)
		{
			if(cnt1 != 0)
			{
				cout << cnt + 1 << "\n";
			}
			else if(cnt2 != 0)
			{
				cout << cnt + 1 << "\n";
			}
			else
			{
				cout << cnt + 2 << "\n";
			}
		}
		else
		{
			cout << cnt << "\n";
		}
	}
	return 0;
}