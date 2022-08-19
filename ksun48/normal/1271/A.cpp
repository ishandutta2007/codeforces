#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	using ll = long long;
	ll a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	b = min(b, c);
	if(e < f){
		swap(e, f);
		swap(a, b);
	}
	ll g = e * min(a, d);
	d -= min(a, d);
	g += f * min(b, d);
	cout << g << '\n';
}