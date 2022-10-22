#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 1e5 + 10;
int n, a[N];
LL k;

void work() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) a[i] = i;
	int m = min(n, 61);
	if((1ll << (m - 1)) < k) return cout << -1 << endl, void();
	k--;
	for(int i = n - m; k && i < n; ) {
		int pos = n;
		for(int j = n - i; j >= 2; j--) {
			if((1ll << (j - 2)) <= k) {
				k -= 1ll << (j - 2);
			} else {
				pos = n - j + 1;
				break;
			}
		}
		reverse(a + i + 1, a + pos + 1);
		i = pos;
	}
	for(int i = 1; i <= n; i++) cout << a[i] <<" ";
	cout << endl;
	return;
}

int main() {
	int T;
	cin >> T;
	for(; T--; work());	
	return 0;
}