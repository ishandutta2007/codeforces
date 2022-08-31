#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 100010;

ll length(ll n)
{
	if (n<=1)
		return 1;
	return 2*length(n/2)+1;
}

ll solve(ll n, ll L, ll R)
{
	if (L>R)
		return 0;
	if (n<=1)
		return n;
	ll m = length(n/2);
	if (L==1&&R==m+m+1)
		return n;
	if (R<=m)
		return solve(n/2, L, R);
	else if (L>=m+2)
		return solve(n/2, L-(m+1), R-(m+1));
	else
	{
		return solve(n/2, L, m) + n%2 + solve(n/2, 1, R-(m+1));
	}
}

int main()
{
	
	ll n, L, R;
	cin >> n >> L >> R;
	cout << solve(n, L, R) << endl;
	
	return 0;
}