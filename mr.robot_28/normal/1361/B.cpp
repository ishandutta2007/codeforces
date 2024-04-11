#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
int power(int a, int b){
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t= power(a, b /  2);
		return t * t % const1;
	}
	else
	{
		int t= power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, p;
		cin >> n >> p;
		vector <int> k(n);
		for(int i = 0; i < n; i++)
		{
			cin >> k[i];
		}
		sort(k.begin(), k.end());
		reverse(k.begin(), k.end());
		int ans = 0;
		for(int i = 0; i < k.size(); i++)
		{
			if(i == k.size() - 1)
			{
				ans = power(p, k[i]);
				break;
			}
			else if(k[i] == k[i + 1])
			{
				i++;
			}
			else
			{
				int j = i + 1;
				int c = 1;
				bool flag = true;
				while(j < n)
				{
					int a = k[j - 1] - k[j];
					while(p != 1 && c < n && a > 0)
					{
						a--;
						c *= p;
					}
					if(c >= n)
					{
						flag = false;
						break;
					}
					c--;
					if(c == 0)
					{
						break;
					}
					j++;
				}
				if(c == 0)
				{
					i = j;
				}
				else
				{
					ans = power(p, k[i]);
					j = i + 1;
					while(j < n)
					{
						ans -= power(p, k[j]);
						if(ans < 0)
						{
							ans += const1;
						}
						j++;
					}
					break;
				}
			}
		}
		cout << ans << "\n";
	}
    return 0;
}