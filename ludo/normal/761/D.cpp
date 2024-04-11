#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5;

int N, l, r;
int a[maxn], b[maxn], c[maxn], p[maxn], pi[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> l >> r;

	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		pi[--p[i]] = i;
	}

	bool valid = true;

	b[pi[0]] = l;
	c[pi[0]] = b[pi[0]] - a[pi[0]];
	for (int i = 1; i < N; i++) {
		int cur = pi[i];
		int lst = pi[i - 1];

		int minB = c[lst] + 1 + a[cur];
		int minC = c[lst] + 1;
		if (minB < l) {
			minB = l;
			minC = l - a[cur];
		}
		if (minB > r) {
			valid = false;
			break;
		}
		b[cur] = minB;
		c[cur] = minC;
	}
	if (!valid) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cout << b[i] << " \n"[i == N - 1];
	}
	/* for (int i = 0; i < N; i++) {
		cerr << c[i] << " \n"[i == N - 1];
	} */
	return 0;
}