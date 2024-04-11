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

	string a, b, c;
	cin >> a >> b >> c;

	a += b;
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());

	cout << (a == c ? "YES" : "NO") << endl;

	return 0;
}