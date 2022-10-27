#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	vector <int> pr(1e5 + 1, -1);
	int n;
	cin >> n;
	vector <int> primes;
	for(int i = 2; i <= n; i++)
	{
		if(pr[i] == -1)
		{
			primes.push_back(i);
			if(i > sqrt(n))
			{
				continue;
			}
			int j = i * i;
			while(j <= n)
			{
				pr[j] = i;
				j += i;
			}
		}
	}
	for(int j = 1; j <= n; j++)
	{
		pr[j] = -1;
	}
	int m = primes.size();
	int k = sqrt(m);
	int ans = 1;
	int sum = n;
	int c = 0;
	int flag = 0;
	for(int i = 0; i < primes.size(); i++)
	{
//		cout << primes[i] << " ";
	}
	for(int i = 0; i < m; i++)
	{
		if(i >= k - 1 && primes[i - k + 1] * ans > n)
		{
			break;
		}
		cout << "B " << primes[i]<< endl;
		int num = 0;
		for(int j = primes[i]; j <= n; j += primes[i])
		{
			if(pr[j] == -1)
			{
				num++;
				--sum;
				pr[j] = 1;
			}
		}
		int x;
		cin >> x;
		if(x != num)
		{
			for(int j = primes[i]; j <= n; j *= primes[i])
			{
				cout << "A " << j << endl;
				cin >> x;
				if(x)
				{
					ans *= primes[i];
				}
				else
				{
					break;
				}
			}
		}
		if((i == m - 1 || i % k == k - 1) && !flag)
		{
			cout << "A 1" << endl;
			cin >> x;
			if(x != sum)
			{
				for(int j = i - k + 1; j <= i; j++)
				{
					for(int j1 = primes[j]; j1 <= n; j1 *= primes[j])
					{
						cout << "A " << j1 << endl;
						cin >> x;
						if(x)
						{
							ans *= (primes[j]);
							flag = 1;
						}
						else
						{
							break;
						}
					}
					if(flag)
					{
						break;
					}
				}
			}
			
		}
	}
	cout << "C " << ans << "\n";
  	return 0;
}