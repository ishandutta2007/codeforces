#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll a, b, c;
	cin >> a >> b >> c;
	if(a > b + 1) a = b + 1;
	if(b > a + 1) b = a + 1;
	ll ans = c + c + a + b;
	cout << ans << '\n';
}