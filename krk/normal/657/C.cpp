#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const ll Inf = 9000000000000000000ll;
const int Maxn = 200005;

int n, k, b, c;
int t[Maxn];
ll cost[Maxn], val[Maxn];
ll res = Inf;

ll Solve(int md)
{
	vector <lli> V;
	for (int i = 0; i < n; i++) {
		cost[i] = (md - t[i] % 5 + 5) % 5;
		val[i] = (ll(t[i]) + cost[i]) / 5;
		cost[i] *= ll(c);
		V.push_back(lli(val[i], i));
	}
	sort(V.begin(), V.end());
	priority_queue <ll> Q;
	ll sum = 0;
	ll add = 0;
	ll res = Inf;
	ll prv = 0ll;
	for (int i = 0; i < V.size(); i++) {
		lli p = V[i];
		add += (val[p.second] - prv) * ll(b);
		if (Q.size() < k || cost[p.second] - add < Q.top()) {
			Q.push(cost[p.second] - add);
			sum += cost[p.second] - add;
		}
		if (Q.size() > k) {
			sum -= Q.top();
			Q.pop();
		}
		prv = val[p.second];
		if (Q.size() == k) 
			res = min(res, sum + ll(add) * ll(k));
	}
	return res;
}

int main()
{
	scanf("%d %d %d %d", &n, &k, &b, &c);
	b = min(b, 5 * c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		t[i] += 1000000000;
	}
	for (int i = 0; i < 5; i++)
		res = min(res, Solve(i));
	printf("%I64d\n", res);
	return 0;
}