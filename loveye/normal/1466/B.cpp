#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,T,a[N];
int main() {
	cin >> T;
	while(T--) {
		cin >> n;
		int ans = 0;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		a[n+1] = 0;
		for(int i = 1;i <= n;++i) {
			if(a[i] != a[i-1]) ++ans;
			else if(a[i] != a[i+1]) ++a[i],++ans;
		}
		cout << ans << endl;
	}
	return 0;
}