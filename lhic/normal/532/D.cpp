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

const int MAXN = 300001;
const ll INF = 1ll << 40;
ll x[MAXN];
ll d[MAXN];
int st[MAXN], stc = 0;
ll sd[MAXN];
int s1c = 0, s2c = 0;
pair <ll, ll> sobs1[MAXN];
pair <ll, ll> sobs2[MAXN];
ll al[MAXN];
ll ar[MAXN];
multiset <ll> s1, s2;

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	x[0] = 0;
	d[0] = d[n + 1] = INF;
	for (int i = 0; i <= n + 1; i++)
	{
		cin >> x[i];
	}
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i <= n; i++) d[i] *= 2;
	stc = 0;
	st[0] = 0, sd[0] = INF;	
	for (int i= 1; i <= n + 1; i++)
	{
		while (sd[stc] < x[i] - x[st[stc]]) stc--;
		if (d[i] > x[i] - x[st[stc]])
		{
			ll nd = d[i] - (x[i] - x[st[stc]]);
			sobs1[s1c++] = make_pair(x[i] + 1, - 1 - x[i]);
			sobs1[s1c++] = make_pair(x[i] + nd, 1 + x[i]);
			++stc;
			st[stc] = i;
			sd[stc] = nd;
		}
	}
	if (stc > 1)
	{
		cout << 0 << endl;
		return 0;
	}
	stc = 0;
	st[0] = n + 1, sd[0] = INF;	
	for (int i= n; i >= 0; i--)
	{
		while (sd[stc] < x[st[stc]] - x[i]) stc--;
		if (d[i] > x[st[stc]] - x[i])
		{
			ll nd = d[i] - (x[st[stc]] - x[i]);
			sobs2[s2c++] = make_pair(x[i] - 1, x[i] + 1);
			sobs2[s2c++] = make_pair(x[i] - nd, - x[i] - 1);
			++stc;
			st[stc] = i;
			sd[stc] = nd;
		}
	}
	sobs1[s1c++] = make_pair(0, -1);
	sobs1[s1c++] = make_pair(x[n + 1], 1);
	sobs2[s2c++] = make_pair(0, -x[n + 1] - 1);
	sobs2[s2c++] = make_pair(x[n + 1], x[n + 1] + 1);
	sort(sobs1, sobs1 + s1c);
	sort(sobs2, sobs2 + s2c);
	ll ans = INF * 2;
	int p1 = 0, p2 = 0;
	while ((p1 < s1c) && (p2 < s2c))
	{
		if (sobs1[p1] < sobs2[p2])
		{
			ll vl = sobs1[p1++].second;
			if (vl > 0)
			{
				s1.erase(s1.lower_bound(vl - 1));
			}
			else s1.insert(-vl - 1);
		}
		else
		{
			ll vl = sobs2[p2++].second;
			if (vl > 0) 
			{
				s2.erase(s2.lower_bound(vl - 1));
			}
			else s2.insert(-vl - 1);
		}
		if (!s1.empty() && !s2.empty())
		{
			ll cur = *s2.begin();
			multiset <ll>::iterator it = s1.end();
			it--;
			cur -= *it;
			ans = min(ans, cur);
		}
	}
	cout << ans / 2 << "." << (ans % 2) * 5 << endl;
	return 0;
}