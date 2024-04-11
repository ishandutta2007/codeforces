#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int n,a[N];
int lfact[N],rfact[N];

int calc(int x) {
    return (lfact[n - x - 1] * rfact[n - x + 1]) % mod;
}
signed main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> a[i];
	sort(a + 1,a + n + 1);
	lfact[0] = rfact[n + 1] = 1;
	for(int i = 1;i <= n + 1;++i) lfact[i] = (lfact[i - 1] * i) % mod;
	for(int i = n;i >= 0;--i) rfact[i] = (rfact[i + 1] * i) % mod;
	int ans = 0, cur = 0,cnt = 0;
	for(int i = 1;i <= n && a[i] != a[n];++i) {
		if(a[i] == a[i - 1]) ++cnt;
		else cur += cnt ,cnt = 1;
		ans = (ans + a[i] * calc(cur)) % mod;
	}
	
	cout << ans << endl;
}