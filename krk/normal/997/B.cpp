#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 3;
const int dx[Maxd] = {4, 9, 49};

set <int> S, nS;

int main()
{
	S.insert(0);
	int n; scanf("%d", &n);
	for (int i = 1; i <= 11 && i <= n; i++) {
		int was = S.size();
		nS.clear();
		for (set <int>::iterator it = S.begin(); it != S.end(); it++)
			for (int j = 0; j < Maxd; j++)
				nS.insert(*it + dx[j]);
		for (set <int>::iterator it = nS.begin(); it != nS.end(); it++)
			S.insert(*it);
	}
	ll res = S.size();
	if (n > 11) res += ll(n - 11) * 49ll;
	cout << res << endl;
	return 0;
}