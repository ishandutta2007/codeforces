#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 1e6 + 10;

ll mul(ll a, ll b, ll M)
{
	ll q = (long double) a * (long double) b / (long double) M;
	ll r = a * b - q * M;
	return (r + 5 * M) % M;
}

ll pow(ll a, ll b, ll M)
{
	ll x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1) x = mul(x, a, M);
		a = mul(a, a, M);
	}
	return x;
}

ll euler_phi(ll n)
{
	if (n == 0)
		return 0;
	ll ans = n;
	for (ll x = 2; x * x <= n; ++x)
		if (n % x == 0)
		{
			ans -= ans / x;
			while (n % x == 0)
				n /= x;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

vector<ll> primes(ll lo, ll hi)
{
	const ll M = 1 << 14, SQR = 1 << 16;
	vector<bool> composite(M), small_composite(SQR);
	vector<pair<ll, ll>> sieve;
	for (ll i = 3; i < SQR; i += 2)
		if (!small_composite[i])
		{
			ll k = i * i + 2 * i * max(0.0, ceil((lo - i * i) / (2.0 * i)));
			sieve.push_back({ 2 * i, k });
			for (ll j = i * i; j < SQR; j += 2 * i)
				small_composite[j] = 1;
		}
	vector<ll> ps;
	if (lo <= 2)
	{
		ps.push_back(2);
		lo = 3;
	}
	for (ll k = lo | 1, low = lo; low < hi; low += M)
	{
		ll high = min(low + M, hi);
		fill(composite.begin(), composite.end(), 0);
		for (auto &z : sieve)
			for (; z.second < high; z.second += z.first)
				composite[z.second - low] = 1;
		for (; k < high; k += 2)
			if (!composite[k - low])
				ps.push_back(k);
	}
	return ps;
}

vector<ll> primes(ll hi)
{
	return primes(0, hi);
}

ll primitive_root(ll m)
{
	if (m == 1)
		return 0;
	if (m == 2)
		return 1;
	if (m == 4)
		return 3;
	auto pr = primes(0, sqrt(m) + 1); // fix upper bound
	ll t = m;
	if (!(t & 1))
		t >>= 1;
	for (ll p : pr)
	{
		if(p > t)
			break;
		if (t % p)
			continue;
		do
			t /= p;
		while (t % p == 0);
		if (t > 1 || p == 2)
			return 0;
	}
	ll x = euler_phi(m), y = x, n = 0;
	vector<ll> f(32);
	for (ll p : pr)
	{
		if (p > y)
			break;
		if (y % p)
			continue;
		do
			y /= p;
		while (y % p == 0);
		f[n++] = p;
	}
	if (y > 1)
		f[n++] = y;
	for (ll i = 1; i < m; ++i)
	{
		if (__gcd(i, m) > 1)
			continue;
		bool flag = 1;
		for (ll j = 0; j < n; ++j)
		{
			if (pow(i, x / f[j], m) == 1)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			return i;
	}
	return 0;
}

bool isprime(int n)
{
	if(n == 2)
		return 1;
	if(n % 2 ==0)
		return 0;
	for(int i = 3; i * i <= n; i++)
		if(n % i == 0)
			return 0;
	return 1;
}

ll div(ll a, ll b, ll M)
{
	ll u = 1, x = 0, s = b, t = M;
	while (s)
	{
		ll q = t / s;
		swap(x -= u * q, u);
		swap(t -= s * q, s);
	}
	if (a % t) return -1; // infeasible
	return mul(x < 0 ? x + M : x, a / t, M);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if(n == 4)
	{
		cout << "YES" << endl << "1\n3\n2\n4" << endl;
		return 0;
	}

	if(n == 1)
	{
		cout << "YES" << endl << 1 << endl;
		return 0;
	}

	if(!isprime(n))
	{
		cout << "NO" << endl;
		return 0;
	}


	ll g = primitive_root(n);
	cout << "YES" << endl;
	ll cur = 1;
	for(int i = 0; i < n - 1; i++) 
	{
		if(i % 2 == 0)
			cout << pow(pow(g, n - 2, n), i, n) << endl;
		else
			cout << cur << endl;
		cur = cur * g % n;
	}	

	cout << n << endl;

	return 0;
	
}