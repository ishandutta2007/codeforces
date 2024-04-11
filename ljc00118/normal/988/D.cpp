#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

map <int, int> f;

int a[N];
int n, ans = 0;

int main() {
	int maxn = -23333333, minn = 23333333;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		minn = min(minn, a[i]), maxn = max(maxn, a[i]);
		f[a[i]]++;
	}
	sort(a + 1, a + n + 1); 
	for(int i = 1; i <= n; i++) {
		int tmp = f[a[i]];
		ans = max(ans, tmp + f[a[i] + 1]);
		for(int j = 2; j + a[i] <= maxn; j <<= 1) ans = max(ans, tmp + f[a[i] + j] + f[a[i] + (j >> 1)]);
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		int tmp = f[a[i]];
		if(tmp + f[a[i] + 1] == ans) {
			for(int j = 1; j <= f[a[i]]; j++) printf("%d ", a[i]);
			for(int j = 1; j <= f[a[i] + 1]; j++) printf("%d ", a[i] + 1);
			return 0;
		}
		for(int j = 2; j + a[i] <= maxn; j <<= 1) {
			if(ans == tmp + f[a[i] + j] + f[a[i] + (j >> 1)]) {
				for(int k = 1; k <= f[a[i]]; k++) printf("%d ", a[i]);
				for(int k = 1; k <= f[a[i] + j / 2]; k++) printf("%d ", a[i] + j / 2);
				for(int k = 1; k <= f[a[i] + j]; k++) printf("%d ", a[i] + j);
				return 0;
			}
		}
	}
	if(ans == 1) cout << a[1];
	return 0;
}