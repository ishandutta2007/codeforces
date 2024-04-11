#include <bits/stdc++.h>
using namespace std;

int tc;
int n;
vector<int> a;
vector<int> b, c;

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		a.clear(); a.resize(n);
		b.clear(); c.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int in;
		for (int i = 0; i < n; i++) {
			scanf("%d", &in);
			if (a[i] == 0) b.push_back(in);
			else c.push_back(in);
		}
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		long long ans = 0;
		long long sum = 0;
		if (b.size() == 0 || c.size() == 0) {
			if (c.size() == 0) swap(b, c);
			for (int i = 0; i < c.size(); i++) ans += c[i];
		} else {
			sum += b[0];
			int i1 = b.size() - 1;
			int i2 = c.size() - 1;
			bool flag = true;
			while (true) {
				if (flag) {
					if (i2 < 0) break;
					sum += 2 * c[i2];
					i2--;
				} else {
					if (i1 < 1) break;
					sum += 2 * b[i1];
					i1--;
				}
				flag = !flag;
			}
			
			for (int i = 1; i <= i1; i++) sum += b[i];
			for (int i = 0; i <= i2; i++) sum += c[i];
			ans = sum;
			sum = 0;
			swap(b, c);
			sum += b[0];
			i1 = b.size() - 1;
			i2 = c.size() - 1;
			flag = true;
			while (true) {
				if (flag) {
					if (i2 < 0) break;
					sum += 2 * c[i2];
					i2--;
				} else {
					if (i1 < 1) break;
					sum += 2 * b[i1];
					i1--;
				}
				flag = !flag;
			}
			
			for (int i = 1; i <= i1; i++) sum += b[i];
			for (int i = 0; i <= i2; i++) sum += c[i];
			ans = max(ans, sum);
		}
		
		
		printf("%lld\n", ans);
	}
	return 0;
}