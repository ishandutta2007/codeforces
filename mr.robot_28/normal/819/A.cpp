#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, l, r;
	cin >> a >> b >> l >> r;
	string s = "";
	for(int i = 0; i < a; i++)
	{
		s += 'a' + i;
	}
	for(int i = 0; i < b; i++)
	{
		s += 'a' + a - 1;
	}
	vector <bool> used(27);
	for(int i = b; i < a + b; i++)
	{
		used[s[i] - 'a'] = true;
	}
	int j = 0;
	for(int i = 0; i < a; i++)
	{
		while(j < 27 && used[j])
		{
			j++;
		}
		s += 'a' + j;
		j++;
	}
	j = a;
	for(int i = 0; i < b; i++)
	{
		s += 'a' + j;
	}
	vector <int> cnt(s.size() + 1);
	for(int i = 0; i < 27; i++)
	{
		used[i] = 0;
	}
	for(int i = 0; i < s.size(); i++)
	{
		cnt[i + 1] = cnt[i];
		cnt[i + 1] += (1 - used[s[i] - 'a']);
		used[s[i] - 'a'] = 1;
	}
	if(r - l >= s.size())
	{
		cout << cnt[s.size()];
		return 0;
	}
	int n = s.size();
	string p = s;
	for(int i= 0; i < 10; i++)
	{
		s += p;
	}
	int d = l / n;
	int w = r - l;
	l -= d * n;
	l += n - 1;
	r = l + w;
	for(int i = 0; i < 27; i++)
	{
		used[i] = 0;
	}
	vector <int> cons(s.size());
	for(int i = a; i < a + b; i++)
	{
		cons[i] = 1;
	}
	int k = s.size();
	for(int i = 0; i < k; i++)
	{
		cons[i] = cons[i % (a + b)];
	}
	vector <set <int> > check(2);
	for(int i = 0; i < a; i++)
	{
		check[1].insert(s[i] - 'a');
	}
	for(int i = a + b; i < 2 * a + b; i++)
	{
		check[0].insert(s[i] - 'a');
	}
	int ans = 0;
	for(int i = r; i >= l; i--)
	{
		if(cons[i])
		{
			int d = i % n;
			int h = (d <= n / 2 ? 0 : 1);
			for(int j = 0; j < 26; j++)
			{
				if(check[h].find(j) == check[h].end() && used[j])
				{
					s[i] = j + 'a';
				}
			}
		}
		ans += (1 - used[s[i] - 'a']);
		used[s[i] - 'a'] = 1;
	}
	cout << ans;
	return 0; 
}