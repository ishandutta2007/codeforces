# include <bits/stdc++.h>
using namespace std;

int a[200010];
int s[200010];

set<int> S;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(a[i] == 0) {
			a[i] = (i == 1) ? 1 : a[i-1];
			S.insert(i);
		}
		s[a[i]] += 1;
	}
	if(s[m] == 0) {
		if(S.empty()) {
			puts("NO"); return 0;
		}
		int k = *S.begin();
		s[a[k]] -= 1;
		a[k] = m;
		s[a[k]] += 1;
	}
	S.clear();
	for(int i = 1; i <= n; ++i) {
		s[a[i]] -= 1;
		if(s[a[i]] == 0) {
			if(S.count(a[i])) S.erase(a[i]);
		} else {
			if(!S.count(a[i])) S.insert(a[i]);
		}
		int mx = S.empty() ? 0 : *S.rbegin();
		if(mx > a[i]) {
			puts("NO"); return 0;
		}
	}
	puts("YES");
	for(int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i==n]);
	return 0;
}