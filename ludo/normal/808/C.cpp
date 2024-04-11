#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back

const int maxn = 100;

ll n, w, a[maxn], p[maxn];
pii idx[maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) idx[i] = pii(a[i], i);
	sort(idx, idx + n);

	ll lst = -1;
	for (int i = 0; i < n; i++) {
		int v = idx[i].x, j = idx[i].y;
		ll cur = (v + 1) / 2;
		w -= cur;
		p[j] = lst = cur;
	}

	if (w < 0) {
		cout << "-1\n";
		return 0;
	}

	ll lastPour = 1e9;
	for (int i = n - 1; i >= 0 && w > 0; i--) {
		int j = idx[i].y;
		ll curPour = min(a[j], p[j] + w);
		curPour = min(curPour, lastPour);

		int add = curPour - p[j];
		w -= add;
		p[j] += add;
		lastPour = curPour;

		if (i > 0 && idx[i].x != idx[i - 1].x) lastPour--;
	}

	for (int i = 0; i < n; i++) {
		cout << p[i] << " \n"[i == n - 1];
	}
	return 0;
}