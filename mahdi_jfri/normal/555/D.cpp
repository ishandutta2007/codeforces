#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

ll a[maxn] , b[maxn] , pos[maxn] , posr[maxn] , n;

int solve(ll p , ll l)
{
	while(1)
	{
		int R = upper_bound(b , b + n + 2 , p + l) - b - 1;
		int L = lower_bound(b , b + n + 2 , 2 * b[R] - l - p) - b; 

		if(L == R)
			return L;
		ll x = l - 2 * b[R] + p + b[L];
		if((x / (b[R] - b[L])) & 1)
			p = b[R];
		else
			p = b[L];
		l = x % (b[R] - b[L]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;

	for(int i = 1; i <= n; i++)
		cin >> a[i] , b[i] = a[i];
	b[n + 1] = 1e15;
	b[0] = -b[n + 1];
	sort(b , b + n + 2);

	for(int i = 1; i <= n; i++)
	{
		pos[i] = lower_bound(b , b + n + 2 , a[i]) - b;
		posr[pos[i]] = i;
	}

	while(q--)
	{
		int p , l;
		cin >> p >> l;
		cout << posr[solve(a[p] , l)] << endl;
	}
}