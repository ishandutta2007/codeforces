#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 1e6 + 10;
int a[N], c[2];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		c[0] = c[1] = 0;
		cin >> n;
		for(int i = 1, x; i <= n; i++) {
			cin >> x;
			a[i] = x & 1;
			c[a[i]]++;
		}
		if(abs(c[0] - c[1]) > 1) {
			cout << -1 << endl;
			continue;
		}
		int cnt0 = 0, cnt1 = 0;
		i64 ans0 = 0, ans1 = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] == 0) {
				cnt0++;
				ans0 += abs(cnt0 * 2 - 1 - i);
			}
			if(a[i] == 1) {
				cnt1++;
				ans1 += abs(cnt1 * 2 - 1 - i);
			}
		}
		i64 ans;
		if(c[0] == c[1]) ans = min(ans0, ans1);
		else ans = c[0] < c[1] ? ans1 : ans0;
		cout << ans << endl;
	}
	return 0; 
}