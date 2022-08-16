#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 100010;

ll add(ll x,ll y,ll z)
{
	ll t = x+y;
	if (t>=z) t -= z;
	return t;
}

ll mul(ll x,ll y,ll z)
{
	ll t=0;
	while (y)
	{
		if (y&1)
			t = add(t, x, z);
		x = add(x, x, z);
		y >>= 1;
	}
	return t;
}

ll power(ll a,ll b,ll p)
{
	if (b==0) return 1;
	ll t=power(a,b>>1,p);
	t=mul(t,t,p);
	if (b&1) t=mul(t,a,p);
	return t;
}

ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}

bool is_prime(ll p)
{
	static ll a[]={2,3,5,7,11,13,17,19,23,29,31,37};
	if (p==1) return false;
	for (int i=0;i<12&&a[i]<p;++i)
	{
		ll t=p-1;
		int s=0;
		while (!(t&1))
		{
			t>>=1;
			++s;
		}
		ll d=power(a[i]<p?a[i]:a[i]%p,t,p);
		if (d==1||d==p-1) continue;
		int flag=0;
		for (;s;--s)
		{
			d=mul(d,d,p);
			if (d==p-1)
			{
				flag=1;
				break;
			}
		}
		if (!flag) return false;
	}
	return true;
}

ll getrand(ll n)
{
	return rand()%n;
}

ll pollard_rho(ll n,ll c)
{
	ll x,y,d,s,t;
	for (x=y=getrand(n-1)+1,d=s=1,t=2;d==1;)
	{
		x=mul(x,x,n)+c;
		if (x>=n) x-=n;
		d=gcd(x>y?x-y:y-x,n);
		if (++s==t) y=x,t*=2;
	}
	return d;
}

int b[MAXN];
vector<int> primes;

vector<ll> factorization(ll n)
{
	if (n == 1)
		return vector<ll>();
	if (is_prime(n))
		return vector<ll>(1,n);
	vector<ll> v;
	for (auto p : primes)
	{
		if (p*p > n) break;
		while (n%p == 0)
		{
			n /= p;
			v.push_back(p);
		}
	}
	if (n > 1) v.push_back(n);
	return v;
}

bool check(int c, int d)
{
	int e = c+d;
	if (e%3 != 0) return false;
	int s = e/3;
	int x = c-s;
	int y = d-s;
	if (0 <= x && 0 <= y) return true;
	return false;
}

bool check(vector<pii> &a, vector<pii> &b)
{
	if (a.size() != b.size()) return false;
	for (int i = 0; i < a.size(); ++ i)
	{
		if (a[i].X != b[i].X) return false;
		int c = a[i].Y, d = b[i].Y;
		/*
		c = x+2y
		d = 2x+y
		c+d = 3(x+y)
		*/
		if (!check(c, d)) return false;
	}
	return true;
}

int main()
{
	for (int i = 2; i <= 1000; ++ i)
		if (!b[i])
		{
			primes.push_back(i);
			for (int j = i+i; j <= 1000; j += i)
				b[j] = 1;
		}
	srand(101);
	
	int T;
	scanf("%d", &T);
	while (T --)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		ll d = (ll)a*b;
		ll nd = pow(d, 1./3);
		while ((nd+1)*(nd+1)*(nd+1) <= d)
			++ nd;
		if (nd*nd*nd != d)
		{
			puts("No");
			continue;
		}
		vector<int> v;
		for (auto p : primes)
		{
			if (p*p > nd) break;
			if (nd%p == 0)
			{
				nd /= p;
				v.push_back(p);
			}
		}
		if (nd > 1)
			v.push_back(nd);
		map<int, int> Fa, Fb;
		int flag = 0;
		for (auto p : v)
		{
			while (a%p == 0)
			{
				a /= p;
				Fa[p] ++;
			}
			while (b%p == 0)
			{
				b /= p;
				Fb[p] ++;
			}
		}
		
		vector<pii> wa, wb;
		for (auto p : Fa)
			wa.push_back(p);
		for (auto p : Fb)
			wb.push_back(p);
		if (check(wa, wb))
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	
	return 0;
}