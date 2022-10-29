#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > ans;

void setup(int l, int r) {
	if (l == r) {
		return;
	}
	int m = (l + r)/2;
	setup(l, m);
	setup(m+1, r);
	for (int i = l; i <= m; i++) {
		ans.push_back(make_pair(i, i+(m-l)+1));
	}
}

vector<int> ind;

void setup2(int l, int r) {
	if (l == r) {
		return;
	}
	int m = (l + r)/2;
	setup(l, m);
	setup(m+1, r);
	for (int i = l; i <= m; i++) {
		ans.push_back(make_pair(ind[i], ind[i+(m-l)+1]));
	}
}

int main() {
	scanf("%d", &n);
	int twos = 1;
	while (twos <= n) {
		twos *= 2;
	}
	twos /= 2;
	setup(1, twos);
	setup(n-twos+1, n);
	/*vector<int> a, b; 
	int sum = 1;
	while (n > 0) {
		if (n >= twos) {
			n -= twos;
			a.push_back(twos);
			b.push_back(sum);
			sum += twos;
		}
		twos/=2;
	}
	n = sum - 1;
	for (int i = 0; i < a.size(); i++) {
		setup(b[i], b[i] + a[i] - 1);
	}
	if (a.size() > 2) {
		int sz = a.size();
		for (int i = b[sz-1]; i <= b[sz-1] + a[sz-1] - 1; i++) {
			
		}
		for (int i = a.size() - 1; i >= 1; i--) {
			
		}
	}*/
	
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}