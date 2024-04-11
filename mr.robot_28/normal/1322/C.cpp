#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int cnst1 = 1e9 + 7;
const int cnst2 = 1e9 + 37;
int pow1(int a, int n, int p)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n % 2 == 1)
	{
		int b = pow1(a, n / 2, p);
		b = b * b % p;
		return b * a % p;
	}
	else
	{
		int b = pow1(a, n / 2, p);
		return b * b % p;
	}
}
signed main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int e;
	cin >> e;
	while(e--)
	{
		int n, m;
		cin >> n >> m;
		vector <int> c(n);
		for(int i = 0; i < n; i++)
		{
			cin >> c[i];
		}
		vector <int> hash1(n), hash2(n), cnt(n);		
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			y--;
			cnt[y]++;
			hash1[y] += pow1(n, x - 1, cnst1);
			hash2[y] += pow1(n, x - 1, cnst2);
			hash1[y] %= cnst1;
			hash2[y] %= cnst2;
		}
		vector <pair <pair <int, int>, int> > t;
		for(int i = 0; i < n; i++)
		{
			if(cnt[i] == 0)
			{
				continue;
			}
			t.push_back({{hash1[i], hash2[i]}, c[i]});
		}
		sort(t.begin(), t.end());
		int ans = 0;
		for(int i = 0; i < t.size(); i++){
			int j = i;
			int sum = 0;
			while(j < t.size() && t[i].first == t[j].first)
			{
				sum += t[j].second;
				j++;
			}
			ans = __gcd(ans, sum);
			i = j - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}