#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second


#define N 201111

int n, K;
int p[N], last[N];
vector <int> a;
int main() {
	read(n); read(K);
	for (int i = 1; i <= n; i++) read(p[i]);
	LL ans = 0;
	for (int i = 1 ;i <= n; i++) {
		if (p[i] >= n - K + 1) {
			ans += p[i];
			p[i] = 1;
			a.push_back(i);
		}else {
			p[i] = 0;
		}
	}
	LL p = 1;
	for (int i = 1; i < (int)a.size(); i++) {
		p = p * (a[i] - a[i - 1]) % 998244353;
	}
	cout << ans << " " << p << endl;
}