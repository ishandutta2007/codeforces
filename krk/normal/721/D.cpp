#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;

ll n, k, x;
ll a[Maxn];
int ind[Maxn];

bool Less(const int &i, const int &j) { return abs(a[i]) < abs(a[j]); }

int main()
{
	scanf("%I64d %I64d %I64d", &n, &k, &x);
	int hm = 0, mnind = 0;
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
		hm += a[i] < 0;
		if (abs(a[i]) < abs(a[mnind])) mnind = i;
	}
	if (hm % 2 == 0) {
		ll tk = abs(a[mnind]) / x + 1;
		if (tk <= k) {
			if (a[mnind] < 0) { a[mnind] += tk * x; hm--; }
			else { a[mnind] -= tk * x; hm++; }
			k -= tk;
		}
	}
	if (hm % 2 == 0) {
		for (int i = 0; i < n; i++)
			ind[i] = i;
		sort(ind, ind + n, Less);
		for (int i = 0; i < n; i++) {
			ll tk = min(ll(abs(a[ind[i]]) / x), k);
			if (a[ind[i]] < 0) a[ind[i]] += tk * x;
			else a[ind[i]] -= tk * x;
			k -= tk;
		}
	} else {
		priority_queue <lli> Q;
		for (int i = 0; i < n; i++)
			Q.push(lli(-abs(a[i]), i));
		while (!Q.empty() && k) {
			int ind = Q.top().second; Q.pop();
			if (a[ind] < 0) a[ind] -= x;
			else a[ind] += x;
			k--;
			Q.push(lli(-abs(a[ind]), ind));
		}
	}
	for (int i = 0; i < n; i++)
		printf("%I64d%c", a[i], i + 1 < n? ' ': '\n');
	return 0;
}