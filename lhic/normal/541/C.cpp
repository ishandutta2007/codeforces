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

const ld PI = acos(-1.0);

const int MAXN = 201;
int f[MAXN];
int w[MAXN];

ll gcd(ll a, ll b)
{
	while (b != 0)
	{
		ll c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> f[i];
	ll ans = 1, mn = 1;
	for (int i = 1; i <= n; i++)
	{
		for  (int j = 1; j <= n; j++)
		{
			w[j] = -1;
		}
		int x = i, cv = 0;
		while (w[x] == -1)
		{
			w[x] = cv++;
			x = f[x];
		}
		mn = max(mn, (ll)w[x]);
		ll b = (ll)(cv - w[x]);
		ll g = gcd(ans, b);
		b /= g;
		ans *= b;
	}
	ans = ((mn - 1) / ans + 1) * ans;
	cout << ans << endl;
	return 0;
}