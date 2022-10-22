#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 3e4 + 10;
int a[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = n; i >= 1; i--) a[i] -= a[i - 1];
		i64 sum = 0;
		for(int i = 1; i <= n; i++) if(a[i] < 0) sum += - a[i];
		if(a[1] < sum) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}