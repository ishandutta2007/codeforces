#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll gen(ll m, ll n, ll k) {
	ll x = min(m-1,k);
	ll y = k-x;
	return (m/(x+1)) * (n/(y+1));
}
int main()
{
	ll m, n, k, p;
	cin >> n;
	cin >> m;
	cin >> k;
	if (k > (m-1+n-1)) {
		cout << -1 << endl;
		return 0;
	}
	ll cand1 = gen(m, n, k);
	ll cand2 = gen(n, m, k);
	cout << max(cand1, cand2) << endl;
	return 0;
}