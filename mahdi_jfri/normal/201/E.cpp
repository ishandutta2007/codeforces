#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int inf = 2e9;
const ll infl = 2e18;

int check(int m , int x)
{
	ll tmp = 1LL * m * x , choose = 1 , sum = 0 , res = 0;

	for(int i = 0; i <= x; i++)
	{
		ll shit = choose;
		if(i && shit > infl / i)
			shit = infl;
		else
			shit *= i;

		if(tmp >= shit)
		{
			tmp -= shit;

			if(res > infl - choose)
				res = infl;
			else
				res += choose;
		}
		else
		{
			if(res > infl - tmp / i)
				res = infl;
			else
				res += tmp / i;
			break;
		}

		if(i == x)
			break;

		ll k = __gcd(choose , 1LL + i);
		shit = i + 1;

		choose /= k;
		shit /= k;

		shit = (x - i) / shit;

		if(choose > (infl) / shit)
			choose = infl;
		else
			choose *= shit;
	}

	return min(res , (ll) inf);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--)
	{
		int n , m;
		cin >> n >> m;

		int l = -1 , r = inf;

		while(r - l > 1)
		{
			int mid = (l + r) / 2;

			if(check(m , mid) >= n)
				r = mid;
			else
				l = mid;
		}

		cout << r << endl;
	}
}