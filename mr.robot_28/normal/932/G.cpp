#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
const int mod = 1e9 + 7;
const int N = 2e5 + 100;

struct str{
	int start, delta, count;
	str(int start1 = 0, int delta1 = 0, int count1 = 0) : start(start1), delta(delta1), count(count1){}
	int end()
	{
		return start + delta * (count - 1);
	}
};

vector <str> g1;
void push(str t)
{
	if(sz(g1) == 0 || g1.back().delta != t.delta)
	{
		g1.push_back(t);
	}
	else
	{
		g1.back().count += t.count;
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = sz(s);
	string s1;
	for(int i = 0; i < n / 2; i++)
	{
		s1 += s[i];
		s1 += s[n - i - 1];
	}
	vector <str> g;
	vector <int> d(n + 1), cache(n + 1);
	d[0] = 1;
	for(int i = 0; i < n; i++)
	{
		int prev = -i - 1;
		for(auto t : g)
		{
			if(t.start > 0 && s1[t.start - 1] == s1[i])
			{
				t.start--;
				if(prev != t.start - t.delta)
				{
					push(str(t.start, t.start - prev, 1));
					t.start += t.delta;
					t.count--;
				}
				if(t.count > 0)
				{
					push(t);
				}
				prev = t.end();
			}
		}
		if(i >= 1 && s1[i - 1] == s1[i])
		{
			push(str(i - 1, i - 1 - prev, 1));
		}
		g = move(g1);
		//cout << i << "\n";
		for(auto &t : g)
		{
		//	cout << t.start << " " << t.delta << " " << t.count << "\n";
			int add = d[t.end()];
			if(t.count > 1)
			{
				add += cache[t.start - t.delta];
			}
			add %= mod;
			if(t.start - t.delta >= 0)
			{
				cache[t.start - t.delta] = add;
			}
			d[i + 1] += add;
			d[i + 1] %= mod;
		}
		g1.clear();
	}
	cout << d[n];
	return 0;
}