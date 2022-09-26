#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
void solve1() {
	if (n <= 5) {
		cout << -1 << endl;
		return;
	}
	cout << 1 << ' ' << 2 << endl;
	cout << 2 << ' ' << 3 << endl;
	cout << 2 << ' ' << 4 << endl;
	for (int i = 5;i <= n;++i) cout << 1 << ' ' << i << endl;
}

void solve2() {
	for (int i = 1;i < n;++i) cout << i << ' ' << i + 1 << endl;
}
int main() {
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cin >> n;
	solve1();
	solve2();
}