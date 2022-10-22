#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define pi pair<int, int>
#define i64 long long
#define u64 unsigned long long
#define db double
using namespace std;
const int N = 2e5 + 10;
int T, n;
int a[N], ans[N], tot = 0;

int ask(int x) {return a[x] ^ a[x + 1] ^ a[x + 2]; }
void flip(int x) {
	if(a[x] == a[x + 1] && a[x + 1] == a[x + 2]) return;
	a[x] = a[x + 1] = a[x + 2] = a[x] ^ a[x + 1] ^ a[x + 2];
	ans[++tot] = x;
	return;
}

void solve() {
	tot = 0;
	cin >> n;
	int parity = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		parity ^= a[i];
	}
	if(parity) {
		cout << "NO" << endl;
		return; 
	}
	int pos = -1, flag = a[1] == 0;
	if(!flag) {
		for(int i = 1; i <= n - 2; i += 2) {
			if(ask(i) == 0) {
				pos = i;
				break;
			} else flip(i);
		}
	} else pos = 1;
	if(pos == -1) {
		cout << "NO" << endl;
		return;
	}
	if(!flag) {
		for(int i = pos; i >= 1; i -= 2) {
			flip(i);
		}
	}
	for(int i = pos + 1; i <= n - 2; i++) {
		if(a[i] == 0) continue;
		if(ask(i) == 0) flip(i);
		else {
			flip(i);
			flip(i - 1);
		}
	}
	flip(n - 2);
	cout << "YES" << endl;
	cout << tot << endl;
	for(int i = 1; i <= tot; i++) cout << ans[i] <<" ";
	cout << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T--; ) solve();
	return 0;
}