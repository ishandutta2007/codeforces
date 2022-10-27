#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a , b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a,b / 2);
		t = t * t % const1;
		return a * t % const1;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> simple;
	vector <int> pred(1e5 + 1, -1);
	for(int i = 2; i <= 1e5; i++)
	{
		if(pred[i] == -1)
		{
			simple.push_back(i);
			int d = i;
			while(d <= 1e5)
			{
				pred[d] = i;
				d += i;
			}
		}
	}
	vector <int> meb(1e5 + 1);
	vector <int> cnt(1e5 + 1);
	meb[1] = 1;
	for(int i = 2; i <= 1e5; i++)
	{
		vector <int> ns;
		int a = i;
		while(a > 1)
		{
			ns.push_back(pred[a]);
			a = a / pred[a];
		}
		bool flag = false;
		for(int j = 0; j + 1 < ns.size(); j++)
		{
			if(ns[j] == ns[j + 1])
			{
				flag = true;
			}
		}
		if(!flag)
		{
			if(ns.size() % 2 == 0)
			{
				meb[i] = 1;
			}
			else
			{
				meb[i] = -1;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= sqrt(A[i]); j++)
		{
			if(A[i] % j == 0)
			{
				cnt[j]++;
			}
			if(j * j != A[i] && A[i] % j == 0)
			{
				cnt[A[i] / j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 1e5; i++)
	{
		ans += (power(2, cnt[i]) - 1) * meb[i] % const1;
		ans = (ans + const1) % const1;
	}
	cout << ans;
	return 0;
}