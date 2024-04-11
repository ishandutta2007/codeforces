#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b; cin >> a >> b;
	vector<int> v(a);
	for (int i = 0; i < a; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int ans = 0, tot = 0;
	while (tot < b)
		tot += v[ans++];
	cout << ans << endl;

	return 0;
}