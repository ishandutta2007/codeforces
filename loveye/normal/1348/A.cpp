#include<bits/stdc++.h>
using namespace std;
long long ans;
int main() {
	int kase;cin >>kase;
	while(kase--) {
		int n;cin >> n;ans = 0;
		for(int i = 1;i <= n/2;++i)
			ans += (1<<i);
		cout << ans << endl;
	}
	return 0;
}