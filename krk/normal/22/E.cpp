#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
int neigh[Maxn];
int in[Maxn];
int st[Maxn];
vector <int> spec;
int col[Maxn];
vector <int> has[Maxn];
vector <int> a, b;

void Traverse(int v)
{
	if (st[v] == 2) return;
	if (st[v] == 1) { spec.push_back(v); col[v] = spec.size(); return; }
	st[v] = 1;
	Traverse(neigh[v]);
	st[v] = 2;
}

int getColor(int v)
{
	if (!col[v]) col[v] = getColor(neigh[v]);
	return col[v];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &neigh[i]); in[neigh[i]]++;
	}
	for (int i = 1; i <= n; i++)
		Traverse(i);
	for (int i = 1; i <= n; i++)
		if (!in[i]) has[getColor(i) - 1].push_back(i);
	if (spec.size() > 1)
		for (int i = 0; i < spec.size(); i++) {
			a.push_back(spec[i]); int ni = (i + 1) % spec.size();
			if (has[ni].size()) { b.push_back(has[ni].back()); has[ni].pop_back(); }
			else b.push_back(spec[ni]);
		}
	for (int i = 0; i < spec.size(); i++)
		while (has[i].size()) { a.push_back(spec[i]); b.push_back(has[i].back()); has[i].pop_back(); }
	printf("%d\n", a.size());
	for (int i = 0; i < a.size(); i++)
		printf("%d %d\n", a[i], b[i]);
	return 0;
}