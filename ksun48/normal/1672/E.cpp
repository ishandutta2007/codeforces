#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	auto ask = [&](int l) -> int {
		cout << "? " << l << '\n';
		cout << flush;
		int res;
		cin >> res;
		return res;
	};
	int s = 0;
	int e = 5e6;
	while(s + 1 < e){
		int m = (s + e) / 2;
		if(ask(m) == 1){
			e = m;
		} else {
			s = m;
		}
	}
	int ans = e;
	for(int i = 2; i <= n; i++){
		int f = (e-1) / i;
		if(f > 0){
			int r = ask(f);
			if(r){
				ans = min(ans, r * f);
			}
		}
	}
	cout << "! " << ans << '\n';
	cout << flush;
}