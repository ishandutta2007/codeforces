#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100005;
typedef long long int ll;

int num[MAX], n, x;

int main(){
	int i; ll ans = 0;
	cin >> n >> x;
	for(i = 1; i <= n; ++ i) cin >> num[i];
	sort(num + 1, num + 1 + n);
	for(i = 1; i <= n; ++ i){
		ans += (ll)num[i] * x;
		x = x > 1 ? x - 1 : 1;
	}
	cout << ans << endl;
	return 0;
}