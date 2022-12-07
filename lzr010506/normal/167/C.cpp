#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(ll a, ll b) 
{
	if(a > b) return solve(b, a);
	if(a == 0) return 0;
	if(!solve(b % a, a)) return 1;
	return ((b / a) % (a + 1)) & 1 ^ 1;
}

int main() 
{
	int T;
	cin >> T;
	while(T --) 
	{
		ll a, b;
		cin >> a >> b;
		cout << (solve(a, b) ? "First" : "Second") << '\n';
	}
	return 0;
}