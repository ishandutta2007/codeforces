#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	for (auto& x : s) cin >> x;
	for (auto& x : t) cin >> x;
	int N = n * m;
	vector<string> r(n*m);
	for (int i = 0, a = 0, b = 0; i < N; ++i, a = (a+1)%n, b = (b+1)%m)
	{
		r[i] = s[a] + t[b];
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		x--;
		x %= n*m;
		cout << r[x] << endl;
	}

	return 0;
}