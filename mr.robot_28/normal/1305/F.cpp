#include<bits/stdc++.h>
using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
int ans = 1e9;
vector <int> pr;
vector <bool> used(1e6 + 1);
set <long long> can;
void add_prime(long long a)
{
	for(int i = 0; i < pr.size(); i++)
	{
		if(a == 1)
		{
			break;
		}
		if(a % pr[i] == 0)
		{
			can.insert(pr[i]);
			while(a % pr[i] == 0)
			{
				a = a / pr[i];
			}
		}
	}
	if(a > 1)
	{
		can.insert(a);
	}
}
vector <long long> a;
int n;
int solve(long long val)
{
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i] < val)
		{
			ans += val - a[i];
		}
		else
		{
			ans += min((val - a[i] % val) % val, a[i] % val);
		}
	}
	ans = min(ans, 1LL * n);
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	a.resize(n);
	vector <int> p;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		p.push_back(i);
	}
	for(int i = 2; i < 1e6; i++)
	{
		if(!used[i])
		{
			pr.push_back(i);
			for(int j = i; j < 1e6; j += i)
			{
				used[j] = 1;
			}
		}
	}
	shuffle(p.begin(), p.end(), mt);
	for(int i = 0; i < 50 && i < n; i++)
	{
		int ind = p[i];
		add_prime(a[ind]);
		add_prime(a[ind] + 1);
		if(a[ind] > 1)
		{
			add_prime(a[ind] - 1);
		}
	}
//	can.resize(unique(can.begin(), can.end()) - can.begin());
	for(long long v : can)
	{
		ans = min(ans, solve(v));
	}
	cout << ans;
	return 0;
}