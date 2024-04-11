#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1000 * 1000 * 10 + 1;

int a[N];
int n;
ll f[N];
ll k;

bool check(int s) {
	fill(f, f + N, 0);
	for (int i = s; i < N; i++)
		f[i] = max(1ll, f[i / 2] + f[i - i / 2]);
	ll cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += f[a[i]]; 
	return cnt >= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int lo = 0;
	int hi = N;
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	if (!lo)
		lo--;
	cout << lo << endl;
}