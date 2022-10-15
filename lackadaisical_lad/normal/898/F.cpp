#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1001000;

const vector<ll> M = { (ll)1e9 + 7, (ll)1e9 + 9, (ll)1e9 - 1337 };

string s;
int n;
ll h[3][N], p[3][N];

bool check(int i, int j)
{
	for (int k = 0; k < 3; k++)
	{
		ll t1 = h[k][i + 1];
		ll t2 = h[k][j + 1] - h[k][i + 1] * p[k][j - i] % M[k];
		ll t3 = h[k][n] - h[k][j + 1] * p[k][n - j - 1] % M[k];
		t2 = (t2 + M[k]) % M[k];
		t3 = (t3 + M[k]) % M[k];
		if ((t1 + t2) % M[k] != t3)
			return false;
	}
	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> s;
	int t = s.length() / 3;
	n = s.length();
	for (int i = 0; i < 3; i++)
	{
		p[i][0] = 1;
		for (int j = 1; j <= n; j++)
		{
			h[i][j] = (h[i][j - 1] * 10 + s[j - 1] - '0') % M[i];
			p[i][j] = p[i][j - 1] * 10 % M[i];
		}
	}
	for (int i = 0; i < n - 2; i++)
	{
		int l = 0, r = n;
		if (i <= t)
		{
			l = i + (n - i - 1) / 2 - 2;
			r = i + (n - i - 1) / 2 + 2;
		}
		else
		{
			l = i + (n - 2 * i - 2) - 2;
			r = i + (n - 2 * i - 2) + 2;
		}
		for (int j = max(i + 1, l); j < min(r, n - 1); j++)
		{
			if (check(i, j))
			{
				string f1 = s.substr(0, i + 1), f2 = s.substr(i + 1, j - i), f3 = s.substr(j + 1, n - j);
				if (f1.length() > 1 && f1[0] == '0')
					continue;
				if (f2.length() > 1 && f2[0] == '0')
					continue;
				if (f3.length() > 1 && f3[0] == '0')
					continue;
				cout << f1 << '+' << f2 << '=' << f3;
				return 0;
			}
		}
	}
	return 0;
}