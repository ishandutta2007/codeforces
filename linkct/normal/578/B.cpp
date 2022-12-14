#include <iostream>
using namespace std;
const int MAXN = 200005;
typedef long long int ll;

ll a[MAXN], x, pf[MAXN], sf[MAXN];
int n, k;

int main(){
	int i; ll ans = 0LL, base = 1LL;
	cin >> n >> k >> x;
	for(i = 1; i <= n; ++ i) cin >> a[i];
	for(i = 1; i <= k; ++ i) base *= x;
	for(i = 1; i <= n; ++ i) pf[i] = pf[i - 1] | a[i];
	for(i = n; i; -- i) sf[i] = sf[i + 1] | a[i];
	for(i = 1; i <= n; ++ i)
		ans = max(ans, pf[i - 1] | sf[i + 1] | (a[i] * base));
	cout << ans << endl;
	return 0;
}