#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

struct stud {
	int abil, cost, ind;
	stud(int abil = 0, int cost = 0, int ind = 0): abil(abil), cost(cost), ind(ind) { }
	bool operator <(const stud &b) const {
		if (abil != b.abil) return abil < b.abil;
		if (cost != b.cost) return cost < b.cost;
		return ind < b.ind;
	}
};

int n, m, s;
ii bugs[Maxn];
stud S[Maxn];
int ans[Maxn];

bool Ok(int days)
{
	ll need = 0ll;
	priority_queue <ii> Q;
	int j = n - 1;
	for (int i = m - 1; i >= 0 && need <= s; i -= days) {
		while (j >= 0 && S[j].abil >= bugs[i].first) {
			Q.push(ii(-S[j].cost, S[j].ind)); j--;
		}
		if (Q.empty()) return false;
		need += -Q.top().first; Q.pop(); 
	}
	return need <= s;
}

void Print(int days)
{
	priority_queue <ii> Q;
	int j = n - 1;
	for (int i = m - 1; i >= 0; i -= days) {
		while (j >= 0 && S[j].abil >= bugs[i].first) {
			Q.push(ii(-S[j].cost, S[j].ind)); j--;
		}
		int toans = Q.top().second; Q.pop();
		for (int l = i; l >= 0 && l > i - days; l--)
			ans[bugs[l].second] = toans;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 0; i < m; i++) {
		scanf("%d", &bugs[i].first); bugs[i].second = i;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &S[i].abil);
	for (int i = 0; i < n; i++) {
		scanf("%d", &S[i].cost); S[i].ind = i + 1;
	}
	sort(bugs, bugs + m); sort(S, S + n);
	int l = 1, r = Maxn;
	int res = -1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Ok(mid)) { res = mid; r = mid - 1; }
		else l = mid + 1;
	}
	if (res == -1) printf("NO\n");
	else {
		printf("YES\n");
		Print(res);
		for (int i = 0; i < m; i++)
			printf("%d%c", ans[i], i + 1 < m? ' ': '\n');
	}
	return 0;
}