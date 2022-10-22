#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n, x;
llint a[1000005];
llint r[1000005];
set<llint> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint lmin = x+1, lmax = -1, rmin = x+1, rmax = -1;
	for(int i = 1; i <= n; i++){
		auto p = S.upper_bound(a[i]);
		if(p != S.end()){
			auto q = S.end(); q--;
			lmax = max(lmax, a[i]);
			lmin = min(lmin, a[i]);
			rmax = max(rmax, *q);
			rmin = min(rmin, *p);
			r[a[i]] = *q;
		}
		S.insert(a[i]);
	}
	if(lmax == -1){
		cout << x*(x+1)/2 << endl;
		return 0;
	}
	
	llint ans = 0, R = lmax;
	ans += lmin * (x-lmax+1);
	for(int i = lmin+1; i <= rmin; i++){
		if(r[i-1] > 0) R = max(R, r[i-1]);
		ans += x-R+1;
	}
	cout << ans << endl;
	
	return 0;
}