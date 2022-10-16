#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> ans(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int mx = 0;
	for (int i = n - 1; i >= 0; --i){
		ans[i] = max(mx - v[i] + 1, 0);
		mx = max(mx, v[i]);
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}