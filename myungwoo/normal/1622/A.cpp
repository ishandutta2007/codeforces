#include <bits/stdc++.h>
using namespace std;

void solve()
{
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	bool ans = 0;
	if (a[0]+a[1] == a[2]) ans = 1;
	for (int i=0;i<3;i++){
		int j = (i+1)%3;
		if (a[j] == a[3-i-j] && a[i]%2 == 0) ans = 1;
	}
	cout << (ans ? "YES" : "NO") << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}