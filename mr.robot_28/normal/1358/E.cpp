#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A((n + 1) / 2);
	int sum = 0;
	vector <int> post(n, 0);
	for(int i = 0; i < (n + 1) / 2; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	for(int i = (n + 1) / 2 - 1; i >= 0; i--)
	{
		post[i] = post[i + 1] + A[i];
 	}
	int x;
	cin >> x;
	if(x >= 0 && sum + (n / 2) * x <= 0)
	{
		cout << -1;
		return 0;
	}
	else if(x >= 0)
	{
		cout << n;
		return 0;
	}
	int len = n / 2 + 1;
	for(int i = (n + 1) / 2 - 1; i >= 0; i--)
	{
		int p = (n + 1) / 2 - i;
		if(post[i] + (len - p) * x <= 0)
		{
			len = n - (i - 1);
		}
	}
	if(len > n)
	{
		cout << -1;
	}
	else
	{
		cout << len;
	}
    return 0;
}