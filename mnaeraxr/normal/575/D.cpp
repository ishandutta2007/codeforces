#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n = 1000;

	cout << 2 * n << endl;

	for (int i = 1; i <= n; ++i)
		cout << i << " " << 1 << " " << i << " " << 2 << endl;

	for (int i = n; i; --i)
		cout << i << " " << 1 << " " << i << " " << 2 << endl;

	return 0;
}