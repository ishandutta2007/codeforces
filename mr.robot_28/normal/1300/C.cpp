#include <bits/stdc++.h>
 
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	vector <int> rev(n);
	vector <int> prefrev(n), postrev(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
			rev[i] = pow(2, 30) - 1 - A[i];
	}
	if(n == 1)
	{
		cout << A[0];
		return 0;
	}
	int ind = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			prefrev[i] = rev[i];
		}
		else
		{
			prefrev[i] = (prefrev[i - 1] & rev[i]);
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(i == n - 1){
			postrev[i] = rev[i];
		}
		else
		{
			postrev[i] = (postrev[i + 1] & rev[i]);
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			if((A[i] & postrev[i + 1]) > ans)
			{
				ans = (A[i] & postrev[i + 1]);
				ind = i;
			}
		}
		else if(i == n - 1)
		{
			if((A[i] & prefrev[i - 1]) > ans)
			{
				ans = (A[i] & prefrev[i - 1]);
				ind = i;
			}
		}
		else if((A[i] & prefrev[i - 1] & postrev[i + 1]) > ans)
		{
			ans = (A[i] & prefrev[i - 1] & postrev[i + 1]);
			ind = i;
		}
	}
	cout << A[ind] << " ";
	for(int i = 0; i < ind; i++)
	{
		cout << A[i] << " ";
	}
	for(int i = ind + 1; i < n; i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}