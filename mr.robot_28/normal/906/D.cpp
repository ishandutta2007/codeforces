#include<bits/stdc++.h>
 
using namespace std;
#define int long long
int n, mod;
vector <int> w;
vector <int> t;
int phi(int a)
{
	int ans = a;
	for(int i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
		{
			ans -= ans / i;
			while(a % i == 0)
			{
				a = a / i;
			}
		}
	}
	if(a > 1)
	{
		ans -= ans / a;
	}
	return ans;
}
int power = 32;
int modl(int a, int mod)
{
	if(a >= power)
	{
		return power + (a - power) % mod;
	}
	return a;
}
int bp(int a, int k, int mod)
{
	if(k == 1)
	{
		return modl(a, mod);
	}
	else if(k % 2 == 0)
	{
		int t = bp(a, k / 2, mod);
		return modl(t * t, mod);
	}
	else
	{
		return modl(bp(a, k - 1, mod) * a, mod);
	}
}
int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	return b;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> mod;
	w.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	int q;
	cin >> q;
	t.push_back(mod);
	while(phi(t.back()) != 1)
	{
		t.push_back(phi(t.back()));
	}
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		r = min(r, l + t.size() - 1);
		int ans = 1;
		for(int i = r; i >= l; i--)
		{
			ans = bp(w[i], ans, t[i - l]);
		}
		cout << ans % mod << "\n";
	}
	return 0;
}