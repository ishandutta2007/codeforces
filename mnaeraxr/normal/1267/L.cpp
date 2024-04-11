#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, l, k;
	cin >> n >> l >> k;

	vector<string> a(n, string(l, '@'));
	string s;
	cin >> s;

	sort(s.begin(), s.end());

	int last = 0, pt = 0;
	for (int j = 0; j < l; ++j)
	{
		for (int i = last; i < k; ++i)
		{
			a[i][j] = s[pt];
			if (i > 0 && a[i][j] != a[i-1][j]) last = i;
			++pt;
		}
	}

	for (auto &i : a)
		for (auto &j : i)
			if (j == '@')
				j = s[pt++];
	/*for (int i = n-1; i >= 0; --i)
		for (int j = l-1; j >= 0; --j)
			if (a[i][j] == '@')
				a[i][j] = s[pt++];*/

	for (auto &i : a)
		cout << i << "\n";

	return 0;
}