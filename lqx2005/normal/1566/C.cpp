#include <bits/stdc++.h>
#define i64 long long
#define db double
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
int T, n;
int used[N];
string a, b;
int main() {
	cin >> T;
	for(; T--; ) {
		cin >> n;
		for(int i = 0; i < n; i++) used[i] = 0;
		cin >> a >> b;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] != b[i]) {
				used[i] = 1;
				ans += 2;
			}
		}
		for(int i = 0; i < n; i++) {
			if(!used[i]) {
				if(i - 1 >= 0 && !used[i - 1] && a[i] != a[i - 1]) used[i - 1] = used[i] = 1, ans += 2;
				else if(i + 1 < n && !used[i + 1] && a[i] != a[i + 1]) used[i] = used[i + 1] = 1, ans += 2;
				else if(a[i] == '0') ans++, used[i] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}