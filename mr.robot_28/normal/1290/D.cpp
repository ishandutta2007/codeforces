#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {	
	int n, k, c;
	cin >> n >> k;
	c = n / k;
	vector <bool> used(n, true);
	for(int i = 0; i  < c; i++)
	{
		int sum = 0;
		cout << "R" << endl;
		fflush(stdout);
		for(int j = 0; j < c; j++)
		{
			int a = (i + sum + c) % c;
			int st = a * k;
			for(int p = st; p < st + k; p++)
			{
				if(used[p])
				{
					cout << "? " << p + 1 << endl;
					fflush(stdout);
					char t;
					cin >> t;
					if(t == 'Y')
					{
						used[p] = false;
					}
				}
			}
			if(sum >= 0)
			{
				sum++;
			}
			sum = -sum;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(used[i])
		{
			ans++;
		}
	}
	cout <<"! " << ans << endl;
	fflush(stdout);
    return 0;
}