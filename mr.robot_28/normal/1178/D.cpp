#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int CONST = 998244353;
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <pair <int, int> > ans;
	int cnt = 0;
	vector <bool> prime(1 + 3 * n / 2, true);
	for(int i = n; i <= 3 * n / 2; i++)
	{
		for(int q = 2; q <= sqrt(i); q++)
		{
			if(i % q == 0)
			{
				prime[i] = false;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cnt++;
		ans.push_back({i + 1, (i + 1) % n + 1});
	}
	if(!prime[cnt])
	{
		for(int i = 0; i < n / 2; i++)
		{
			ans.push_back({i + 1, i + 1 + n / 2});
			cnt++;
			if(prime[cnt])
			{
				break;
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	return 0;
}