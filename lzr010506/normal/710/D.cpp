#include <bits/stdc++.h>
#define ll long long
#define inf 10000000
using namespace std;

ll gcd(ll a, ll b)
{
	while(a)
	{
		ll c = a;
		a = b % a;
		b = c;
	}
	return b;
}

void ex_gcd(ll a, ll b, ll &x, ll &y)
{
	if(!b) {x = 1; y = 0; return;}
    ex_gcd(b, a % b, x, y);
    ll z = x - a / b * y; 
	x = y; 
	y = z;
}

ll exgcd(ll a, ll b, ll c)
{
    ll Gcd = gcd(a,b);
    if(c % Gcd) return -inf;
    a /= Gcd;
    b /= Gcd;
    c /= Gcd;
    ll x, y;
    ex_gcd(a, b, x, y);
    x = x * c; 
    x %= b; 
    y = (c - x * a) / b;
    return x;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

ll div1(ll a, ll b)
{
	ll s = a / b;
	ll ret = 0;
	for(int i = s - 2; i <= s + 2; i ++)
		if(i * b <= a) ret = i;
	return ret;
}

ll div2(ll a, ll b)
{
	ll s = a / b;
	ll ret = 0;
	for(int i = s + 2; i >= s - 2; i --)
		if(i * b >= a) ret = i;
	return ret;
}

ll a[3], b[3], x = 1, y = 0, X, Y;
void init(int i)
{
	scanf("%I64d %I64d", &X, &Y);
	a[i] = X;
	b[i] = Y;
	ll p = exgcd(x, X, Y - y);
	if(p == -inf) {printf("0"); exit(0);}
	ll xx = p * x + y;
	ll lm = lcm(x, X);
	y = (xx % lm + lm) % lm;
	x = lm;
}

int main()
{
	int T = 2;
	for(int i = 1; i <= T; i ++)
		init(i);
    
    ll l,r;
    scanf("%I64d %I64d", &l, &r);
    l = max(max(l, b[1]), b[2]);
    if(l > r) {printf("0"); return 0;}
	l -= y; 
	r -= y;
	ll ans = div1(r, x) - div2(l, x) + 1;
	cout<<max(ans,0LL)<<"\n";
	return 0;
}