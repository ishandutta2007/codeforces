#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, B = 447;
int n, a[N], cnt[N], las[N << 1];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= B; i++) {
		memset(cnt, 0, sizeof(cnt));
		int hd = 1, mx = 0;
		for(int j = 1; j <= n; j++) {
			if(cnt[a[j]] == i) mx--;
			cnt[a[j]]++;
			while(hd <= j && cnt[a[j]] > i) {
				if(cnt[a[hd]] == i) mx--;
				cnt[a[hd]]--;
				hd++;
			}
			if(cnt[a[j]] == i) mx++;
			if(mx > 1) ans = max(ans, j - hd + 1);
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	int x = 0;
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		if(cnt[i] > cnt[x]) {
			x = i, tot = 1;
		} else if(cnt[i] == cnt[x]) {
			tot++;
		}
	}
	if(tot > 1) cout << n << endl, exit(0);
	for(int i = 1; i <= n; i++) {
		if(cnt[i] <= B || x == i) continue;
		memset(las, -1, sizeof(las));
		int sum = 0;
		las[n] = 0;
		for(int j = 1; j <= n; j++) {
			if(a[j] == x) sum++;
			if(a[j] == i) sum--;
			if(las[sum + n] >= 0) ans = max(ans, j - las[sum + n]);
			else las[sum + n] = j;
		}
	}
	cout << ans << endl;
	return 0;
}