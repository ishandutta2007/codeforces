#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef double db;
typedef long long i64;
const int N = 5e5 + 10, P = 1e9 + 7;

struct Modint {
	int x;
	Modint() {x = 0; }
	Modint(i64 X) {x = (X % P + P) % P; }
	friend Modint operator + (const Modint a, const Modint b) {
		return Modint((a.x + b.x) % P);
	} 
	friend Modint operator - (const Modint a, const Modint b) {
		return Modint((a.x - b.x + P) % P);
	} 
	friend Modint operator * (const Modint a, const Modint b) {
		return Modint(1ll * a.x * b.x % P);
	}
	friend void operator += (Modint &a, const Modint b) {
		a = a + b;
	}
	friend void operator -= (Modint &a, const Modint b) {
		a = a - b;
	}
	friend void operator *= (Modint &a, const Modint b) {
		a = a * b;
	}
};
int n, x[N], y[N];
i64 cr[N];

i64 cross(int a, int b) {
	return 1ll * x[a] * y[b] - 1ll * x[b] * y[a];
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	i64 sum = 0, now = 0;
	Modint csum = 0, xsum = 0, ysum = 0, ans = 0;
	for(int i = 0; i < n; i++) cr[i] = cross((i + 1) % n, i), sum += cr[i];
	for(int i = 0, j = 0; i < n; i++) {
		while((j + 1) % n != i && (now + cr[j] + cross(i, (j + 1) % n)) <= (sum - 1) / 2) {
			now += cr[j];
			j = (j + 1) % n;
			csum += now;
			xsum += x[j], ysum += y[j];
		}
		int cnt = (j - i + n) % n;
		ans += cnt * Modint(sum);
		ans -= csum * 2;
		ans -= (x[i] * ysum - xsum * y[i]) * 2;
		csum -= cnt * Modint(cr[i]);
		now -= cr[i];
		xsum -= x[(i + 1) % n];
		ysum -= y[(i + 1) % n];
	}
	ans -= Modint(sum) * n;
	cout << ans.x << endl;
    return 0;
}