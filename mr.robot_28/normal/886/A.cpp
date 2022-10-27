#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector <int> a(6);
    int sum = 0;
    for(int i = 0; i < 6; i++)
    {
    	cin >> a[i];
    	sum += a[i];
	}
	for(int i = 0; i < 6; i++)
	{
		for(int j = i + 1; j < 6; j++)
		{
			for(int k = j + 1; k < 6; k++)
			{
				if(2 * (a[i] + a[j] + a[k]) == sum)
				{
					cout << "YES";
					return 0;
				}
			}
		}
	}
	cout << "NO";
    return 0;
}