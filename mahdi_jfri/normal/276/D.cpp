#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 5e6 + 20;
ll solve(ll l , ll r)
{
	if(l == r)
		return 0;
	return solve(l / 2 , r / 2) * 2 + 1;
}
int main()
{
	ll l , r;
	cin >> l >> r;
	cout << solve(l , r) << endl;
}