#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	while(n--)
	{
		ll a , b , c;
		cin >> a >> b >> c;

		b /= __gcd(a , b);
	
		while(1)
		{
			ll k = __gcd(b , c);

			if(k == 1)
				break;

			while(b % k == 0)
				b /= k;

		}

		if(b == 1)
			cout << "Finite" << endl;
		else
			cout << "Infinite" << endl;

	}

}