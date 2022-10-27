#include <bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return a * t % const1;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int d;
	cin >> d;
	int t = log2(d) + 1;
	vector <int> fact(t);
	fact[0] = 1;
	for(int i = 1; i < t; i++)
	{
		fact[i] = fact[i - 1] * i % const1;
	}
	vector <int> fact1(t);
	fact1[t - 1] = power(fact[t - 1], const1 - 2);
	for(int i = t - 2; i >= 1; i--)
	{
		fact1[i] = fact1[i + 1] * (i + 1) % const1;
	}
	vector <int> del;
	int d1 = d;
	for(int i = 2; i * i <= d1; i++)
	{
		if(d % i == 0)
		{
			del.push_back(i);
		}
		while(d % i == 0)
		{
			d = d / i;
		}
	}
	if(d != 1)
	{
		del.push_back(d);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int u, v;
		cin >> u >> v;
		int e = u / __gcd(u, v) * v;
		int cntall1 = 0, cntall2 = 0;
		int pr1 = 1, pr2 = 1;
		vector <int> cnt1(del.size()), cnt2(del.size()), cnt3(del.size());
		for(int i = 0; i < del.size(); i++)
		{
			while(u % del[i] == 0)
			{
				cnt1[i]++;
				u = u / del[i];
			}
			while(e % del[i] == 0)
			{
				cnt2[i]++;
				e = e / del[i];
			}
			while(v % del[i] == 0)
			{
				cnt3[i]++;
				v = v / del[i];
			}
		}
		for(int i = 0; i < del.size(); i++)
		{
			cntall1 += cnt2[i] - cnt1[i];
			if(cnt2[i] != cnt1[i])
			{
				pr1 = pr1 * fact1[cnt2[i] - cnt1[i]] % const1;
			}
			cntall2 += cnt2[i] - cnt3[i];
			if(cnt2[i] != cnt3[i])
			{
				pr2 = pr2 * fact1[cnt2[i] - cnt3[i]] % const1;
			}
		}
		cout << (fact[cntall1] * fact[cntall2] % const1) * (pr1 * pr2 % const1) % const1 << "\n";
	}
	return 0;
}