#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define ll long long
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define N 300100
#define MOD 1000000007 //998244353
#define pii pair<int,int>
#define pll pair<ll,ll>


int main() {
	ll n, k;
	ll a[N];
	ll x, y, z, z2, r, d;
	pair<ll, pll> p;
	ll ans = 0;
	priority_queue<pair<ll, pll> >pq;
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
		ans += (a[i] * a[i]);
		if (a[i] > 1) {
			x = a[i];
			y = 1;
			r = x / y;
			d = x % y;
			z = (r*r*(y - d));
			z += ((r + 1)*(r + 1)*d);
			y++;
			r = x / y;
			d = x % y;
			z2 = (r*r*(y - d));
			z2 += ((r + 1)*(r + 1)*d);
			pq.push({ z - z2,{i,y} });
		}
	}
	rep(i, k-n) {
		p = pq.top();
		pq.pop();
		ans -= (p.first);
		x = a[(p.second.first)];
		y = p.second.second;
		if (x > y) {
			r = x / y;
			d = x % y;
			z = (r*r*(y - d));
			z += ((r + 1)*(r + 1)*d);
			y++;
			r = x / y;
			d = x % y;
			z2 = (r*r*(y - d));
			z2 += ((r + 1)*(r + 1)*d);
			pq.push({ z - z2,{p.second.first,y} });
		}
	}
	cout << ans << endl;
	return 0;
}