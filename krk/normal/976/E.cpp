#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

ll res;
int n, a, b;
int hp[Maxn], dmg[Maxn];
vector <ii> seq;
bool tk[Maxn];
ll cur;

int main()
{
	scanf("%d %d %d", &n, &a, &b); b = min(b, n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &hp[i], &dmg[i]);
		cur += dmg[i];
		seq.push_back(ii(max(0, hp[i] - dmg[i]), i));
	}
	sort(seq.rbegin(), seq.rend());
	for (int i = 0; i < b; i++) {
		cur += seq[i].first;
		tk[seq[i].second] = true;
	}
	res = cur;
	if (b == 0) { printf("%I64d\n", res); return 0; }
	for (int i = 0; i < n; i++) {
		ll cand = cur;
		if (tk[i]) {
			cand -= max(hp[i], dmg[i]);
			ll nhp = hp[i];
			for (int j = 0; j < a; j++)
				nhp *= 2ll;
			cand += max(nhp, ll(dmg[i]));
		} else {
			cand -= dmg[i];
			cand -= seq[b - 1].first;
			ll nhp = hp[i];
			for (int j = 0; j < a; j++)
				nhp *= 2ll;
			cand += max(nhp, ll(dmg[i]));
		}
		res = max(res, cand);
	}
	cout << res << endl;
	return 0;
}