#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 2 * max(v[0], l - v[n - 1]);
	for (int i = 1; i < n; ++i){
		ans = max(ans, v[i] - v[i - 1]);
	}

	cout << ans / 2 << ".";
	if (ans & 1) cout << "5" << endl;
	else cout << "0" << endl;

	return 0;
}