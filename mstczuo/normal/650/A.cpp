# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstring>
# include <algorithm>
using namespace std;

typedef long long ll;

int n;
typedef pair<int,int> pii;

pii a[200010];

bool cmp2(const pii&a,const pii&b) {
	return pii(a.second, a.first) < pii(b.second, b.first);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	ll ans = 0;
	for(int i = 0, j; i < n; i = j) {
		for(j = i; j < n && a[j].first == a[i].first; ++j) {
			ans += j - i;
		}
	}
	for(int i = 0, j; i < n; i = j) {
		for(j = i; j < n && a[j] == a[i]; ++j) {
			ans -= j - i;
		}
	}
	sort(a, a + n, cmp2);
	for(int i = 0, j; i < n; i = j) {
		for(j = i; j < n && a[j].second == a[i].second; ++j) {
			ans += j - i;
		}
	}
	cout << ans << endl;
}