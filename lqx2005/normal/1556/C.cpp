#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e3 + 10;
int a[N], f[N][N], g[N][N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	i64 ans = 0;
	for(int i = 1; i <= n; i += 2) {
		i64 now = 0, mn = a[i] - 1;
		for(int j = i + 1; j <= n; j += 2) {
			now += a[j - 1];
			i64 tmp = now - mn;
			if(a[j] >= tmp) {
				ans += min(mn, a[j] - tmp) + 1;
			}
			now -= a[j];
			mn = min(mn, now);
			if(now < 0) break;
		}
	}
	cout << ans << endl;
	return 0; 
}