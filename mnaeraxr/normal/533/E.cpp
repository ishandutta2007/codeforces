#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s, t;
	cin >> s >> t;

	int b = 0, e = 0;
	for (;s[b] == t[b]; ++b);
	for (;s[n - e - 1] == t[n - e - 1]; ++e);

	int ans = 0;

	string s1 = s.substr(0, b) + t[b] + s.substr(b, n - b);
	string t1 = t.substr(0, n - e) + s[n - e - 1] + t.substr(n - e, e);

	if (s1 == t1) ++ans;

	string s2 = s.substr(0, n - e) + t[n - e - 1] + s.substr(n - e, e);
	string t2 = t.substr(0, b) + s[b] + t.substr(b, n - b);

	if (s2 == t2) ++ans;

	cout << ans << endl;

	return 0;
}