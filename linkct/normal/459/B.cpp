#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int flo[200005], n;

int main(){
	int i;
	ll ans = 0;
	ios :: sync_with_stdio(false);
	cin >> n;
	for(i = 1; i <= n; ++ i)
		cin >> flo[i];
	sort(flo + 1, flo + 1 + n);
	if(flo[1] == flo[n]){
		cout << 0 << ' ' << (ll)n * (n - 1) / 2 << endl;
		return 0;
	}
	for(i = 2; i <= n && flo[i] == flo[1]; ++ i);
	ans = i - 1;
	for(i = n - 1; i && flo[i] == flo[n]; -- i);
	ans *= n - i;
	cout << flo[n] - flo[1] << ' ' << ans << endl;
	return 0;
}