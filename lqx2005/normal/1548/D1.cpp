#include <bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 6000 + 10;
int n, x[N], y[N];
int cnt[2][2];

int Gcd(int x, int y) {
	return !(x % 2 == 0 && y % 2 == 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		x[i] /= 2, y[i] /= 2;
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i++) {
		memset(cnt, 0, sizeof(cnt));
		for(int j = 1; j < i; j++) {
			int g = Gcd(x[i] - x[j], y[i] - y[j]);
			for(int k = 0; k < 2; k++) {
				for(int l = 0; l < 2; l++) {
					if(g == (Gcd(x[i] - k, y[i] - l) ^ Gcd(x[j] - k, y[j] - l))) {
						ans += cnt[k][l];
					}
				}
			}
			cnt[x[j] & 1][y[j] & 1]++;
		}
	}
	cout << ans << endl;
    return 0;
}