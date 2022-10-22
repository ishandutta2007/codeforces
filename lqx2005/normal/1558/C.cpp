#include<bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define pi pair<int, int> 
#define vi vector<int>
#define db double
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 4e6 + 10;
int T, n, a[N], ans[N], tot = 0;

void rev(int x) {
	reverse(a + 1, a + x + 1);
	ans[++tot] = x;
	return ;
}

void solve() {
	tot = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if((a[i] - i) & 1) {
			cout << -1 << endl;
			return;
		}
	}
	for(int i = n; i >= 3; i -= 2) {
		int p1 = -1, p2 = -1;
		for(int j = 1; j <= i; j++) {
			if(a[j] == i) p1 = j;
		}
		rev(p1);
		for(int j = 1; j <= i; j++) {
			if(a[j] == i - 1) p2 = j;
		}
		rev(p2 - 1);
		rev(p2 + 1);
		rev(3);
		rev(i);
	}
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) cout << ans[i] <<" ";
	cout << endl;
	for(int i = 1; i <= n; i++) assert(a[i] == i);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T--; ) solve();
	return 0;
}