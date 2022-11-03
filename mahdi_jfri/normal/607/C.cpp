#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6 + 20;
string s, t;
char x[maxn];
ll dp[maxn], cnt[maxn];
int main()
{
    int n;
	x['N'] = 'S';
	x['S'] = 'N';
	x['E'] = 'W';
	x['W'] = 'E';
	cin >> n >> s >> t;
	cnt[0] = 1;
	for(int i = 1; i < n; ++i)
		cnt[i] = cnt[i - 1] * 31;
    n--;
	for(int i = n - 1; i >= 0; --i)
		dp[i] = s[i] * cnt[n - i - 1] + dp[i + 1];
	ll h = 0;
	for(int i = n - 1; i >= 0; --i)
    {
        h *= 31;
        h += x[t[i]];
		if (dp[i] == h)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}