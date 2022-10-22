#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

llint n;
llint a[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
	
	llint z = 0;
	for(int i = 1; i <= n; i++) z = gcd(z, mx-a[i]);
	
	llint y = 0;
	for(int i = 1; i <= n; i++) y += (mx-a[i]) / z;
	cout << y << " " << z << endl;
	
	return 0;
}