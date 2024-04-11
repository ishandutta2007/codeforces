#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
int a[N];
int p[N];
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	int cnt = 0;
	for (int i = 1;i <= n;++i) {
		if (i == p[i]) continue;
		int pp = p[i];
		swap(a[i], a[pp]);
		p[a[i]] = i;
		p[a[pp]] = pp;
		cnt++;
	}
	if ((n - cnt) & 1) cout << "Um_nik";
	else cout << "Petr";
}