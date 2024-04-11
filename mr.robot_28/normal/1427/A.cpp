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
    	int n;
    	cin >> n;
    	int sum = 0;
    	vector <int> a, b, c;
    	for(int i = 0; i < n; i++)
    	{
    		int x;
    		cin >> x;
    		if(x < 0)
    		{
    			a.push_back(x);
			}
			else if(x == 0)
			{
				b.push_back(x);
			}
			else
			{
				c.push_back(x);
			}
			sum += x;
		}
		if(sum == 0)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		if(sum > 0)
		{
			for(int i = 0; i < c.size(); i++)
			{
				cout << c[i] << " ";
			}
			for(int i = 0; i < a.size(); i++)
			{
				cout << a[i] << " ";
			}
		}
		else if(sum < 0)
		{
			for(int i = 0; i < a.size(); i++)
			{
				cout << a[i] << " ";
			}
			for(int i = 0; i < c.size(); i++)
			{
				cout << c[i] << " ";
			}
		}
			for(int i = 0; i < b.size(); i++)
			{
				cout << b[i] << " ";
			}
			cout << "\n";
		}
	}
    return 0;
}