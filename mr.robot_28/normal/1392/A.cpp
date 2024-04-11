#include<bits/stdc++.h>
using namespace std;
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
    	vector <int> a(n);
    	long long sum = 0;
    	for(int i = 0; i < n; i++)
    	{
    		cin >> a[i];
    		sum += a[i];
		}
		vector <int> pred(n, -1);
		int maxcnt = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[i - 1] != a[i])
			{
				pred[i] = i - 1;
			}
			else
			{
				pred[i] = pred[i - 1];
			}
		}
		if(pred[n - 1] == -1)
		{
			cout << n << "\n";
		}
		else
		{
			cout << 1 << "\n";
		}
	}
    return 0;
}