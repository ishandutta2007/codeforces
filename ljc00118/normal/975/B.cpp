#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a[24], b[24];
LL ans = 0;

int main() {
	for(int i = 1; i <= 14; i++) cin >> a[i];
	for(int i = 1; i <= 14; i++) if(a[i] % 2 == 0) ans += a[i];
	for(int i = 1; i <= 14; i++) {
		for(int j = 1; j <= 14; j++) {
			if(i == j) b[j] = a[i] / 14;
			else b[j] = a[j] + a[i] / 14;
		}
		LL tmp = a[i] % 14, u = i % 14 + 1;
		while(tmp) {
			b[u]++;
			tmp--;
			u = u % 14 + 1;
		}
		LL co = 0;
		for(int j = 1; j <= 14; j++) if(b[j] % 2 == 0) co += b[j];
		ans = max(ans, co);
	}
	cout << ans;
	return 0;
}