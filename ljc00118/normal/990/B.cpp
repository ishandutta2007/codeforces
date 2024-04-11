#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;
const int M = 1000000 + 10;

int f[M], a[M];
int n, k;

int main() {
	cin >> n >> k;
	int maxn = 0;
	for(int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a[tmp]++;
		maxn = max(maxn, tmp);
	}
	int ans = 0, tmp = maxn + 1;
	for(int i = maxn; i >= 1; i--) {
		if(a[i] == 0) continue;
		if(tmp > i) ans += a[i];
		tmp = i - k;
	}
	cout << ans << endl;
	return 0;
}