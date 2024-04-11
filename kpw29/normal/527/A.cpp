#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;

ll query(ll a, ll b)
{
	if (a < b) swap(a,b);
	if (b == 0) return 0;
	return a/b + query(a%b, b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	cout << query(a,b);
}