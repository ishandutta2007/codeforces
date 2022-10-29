#include <bits/stdc++.h>
using namespace std;

int tc;
int n, k;
vector<int> a;
vector<vector<int> > b;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		a.clear(); a.resize(n);
		b.clear(); b.resize(n + 2);
		vector<int> ans;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b[a[i]].push_back(i + 1);
		}
		int k = 0;
		if (b[0].size() > 0) {
			int cur = 0;
			int nex = -1;
			int l = 1, r = n;
			bool kinc = false;
			while (ans.size() < n) {
				for (int i = 0; i < b[cur].size(); i++) {
					if (kinc) k++;
					if (b[b[cur][i]].size() > 0) {
						nex = b[cur][i];
					} else {
						ans.push_back(b[cur][i]);
					}
				}
				kinc = !kinc;
				if (ans.size() >= n) break;
				ans.push_back(nex);
				cur = nex;
				nex = -1;
			}
			printf("%d\n", k);
			for (int i = 0; i < ans.size(); i++) {
				if (i > 0) printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		} else {
			int cur = n+1;
			int nex = -1;
			int l = 1, r = n;
			bool kinc = true;
			while (ans.size() < n) {
				for (int i = 0; i < b[cur].size(); i++) {
					if (kinc) k++;
					if (b[b[cur][i]].size() > 0) {
						nex = b[cur][i];
					} else {
						ans.push_back(b[cur][i]);
					}
				}
				kinc = !kinc;
				if (ans.size() >= n) break;
				ans.push_back(nex);
				cur = nex;
				nex = -1;
			}
			printf("%d\n", k);
			for (int i = 0; i < ans.size(); i++) {
				if (i > 0) printf(" ");
				printf("%d", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}