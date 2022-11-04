#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll x[100100], y[100100];

void solve(){
	cin >> n;


	int c1 = 0, c2 = 0;
	for(int i=1;i<=2*n;i++){
		ll a, b; cin >> a >> b;
		if(b == 0) x[c1++] = a*a;
		if(a == 0) y[c2++] = b*b;
	}

	sort(x, x+n), sort(y, y+n);

	double ans = 0;
	for(int i=0;i<n;i++) ans += sqrt(x[i] + y[i]);
	cout << ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed;
	cout.precision(10);

	int tc = 1; cin >> tc;
	while(tc--) solve(), cout << "\n";
}