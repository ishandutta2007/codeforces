#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,a[N];
int main() {
	int t;cin >> t;
	while(t--) {
		long long sum = 0,x,ans = -1;
		cin >> n >> x;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		sort(a+1,a+n+1);
		for(int i = n;i >= 1;--i) {
			sum += a[i];
			if(sum < x*(n-i+1)) {
				ans = n-i;
				break;
			}
		}
		if(-1 == ans) ans = n;
		cout << ans << endl;
	}
	return 0;
}