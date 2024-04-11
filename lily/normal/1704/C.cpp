#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


const int N = 1e5 + 5;

int n, m;
int a[N];

void work() {
	read(n); read(m);
	for (int i = 0; i < m; i++) read(a[i]), a[i]--;
	sort(a, a + m);
	vector <int> w;
	for (int i = 0; i < m; i++) if ((a[i] + 1) % n != a[(i + 1) % m]) {
		w.push_back((a[(i + 1) % m] + n - a[i] - 1) % n);
	}
	sort(w.begin(), w.end(), greater<int>());
	int days = 0, ans = 0;
	for (auto i : w) {
		if (days * 2 >= i) break;
		ans += 1;
		days ++;
		if (days * 2 >= i) break;
		ans += i - days * 2;
		days++;
	}
	printf("%d\n", n - ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}