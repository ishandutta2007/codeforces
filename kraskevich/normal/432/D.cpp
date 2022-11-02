#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string s;
    cin >> s;
    //cerr << s << endl;
    int n = s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i,  r = i + z[i] - 1;
	}
    z[0] = n;
	//for (int i = 0; i < n; i++)
    //    cerr << z[i] << " ";
    cerr << endl;
	vector<int> v;
	for (int i = 0; i < n; i++)
        v.push_back(-z[i]);
    sort(v.begin(), v.end());
    vector<pii> ans;
    for (int len = 1; len <= n; len++)
        if (z[n - len] >= len)
        {
            int p = upper_bound(v.begin(), v.end(), -len) - v.begin() + 1;
            ans.push_back(pii(len, p));
        }
    cout << ans.size() << "\n";
    for (pii x : ans)
        cout << x.F << " " << x.S - 1 << "\n";

    return 0;
}