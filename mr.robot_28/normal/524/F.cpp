#include<bits/stdc++.h>
using namespace std;
#define int long long
string s, t;
int n;
const int mod1 = 1e9 + 7, mod2 = 998244353;
vector <int> hash1, hash2;
vector <int> powers1, powers2;
pair <int, int> get(int l, int r)
{
	if(l == 0)
	{
		return {hash1[r], hash2[r]};
	}
	return {(hash1[r] - hash1[l - 1] * powers1[r - l + 1] % mod1 + mod1) % mod1,
	(hash2[r] - hash2[l - 1] * powers2[r - l + 1] % mod2 + mod2) % mod2};
}
bool compare(int i, int j)
{
	int l = 0, r = n + 1;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		if(get(i, i + midd - 1) == get(j, j + midd - 1))
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	if(l == n)
	{
		return 0;
	}
	else
	{
		return (t[i + l] == '(');
	}
}
signed main() {	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	n = s.size();
	t = s + s;
	hash1.resize(2 * n);
	hash2.resize(2 * n);
	powers1.resize(2 * n + 1);
	powers2.resize(2 * n + 1);
	powers1[0] = powers2[0] = 1;
	for(int i = 0; i < 2 * n; i++)
	{
		if(i != 0)
		{
		hash1[i] = (hash1[i - 1] * 10 + (t[i] == ')') + 1) % mod1;
		hash2[i] = (hash2[i - 1] * 10 + (t[i] == ')') + 1) % mod2;
		}
		else
		{
			hash1[i] = hash2[i] = (t[i] == ')') + 1;
		}
		powers1[i + 1] = powers1[i] * 10 % mod1;
		powers2[i + 1] = powers2[i] * 10 % mod2;
	}
	vector <int> prefsum(n + 1);
	for(int i = 1;i <= n; i++)
	{
		prefsum[i] = prefsum[i - 1];
		if(s[i - 1] == '(')
		{
			prefsum[i]++;
		}
		else
		{
			prefsum[i]--;
		}
	}
	vector <int> prefmin(n + 1, 1e9), postmin(n + 2, 1e9);
	vector <int> prefmax(n + 1, -1e9), postmax(n + 2, -1e9);
	prefmax[0] = prefmin[0] = prefsum[0];
	for(int i = 1; i <= n; i++)
	{
		prefmin[i] = min(prefmin[i - 1], prefsum[i]);
		prefmax[i] = max(prefmax[i - 1] + prefsum[i] - prefsum[i - 1], prefsum[i] - prefsum[i - 1]);
	}
	for(int i = n; i >= 1; i--)
	{
		if(i == n)
		{
			postmax[i] = prefsum[n] - prefsum[n - 1];
		}
		else
		{
			postmax[i] = max(postmax[i + 1], prefsum[n] - prefsum[i]);
		}
		if(i == n)
		{
			postmin[i] = prefsum[i] - prefsum[i - 1];
		}
		else
		{
			postmin[i] = min(postmin[i + 1] + prefsum[i] - prefsum[i - 1], prefsum[i] - prefsum[i - 1]);
		}
	}
	int st = -1;
	if(prefsum[n] <= 0)
	{
		if(postmax[1] <= 0)
		{
			st = 0;
		}
		for(int i = 1; i < n; i++)
		{
			if(max(prefmax[i], prefsum[i] + postmax[i + 1]) <= 0)
			{
	//			cout << i << '\n';
	//			cout << compare(i, st)<< "\n";
				if(st == -1)
				{
					st = i;
				}
				else if(compare(i, st))
				{
					st = i;
				}
			}
		}
//		cout << compare(12, st) << "\n";
//		cout << st << "\n";
		for(int i = 0; i < -prefsum[n]; i++)
		{
			cout <<"(";
		}
		for(int i = 0; i < n; i++)
		{
			cout << t[st + i]; 
		}
	}
	else
	{
		if(prefmin[n] >= 0)
		{
			st = 0;
		}
		for(int i = n; i >= 2; i--)
		{
			if(min(postmin[i], prefmin[i - 1] + (prefsum[n] - prefsum[i - 1])) >= 0)
			{
//				cout << i  << " " << compare(i - 1, st) << "\n";
				if(st == -1)
				{
					st = i - 1;
				}
				else if(compare(i - 1, st))
				{
					st = i - 1;
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			cout << t[st + i];
		}
		for(int i = 0; i < prefsum[n]; i++){
			cout << ")";
		}
	}
    return 0;
}