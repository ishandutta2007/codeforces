#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	bool flag = true;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			flag = false;
		}
	}
	if(flag)
	{
		cout << 1;
		return 0;
	}
	if(n % 2 == 0)
	{
		cout << 2;
		return 0;
	}
	flag = true;
	for(int i = 2; i * i <= n - 2; i++)
	{
		if((n - 2) % i == 0)
		{
			flag = false;
		}
	}
	if(flag)
	{
		cout <<2;
	}
	else
	{
		cout << 3;
	}
	return 0;
}