#include <iostream>
#include <cmath>
typedef long long int ll;
using namespace std;

ll n, a, b;

int main(){
	bool sign = false;
	ll ans = 1LL << 50, ansa, ansb;
	cin >> n >> a >> b;
	n *= 6LL;
	if(a > b) swap(a, b), sign = true;
	if(a * b >= n){
		cout << a * b << endl << a << ' ' << b << endl;
		return 0;
	}
	ll limit = ceil(sqrt((double)n));
	for(; a <= limit; ++ a){
		ll b_ = ceil((double)n / a);
		if(b_ < b) break;
		if(a * b_ < ans) ans = a * b_, ansa = a, ansb = b_;
	}
	if(sign && ansb > ansa) swap(ansb, ansa);
	cout << ans << endl << ansa << ' ' << ansb << endl;
	return 0;
}