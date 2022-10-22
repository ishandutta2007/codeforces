#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 300005;
const ll Inf = 1000000000000000000ll;

int T;
int n, m;
int X[Maxn];
char str[Maxn];
ii my[Maxn];
ll res[Maxn];

ll getDist(int a, int b)
{
	a = my[a].second;
	b = my[b].second;
	if (str[a] == 'L' && str[b] == 'L')
		return X[a] + (X[b] - X[a]) / 2;
	if (str[a] == 'L' && str[b] == 'R')
		return (X[a] + m - X[b] + m) / 2;
	if (str[a] == 'R' && str[b] == 'L')
		return (X[b] - X[a]) / 2;
	if (str[a] == 'R' && str[b] == 'R')
		return m - X[b] + (X[b] - X[a]) / 2;
	return 0;
}

void Solve(int d)
{
	set <int> S;
	vector <int> seq;
	for (int i = 0; i < n; i++)
		if (X[my[i].second] % 2 == d) {
			S.insert(i);
			seq.push_back(i);
		}
	priority_queue <llii> Q;
	for (int i = 0; i + 1 < seq.size(); i++)
		Q.push(llii(-getDist(seq[i], seq[i + 1]), ii(seq[i], seq[i + 1])));
	while (!Q.empty()) {
		ll dist = -Q.top().first;
		int a = Q.top().second.first, b = Q.top().second.second;
		Q.pop();
		if (!S.count(a) || !S.count(b)) continue;
		S.erase(a);
		S.erase(b);
		res[my[a].second] = res[my[b].second] = dist;
		auto it = S.lower_bound(a);
		if (it != S.end()) {
			auto prv = it;
			if (prv != S.begin()) {
				prv--;
				Q.push(llii(-getDist(*prv, *it), ii(*prv, *it)));
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &X[i]);
			res[i] = Inf;
			my[i] = ii(X[i], i);
		}
		sort(my, my + n);
		for (int i = 0; i < n; i++)
			scanf(" %c", &str[i]);
		Solve(0);
		Solve(1);
		for (int i = 0; i < n; i++)
			printf("%I64d%c", res[i] >= Inf? -1ll: res[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}