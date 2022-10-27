#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;

signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	vector <int> pre_calc(1e5 + 1);
	for(int i = 1; i <= 1e5; i++)
	{
		for(int j = 1; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				pre_calc[i]++;
				if(j * j != i)
				{
					pre_calc[i]++;
				}
			}
		}
	}
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector <int> mass(8);
		mass[7] = pre_calc[__gcd(__gcd(a, c), b)];
		mass[6] = pre_calc[__gcd(b, c)] - mass[7];
		mass[5] = pre_calc[__gcd(a, c)] - mass[7];
		mass[3] = pre_calc[__gcd(a, b)] - mass[7];
		mass[4] = pre_calc[c] - mass[7] - mass[6] - mass[5];
		mass[2] = pre_calc[b] - mass[7] - mass[3] - mass[6];
		mass[1] = pre_calc[a] - mass[7] - mass[3] - mass[5];
		int ans = 0;
		for(int t1 = 1; t1 < 7; t1++)
		{
			for(int t2 = t1; t2 < 8; t2++)
			{
				for(int t3 = t2; t3 < 8; t3++)
				{
					if((t1 | t2 | t3) == 7)
					{
						if(t1 == t2)
						{
							ans += mass[t1] * (mass[t1] + 1) / 2 * mass[t3];
						}
						else if(t2 == t3)
						{
							ans += mass[t1] * mass[t2] * (mass[t2] + 1) / 2;
						}
						else if(t1 == t3)
						{
							ans += mass[t2] *mass[t1] * (mass[t1] + 1) / 2;
						}
						else
						{
							ans += mass[t1] * mass[t2] * mass[t3];
						}
					}
				}
			}
		}
		ans += mass[7] * (mass[7] + 1) * (mass[7] + 2) / 6;
		ans -= mass[1] * (mass[1] + 1) / 2 * (mass[6] + mass[7]);
		ans -= mass[2] * (mass[2] + 1) / 2 * (mass[5] + mass[7]);
		ans -= mass[4] * (mass[4] + 1) / 2 * (mass[3] + mass[7]);
		cout << ans << "\n";
	}
	return 0;
}