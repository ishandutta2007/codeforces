#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000100;

int t[N];

void add(int pos, int val)
{
	for (; pos < N; pos |= pos + 1)
		t[pos] += val;
}

int get(int pos)
{
	int s = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
		s += t[pos];
	return s;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	set<int> a;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.insert(t);
		add(t, 1);
	}
	if (k == 1)
	{
		cout << n;
		return 0;
	}
	int ans = 0;
	for (auto it = a.begin(); it != a.end(); it++)
	{
		int i = *it;
		auto p = a.lower_bound(i + m);
		p--;
		while (get(*p) - get(i - 1) >= k)
		{
			add(*p, -1);
			a.erase(p);
			p = a.lower_bound(i + m);
			p--;
			ans++;
		}
	}
	cout << ans;
	return 0;
}