# include <iostream>
# include <cstdio>
# include <functional>
# include <algorithm>
# include <set>

using namespace std;

const int maxn = 200010;
const int inf = ~0U>>1;

pair<int,int> a[maxn]; 

set<int, greater<int> > L; 
set<int, less<int> > R; 

int ans[maxn];

int main() {
	int n, j; scanf("%d", &n);

	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);

	L.insert(0); L.insert(n + 1);
	R.insert(0); R.insert(n + 1);

	for(int i = 1; i <= n; i = j) {
		for(j = i; j <= n && a[j].first == a[i].first; ++j) {
			int len = *R.upper_bound(a[j].second) - *L.upper_bound(a[j].second) - 1;
			//cout << len << endl;
			ans[len] = max(ans[len], a[j].first);
		}
		for(j = i; j <= n && a[j].first == a[i].first; ++j) {
			L.insert(a[j].second);
			R.insert(a[j].second);
		}
	}

	for(int i = n-1; i > 0; --i) {
		ans[i] = max(ans[i], ans[i + 1]);
	}

	for(int i = 1; i <= n; ++i) {
		printf("%d%c",ans[i], " \n"[i==n]);
	}
}