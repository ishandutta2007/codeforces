#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, cnt[N];
int mx;

int main() {
	cin >> n;
	while (n--) {
		int x; cin >> x;
		cnt[x]++;
		mx = max(mx, cnt[x]);
	}
	cout << mx;
}