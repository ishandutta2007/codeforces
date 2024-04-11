#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans = 0;
int main()
{
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	int timea = 1, timeb = 1;
	while(timea <= 100000000 && timeb <= 100000000)
	{
		if(b < d) b += a, timea ++;
		else if(d < b) d += c, timeb ++;
		else break;
	}
	if(b == d) cout << b;
	else cout << -1;
	return 0;
}