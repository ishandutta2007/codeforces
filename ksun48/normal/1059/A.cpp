#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	LL n, L, a;
	cin >> n >> L >> a;
	LL ans = 0;
	LL last = 0;
	for(int i = 0; i < n; i++){
		LL t, l;
		cin >> t >> l;
		ans += (t - last) / a;
		last = t + l;
	}
	ans += (L - last) / a;
	cout << ans << endl;
}