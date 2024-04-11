#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn],b[maxn],c[maxn],n,m,cnt[maxn * 3];
vector <int> x;

#define X(i) (lower_bound(x.begin(), x.end(), i) - x.begin() + 1)

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), x.push_back(a[i]);
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) scanf("%d", &b[i]), x.push_back(b[i]);
	for(int i = 1; i <= m; ++i) scanf("%d", &c[i]), x.push_back(c[i]);
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	for(int i = 1; i <= n; ++i)
		cnt[a[i] = X(a[i])]++;
	int ans = 0, cnt1 = -1, cnt2 = -1;
	for(int i = 1; i <= m; ++i) {
		b[i] = X(b[i]), c[i] = X(c[i]);
		if(cnt1 < cnt[b[i]] || (cnt1 == cnt[b[i]] && cnt2 < cnt[c[i]])) ans = i, cnt1 = cnt[b[i]], cnt2 = cnt[c[i]];
	}
	printf("%d\n", ans);
	return 0;
}