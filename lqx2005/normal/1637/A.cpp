#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) int((a).size())
#define vi vector<int>
typedef long long ll;
const int N = 1e4 + 10;
int n, a[N];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int flag = 0;
	for(int i = 2; i <= n; i++) if(a[i - 1] > a[i]) flag = 1;
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}