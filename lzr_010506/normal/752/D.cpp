#include <bits/stdc++.h>
#define MOD 1000000007
#define Fst first
#define Sec second
#define MP make_pair
#define PB pop_back
#define ll long long
#define sz size
#define bk(a) (a).back()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
int K, N;
string s[100010];
ll m[2] = {1000000007ll, 1000000009ll}, k[100010];
map<ll, vector<ll>> M;
map<ll, ll> Op;

ll ans, res;

int main () 
{
	cin >> K >> N;
	for(int j = 0; j < K; j ++)
	{
		ll v;
		cin >> s[j] >> v;
		ll h[2] = {0ll, 0ll}, g[2] = {0ll, 0ll};
		for (char c : s[j]) 
			for(int i = 0; i < 2; i ++) 
				h[i] = (h[i] * 137 + c) % m[i];
		reverse(ALL(s[j]));
		for (char c : s[j]) 
			for(int i = 0; i < 2; i ++) 
				g[i] = (g[i] * 137 + c) % m[i];

		ll H = h[0] * 1000000009ll + h[1];
		ll G = g[0] * 1000000009ll + g[1];

		M[H].push_back(v);
		Op[H] = G;
	}

	for (auto& i : M) sort(ALL(i.Sec));

	for (auto& x : M) 
	{
		ll h = x.Fst;
		if (h == Op[h]) 
		{
			vector<ll>& a = x.Sec;
			ll X = -1e18, Y = -1e18;
			while ((int) a.sz() >= 2 && a[(int)a.sz() - 2] + a[(int)a.sz() - 1] >= 0) 
			{
				res += bk(a);
				X = bk(a);
				a.PB();
				res += bk(a);
				Y = bk(a);
				a.PB();
			}
			if (X != -1e18)  ans = max(ans, -Y);
			if (a.sz()) ans = max(ans, a.back());
		} 
		else if (h < Op[h]) 
		{
			vector<ll> a = x.Sec, b = M[Op[h]];
			while (a.sz() && b.sz() && bk(a) + bk(b) >= 0) 
			{
				res += bk(a) + bk(b);
				a.PB();
				b.PB();
			}
		}
	}

	printf("%lld\n", res + ans);

	return 0;
}