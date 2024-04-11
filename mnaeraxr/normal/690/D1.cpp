#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

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

	int a, b;
	cin >> a >> b;
	string s;

	for (int i = 0; i < a; ++i)
		cin >> s;

	int ans = 0;

	s = "." + s;
	for (int i = 1; i < (int)s.length(); ++i)
		if (s[i] == 'B' && s[i - 1] == '.') ++ans;

	cout << ans << endl;

	return 0;
}