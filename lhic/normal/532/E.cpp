#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ll M1 = 1000 * 1000 * 1000 * 1000 * 1000 * 100 + 7;
const ll M2 = 1000 * 1000 * 1000 * 1000 * 100 * 100 + 9;
const ld PI = acos(-1.0);
const ll HSH = 43;
const int MAXN = 100002;
ll p[MAXN], sf[MAXN];
ll sh[MAXN];
const int MM = 26 * MAXN;
pair <ll, ll> a[MM];
pair <ll, ll> b[MM];	

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	sh[0] = 1;
	for (int i = 1; i < MAXN; i++) sh[i] = (sh[i - 1] * HSH) % M1;
	p[0] = 0;
	for (int i = 0; i < n; i++)
	{
		p[i + 1] = (p[i] + (ll)(s[i] - 'a' + 1) * sh[i]) % M1;
	}
	sf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sf[i] = (sf[i + 1] + (ll)(s[i] - 'a' + 1) * sh[i + 1]) % M1;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			a[i * 26 + j].first = (p[i] + sf[i] + (ll)(j + 1) * sh[i]) % M1;
		}
	}
	p[0] = 0;
	for (int i = 0; i < n; i++)
	{
		p[i + 1] = (p[i] + (ll)(t[i] - 'a' + 1) * sh[i]) % M1;
	}
	sf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sf[i] = (sf[i + 1] + (ll)(t[i] - 'a' + 1) * sh[i + 1]) % M1;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			b[i * 26 + j].first = (p[i] + sf[i] + (ll)(j + 1) * sh[i]) % M1;
		}
	}

	sh[0] = 1;
	for (int i = 1; i < MAXN; i++) sh[i] = (sh[i - 1] * HSH) % M2;
	p[0] = 0;
	for (int i = 0; i < n; i++)
	{
		p[i + 1] = (p[i] + (ll)(s[i] - 'a' + 1) * sh[i]) % M2;
	}
	sf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sf[i] = (sf[i + 1] + (ll)(s[i] - 'a' + 1) * sh[i + 1]) % M2;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			a[i * 26 + j].second = (p[i] + sf[i] + (ll)(j + 1) * sh[i]) % M2;
		}
	}
	p[0] = 0;
	for (int i = 0; i < n; i++)
	{
		p[i + 1] = (p[i] + (ll)(t[i] - 'a' + 1) * sh[i]) % M2;
	}
	sf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		sf[i] = (sf[i + 1] + (ll)(t[i] - 'a' + 1) * sh[i + 1]) % M2;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			b[i * 26 + j].second = (p[i] + sf[i] + (ll)(j + 1) * sh[i]) % M2;
		}
	}

	int cn = (n + 1) * 26;
	sort(a, a + cn);
	sort(b, b + cn);
	int as = unique(a, a + cn) - a;
	int bs = unique(b, b + cn) - b;
	int pa = 0, pb = 0;
	int ans = 0;
	while ((pa < as) && (pb < bs))
	{
		if (a[pa] == b[pb])
		{
			ans++;
			pa++, pb++;
		}
		else if (a[pa] < b[pb]) pa++;
		else pb++;
	}
	cout << ans << endl;
		return 0;
}