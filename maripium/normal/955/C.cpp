#include<bits/stdc++.h>
using namespace std;

long long f[67];
long long binpow(long long n, int k) {
    int ans = 1;
    while(k) {
    	if(k & 1) ans = ans * n;
    	n = n * n;
    	k >>= 1;
	}
	return ans;
}

long long calc(long long n, int k) {
    if (k >= 38) return 1 + ((1LL << k) <= n);
    long long ans = floor(pow((long double)n, (long double) 1 / k)) + 1;
    while (ans && pow((long double) ans, (long double) k) > n) --ans;
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		long long l,r;
		cin >> l >> r;
		long long ans = 0;
		if(l == 1) ++l,++ans;
		for(int i = 62;i >= 2;--i) {
			f[i] = calc(r,i) - calc(l - 1,i);
			for(int j = i << 1;j <= 62;j += i) f[i] -= f[j];
			ans += f[i];
		}
		cout << ans << endl;
	}
}