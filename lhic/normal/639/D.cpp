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
#include <memory.h>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);
const ll INF = (1ll << 61);
const int MAXN = 300001;

set <pair <ll, int> > st;

ll a[MAXN];
const ll AD = 1000ll * 1000ll * 1000ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n, k;
	ll b, c;
	cin >> n >> k >> b >> c;
	b = min(b, 5ll * c);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] += AD;
	}
	sort(a, a + n);
	ll ans = INF;
	for (int mod = 0; mod < 5; mod++)
	{
		st.clear();
		ll ss = 0;
		for (int i = 0; i < n; i++)
		{
			ll da = a[i];
			ll cur = 0;
			while (da % 5 != mod) cur+=c, da++;
			ll db = (da / 5ll) * b;
			cur -= db;
			st.insert(mp(-cur, i));
			ss += cur;
			if (st.size() > k)
			{
				ss += st.begin()->first;
				st.erase(*st.begin());
			}
			if (st.size() == k)
			{
				ans = min(ans, db * (ll)k + ss);
			}
		}
	}
	cout << ans << endl;
	return 0;
}