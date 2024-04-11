#include <iostream>
using namespace std;
typedef long long int ll;

ll lft, a, b, n, t, m;

inline ll get(ll l, ll r){
	return (a + (l - 1) * b + a + (r - 1) * b) * (r - l + 1) / 2;
}
int main(){
	ll l, r, mid;
	cin >> a >> b >> n;
	for(int i = 1; i <= n; ++ i){
		cin >> lft >> t >> m;
		l = 1, r = t / b + 1;
		while(l < r){
			mid = (l + r + 1) >> 1;
			if(a + (mid - 1) * b <= t) l = mid;
			else r = mid - 1;
		}
		if(a + (r - 1) * b > t) r = -1;
		l = 1;
		while(l < r){
			mid = (l + r + 1) >> 1;
			if(get(lft, mid) <= m * t) l = mid;
			else r = mid - 1;
		}
		if(r < lft || get(lft, r) > m * t) cout << -1 << endl;
		else cout << r << endl;
	}
	return 0;
}