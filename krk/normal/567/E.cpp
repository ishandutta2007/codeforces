#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 100005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const ll Inf = 1000000000000000000ll;

int n, m, s, t;
int a[Maxn], b[Maxn], l[Maxn];
vector <llll> neigh[Maxn], rneigh[Maxn];
ll dist1[Maxn], dist2[Maxn];
llll ways1[Maxn], ways2[Maxn];

void Dijkstra(int s, const vector <llll> neigh[], ll dist[], llll ways[])
{
	fill(dist, dist + n + 1, Inf); dist[s] = 0;
	ways[s] = llll(1, 1);
	priority_queue <llll> Q; Q.push(llll(-dist[s], s));
	while (!Q.empty()) {
		ll v = Q.top().second, d = -Q.top().first; Q.pop();
		if (dist[v] != d) continue;
		for (int i = 0; i < neigh[v].size(); i++) {
			llll u = neigh[v][i];
			if (d + u.second < dist[u.first]) {
				dist[u.first] = d + u.second; ways[u.first] = llll(0, 0);
				Q.push(llll(-dist[u.first], u.first));
			}
			if (d + u.second == dist[u.first]) {
				ways[u.first].first = (ways[u.first].first + ways[v].first) % mod1;
				ways[u.first].second = (ways[u.first].second + ways[v].second) % mod2;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &l[i]);
		neigh[a[i]].push_back(llll(b[i], l[i]));
		rneigh[b[i]].push_back(llll(a[i], l[i]));
	}
	Dijkstra(s, neigh, dist1, ways1);
	Dijkstra(t, rneigh, dist2, ways2);
	ll res = dist1[t];
	for (int i = 0; i < m; i++)
		if (dist1[a[i]] + l[i] + dist2[b[i]] == res &&
			ll(ways1[a[i]].first) * ways2[b[i]].first % mod1 == ways1[t].first &&
			ll(ways1[a[i]].second) * ways2[b[i]].second % mod2 == ways1[t].second)
			printf("YES\n");
		else {
			ll x = res - dist1[a[i]] - dist2[b[i]] - 1;
			if (x > 0) printf("CAN %I64d\n", l[i] - x);
			else printf("NO\n");
		}
	return 0;
}