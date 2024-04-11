#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;

int f[maxn] , last = -1;

ll dp[maxn] , ps[maxn] , pps[maxn];

int main()
{
	string s , t;
	cin >> s >> t;
	int n = s.size() , m = t.size() , state = 0;
	s = "#" + s;
	for(int i = 1; i < m; i++)
	{
		int state = f[i];
		while(state && t[state] != t[i])
			state = f[state];
		if(t[state] == t[i])
			state++;
		f[i + 1] = state;
	}
	state = 0;
	for(int i = 1; i <= n; i++)
	{
		while(state && t[state] != s[i])
			state = f[state];
		if(t[state] == s[i])
			state++;
		if(state == m)
		{
			dp[i] = (i - m + 1) + pps[i - m];
			state = f[state];
		}
		else
			dp[i] = dp[i - 1];
		dp[i] %= mod;

		ps[i] = (ps[i - 1] + dp[i]) % mod;
		pps[i] = (pps[i - 1] + ps[i]) % mod;
	}
	cout << ps[n] << endl;
}