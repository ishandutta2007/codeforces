# include <iostream>
# include <cstdio>
# include <algorithm>
# include <map>

using namespace std;

const int maxn = 52000;

int a[maxn], b[maxn];
int n, x;

map<int, int> cnt;

bool check(int limit) {
	cnt.clear();
	for(int i = 0; i < n; ++i) {
		for(x = a[i]; x > limit; x = x >> 1);
		cnt[x] += 1;
		while(x > 0 && cnt[x] > 1) { 
			cnt[x >> 1] += cnt[x] - 1;
			cnt[x] = 1;
			x = x >> 1;
		}
		if(x == 0) return false;
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	int l = n - 1, r = a[0];
	while(r-l>1) {
		int mid = l + ((r - l) >> 1);
		check(mid) ? r = mid : l = mid;
	}
	check(r);
	for(auto e:cnt) printf("%d ", e.first);
	puts("");
	return 0;
}