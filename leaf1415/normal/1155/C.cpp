#include <iostream>
#define llint long long

using namespace std;

llint n, m;
llint x[300005], p[300005];

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= m; i++) cin >> p[i];
	
	llint g = 0, mn = 1e18+5;
	for(int i = 1; i < n; i++) g = gcd(g, x[i+1]-x[i]);
	for(int i = 1; i <= n; i++) mn = min(mn, x[i]);
	
	for(int i = 1; i <= m; i++){
		if(g % p[i] == 0){
			cout << "YES" << endl;
			cout << mn << " " << i << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}