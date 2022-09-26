#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int m, k, n, s;
int a[N];
int b[N];
int cnt[N];
int now[N];
int nxt[N];
vector<int> vpos[N];

int main() {
	scanf("%d %d %d %d", &m, &k, &n, &s);
	
	for (int i = 1; i <= m; ++i) {
		scanf("%d", a + i);
		vpos[a[i]].push_back(i);
	}
	
	for (int i = 1; i <= s; ++i) {
		scanf("%d", b + i);
		++cnt[b[i]];
	}
	
	int ptr = k;
	for (int i = 1; i < N; ++i) {
		if (vpos[i].size() < cnt[i]) {
			puts("-1");
			return 0;
		} 
		if (cnt[i]) {
			ptr = max(ptr, vpos[i][cnt[i] - 1]);
		}
	}
	nxt[1] = ptr;
	for (int i = 1; i <= ptr; ++i) {
		++now[a[i]];
	}
	
	for (int i = 2; i <= m; ++i) {
		--now[a[i - 1]];
		while (ptr < m && (now[a[i - 1]] < cnt[a[i - 1]] || ptr - i + 1 < k)) {
			++ptr;
			++now[a[ptr]];
		}
		if (now[a[i - 1]] >= cnt[a[i - 1]] && ptr - i + 1 >= k) {
			nxt[i] = ptr;
		} else {
			break;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		if (nxt[i]) {
			int l = (i - 1) / k;
			int r = (m - nxt[i]) / k;
			if (l + r + 1 < n) {
				continue;
			}
			vector<int> ans;
			for (int j = l * k + 1; j <= i - 1; ++j) {
				ans.push_back(j);
			}
			for (int j = nxt[i] + 1; j <= m - r * k; ++j) {
				ans.push_back(j);
			}
			multiset<pair<int,int>> avail;
			for (int j = i; j <= nxt[i]; ++j) {
				avail.insert(make_pair(a[j], j));
			}
			for (int j = 1; j <= s; ++j) {
				auto it = avail.lower_bound(make_pair(b[j], 0));
				assert(it->first == b[j]);
				avail.erase(it);
			}
			
			vector<pair<int,int>> to(avail.begin(), avail.end());
			for (int j = k - s; j < to.size(); ++j) {
				ans.push_back(to[j].second);
			}
			sort(ans.begin(), ans.end());
			
			printf("%d\n", (int) ans.size());
			
			for (int v : ans) {
				printf("%d ", v);
			}
			return 0;
		}
	}
	puts("-1");
}