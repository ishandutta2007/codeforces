#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 7;

int n,k;
int a[N],t[N];
signed main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> k;
	int ans = 0;
	int upd = 0;
	for (int i = 1;i <= n;++i) cin >> a[i];
	for (int i = 1;i <= n;++i) {
		cin >> t[i];
    	if(t[i] == 0) t[i] = t[i - 1] + a[i];
    	else t[i] = t[i - 1],ans += a[i];
	}
	for (int i = k;i <= n;++i) {
		upd = max(upd,t[i] - t[i - k]); 
	}
	cout << ans + upd << endl;
}