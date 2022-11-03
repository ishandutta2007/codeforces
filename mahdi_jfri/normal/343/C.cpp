#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

ll h[maxn] , p[maxn] , n , m;

bool check(ll M)
{
	int pos = 0;
	for(int i = 0; i < n; i++)
	{
		if(h[i] - p[pos] > M)
			return 0;
		if(h[i] > p[pos])
		{
			ll k = (M - (h[i] - p[pos]));
			k = max(h[i] + k / 2 , k + p[pos]);
			pos = upper_bound(p , p + m , k) - p;
		}
		else
		{
			while(pos < m && p[pos] - h[i] <= M)
				pos++;
		}
		if(pos == m)
			return 1;
	}
	return pos == m;
}

int main()
{
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> h[i];
	for(int i = 0; i < m; i++)
		cin >> p[i];

	ll l = -1 , r = 1e16;

	while(r - l > 1)
	{
		ll m = (r + l) / 2;
		if(check(m))
			r = m;
		else
			l = m;
	}
	cout << r << endl;
}