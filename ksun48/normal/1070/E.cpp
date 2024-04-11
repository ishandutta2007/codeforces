#include <bits/stdc++.h>
using namespace std;

#define N 210000

int n, m;
long long t;
bool in[N];
int p[N], tx[N];
int best_d;

bool cmp(int x, int y) {
	return p[x] < p[y];
}

long long calc(int mm) {
	long long ans = 1e18;
	
	int m1, m2;
	if (mm == 0) {
		best_d = 1;
		return 0;
	}
	if (mm % m == 0) {
		m1 = mm - m;
	}else {
		m1 = mm / m * m;
	}
	m2 = mm;

	int now1 = n;
	int now2 = n;
	
	int s1 = 0, s2 = 0;
	long long sum1 = 0, sum2 = 0;
	
	for (int i = 1; i <= n; i++)
		in[i] = false;

	for (int i = 1; i <= n; i++) {
		int h = i;
		while (h < n && p[tx[h + 1]] == p[tx[i]])
			h++;
		for (int j = i; j <= h; j++) {
			if (tx[j] <= now1) {
				s1++;
				sum1 += p[tx[j]];
			}
			
			if (tx[j] <= now2) {
				s2++;
				sum2 += p[tx[j]];
			}
			in[tx[j]] = true;
		}
		while (s1 > m1) {
			if (in[now1]) {
				s1--;
				sum1 -= p[now1];
			}
			now1--;
		}

		while (s2 > m2) {
			if (in[now2]) {
				s2--;
				sum2 -= p[now2];
			}
			now2--;
		}
		
		if (s1 == m1 && s2 == m2) {
			if (sum1 + sum2 < ans) {
				ans = sum1 + sum2;
				best_d = p[tx[i]];
			}
		}
		i = h;
	}

	return ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		cin >> n >> m >> t;
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		for (int i = 1; i <= n; i++)
			tx[i] = i;
		sort(tx + 1, tx + n + 1, cmp);
		
		int l = 0, r = n + 1;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (calc(mid) <= t)
				l = mid;
			else
				r = mid;
		}
		calc(l);
		printf("%d %d\n", l, best_d);
	}
}