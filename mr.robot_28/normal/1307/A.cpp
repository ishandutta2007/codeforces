#include<bits/stdc++.h>
 
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
		int n, d;
		cin >> n >> d;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		int sum = A[0];
		for(int i = 1; i < n; i++)
		{
			if(d > A[i] * i)
			{
				sum += A[i];
				d -= A[i] * i;
			}
			else
			{
				sum += d / (i);
				break;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}