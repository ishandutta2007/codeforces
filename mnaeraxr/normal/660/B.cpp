

#include <bits/stdc++.h>
#include <ext/algorithm>
#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= 2 * n; ++i){
		int v = 2 * n + i;
		if (v <= m) cout << v << " ";
		if (i <= m) cout << i << " ";
	}
	cout << endl;

	return 0;
}