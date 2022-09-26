#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int solve(vector<int> a) {
	int now = 0;
	int cnt = 0;
	vector<int> na;
	for (int v : a) {
		if (v == 0) {
			++cnt;
		} else {
			na.push_back(v);
		}
	}
	a.swap(na);
	for (int i = 0; i < 30; ++i) {
		if (now == a.size()) {
			break;
		}
		bool found = false;
		for (int j = now; j < int(a.size()); ++j) {
			if ((a[j] >> i) & 1) {
				swap(a[j], a[now]); 
				found = true;
				break;
			}
		}
		if (found) {
			for (int j = now + 1; j < int(a.size()); ++j) {
				if ((a[j] >> i) & 1) {
					a[j] ^= a[now];
					if (a[j] == 0) {
						++cnt;
					}
				}
			}
			++now;
		}
	}
	return cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
	}
	if (a[n] == 0) {
		puts("-1");
		return 0;
	} else {
		reverse(a.begin(), a.end());
		a.pop_back();
		printf("%d\n", n - solve(a));
	}
}