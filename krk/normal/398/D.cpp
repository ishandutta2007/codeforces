#include <cstdio>
#include <set>
using namespace std;

const int Maxn = 50005;
const int Maxp = 224;
const int margin = 20;

int n, m, q;
set <int> neighb[Maxn], neighs[Maxn];
bool B[Maxn], O[Maxn];
int hass[Maxn];

void becomeBig(int v)
{
	if (B[v] || neighb[v].size() + neighs[v].size() < Maxp) return;
	B[v] = true;
	for (set <int>::iterator it = neighb[v].begin(); it != neighb[v].end(); it++) {
		int u = *it;
		hass[u] -= O[v]; neighs[u].erase(v); neighb[u].insert(v);
	}
	for (set <int>::iterator it = neighs[v].begin(); it != neighs[v].end(); it++) {
		int u = *it;
		hass[u] -= O[v]; neighs[u].erase(v); neighb[u].insert(v);
	}
}

void becomeSmall(int v)
{
	if (!B[v] || neighb[v].size() + neighs[v].size() >= Maxp - margin) return;
	B[v] = false;
	for (set <int>::iterator it = neighb[v].begin(); it != neighb[v].end(); it++) {
		int u = *it;
		hass[u] += O[v]; neighb[u].erase(v); neighs[u].insert(v);
	}
	for (set <int>::iterator it = neighs[v].begin(); it != neighs[v].end(); it++) {
		int u = *it;
		hass[u] += O[v]; neighb[u].erase(v); neighs[u].insert(v);
	}
}

void Login(int v)
{
	O[v] = true;
	if (B[v]) return;
	for (set <int>::iterator it = neighb[v].begin(); it != neighb[v].end(); it++)
		hass[*it]++;
	for (set <int>::iterator it = neighs[v].begin(); it != neighs[v].end(); it++)
		hass[*it]++;
}

void Logout(int v)
{
	O[v] = false;
	if (B[v]) return;
	for (set <int>::iterator it = neighb[v].begin(); it != neighb[v].end(); it++)
		hass[*it]--;
	for (set <int>::iterator it = neighs[v].begin(); it != neighs[v].end(); it++)
		hass[*it]--;
}

void addFriend(int v, int u)
{
	if (B[u]) neighb[v].insert(u);
	else { hass[v] += O[u]; neighs[v].insert(u); }
	if (B[v]) neighb[u].insert(v);
	else { hass[u] += O[v]; neighs[u].insert(v); }
	becomeBig(v); becomeBig(u);
}

void delFriend(int v, int u)
{
	if (B[u]) neighb[v].erase(u);
	else { hass[v] -= O[u]; neighs[v].erase(u); }
	if (B[v]) neighb[u].erase(v);
	else { hass[u] -= O[v]; neighs[u].erase(v); }
	becomeSmall(v); becomeSmall(u);
}

int countFriends(int v)
{
	int res = hass[v];
	for (set <int>::iterator it = neighb[v].begin(); it != neighb[v].end(); it++)
		res += O[*it];
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	int o; scanf("%d", &o);
	while (o--) {
		int v; scanf("%d", &v);
		Login(v);
	}
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		addFriend(a, b);
	}
	while (q--) {
		char a; int b, c; scanf(" %c %d", &a, &b);
		if (a == 'O') Login(b);
		else if (a == 'F') Logout(b);
		else if (a == 'A') { scanf("%d", &c); addFriend(b, c); }
		else if (a == 'D') { scanf("%d", &c); delFriend(b, c); }
		else printf("%d\n", countFriends(b));
	}
	return 0;
}