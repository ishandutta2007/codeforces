#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin >> t;
	while(t--) {
		int n,res = 0,_ = 1,now = 1,del;cin >> n;
		while(_ <= n) res++,_ <<= 1;
		--res;
		cout << res << endl;n -= res+1;
		for(int i = 1;i <= res;++i) {
			del = min(now,n / (res-i+1));
			n -= (res-i+1) * del;
			now += del;
			cout << del << ' ';
		}
		cout << endl;
	}
	return 0;
}