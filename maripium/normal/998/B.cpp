#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i, l, r) for (int i = (l); i <= (r); ++i)
#define Ford(i, r, l) for (int i = (r); i >= (l); --i) 
using namespace std;

const int N = 105;

int n, b;
int a[N], prf[N];
int f[N][N][2];
 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> b;
	vector<int> vec;
	For(i, 1, n) {
		cin >> a[i];
		if (a[i] & 1) prf[i] = prf[i - 1] + 1;
		else prf[i] = prf[i - 1] - 1;
	}
	For(i, 1, n - 1) if (!prf[i]) {
		vec.pb(abs(a[i + 1] - a[i]));
	}
	sort(vec.begin(), vec.end());
	int cnt = 0, sum = 0;
	for (int x : vec) {
		if (sum + x > b) break;
		sum += x;
		cnt++; 
	}
	cout << cnt;
}