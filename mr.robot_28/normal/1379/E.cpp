#include<bits/stdc++.h>
 
using namespace std;
int ans[200010];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	if(n % 2 == 0)
	{
		cout << "NO";
		return 0;
	}
	if(k == 0)
	{
		int a = n + 1;
		while(a % 2 == 0)
		{
			a = a / 2;
		}
		if(a == 1)
		{
			cout << "YES\n";
			for(int i = 1; i <= n; i++)
			{
				cout << i /2 << " ";
			}
		}
		else
		{
			cout << "NO";
		}
	}
	else if(k == 1)
	{
		int a = n + 1;
		while(a % 2 == 0)
		{
			a = a / 2;
		}
		if(a != 1)
		{
			cout << "YES\n";
			for(int i = 1; i <= n; i++)
			{
				cout << i / 2 << " ";
			}
		}
		else
		{
			cout << "NO";
		}
	}
	else
	{
		int root = 1;
		ans[1] = 0;
		for(int i = 1; i <= k - 1; i++)
		{
			ans[root + 1] = root;
			ans[root + 2] = root;
			root += 2;
		}
		if(n - root + 1 <= 3)
		{
			cout << "NO";
			return 0;
		}
		int a = (n - root + 1) + 1;
		while(a % 2 == 0)
		{
			a = a / 2;
		}
		if(a != 1)
		{
			for(int i = root + 1; i <= n; i++)
			{
				ans[i] = (i - root + 1) / 2 + (root - 1);
			}
			cout << "YES\n";
			for(int i = 1; i <= n; i++)
			{
				cout << ans[i] << " ";
			}
		}
		else
		{
			if(n == 9){
				cout << "NO";
				return 0;
			}
			ans[n]= 2;
			ans[n - 1] = 2;
			n -= 2;
			for(int i = root + 1; i <= n; i++)
			{
				ans[i] = (i - root + 1) / 2 + (root - 1);
			}
			cout << "YES\n";
			for(int i = 1; i <= n + 2; i++)
			{
				cout << ans[i] << " ";
			}
		}
	}
	return 0;
}