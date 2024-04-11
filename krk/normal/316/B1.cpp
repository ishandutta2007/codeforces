#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 1005;

int n, x;
int to[Maxn];
int in[Maxn];
int id, comp[Maxn];
bool pos[Maxn];
int add;

int getSize(int v, int id)
{
	comp[v] = id;
	int res = 1;
	if (to[v] && !comp[to[v]]) res += getSize(to[v], id);
	return res;
}

int getPos(int v)
{
	if (!to[v]) return 1;
	return 1 + getPos(to[v]);
}

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &to[i]);
		if (to[i]) in[to[i]]++;
	}
	pos[0] = true;
	for (int i = 1; i <= n; i++) if (!in[i] && !comp[i]) {
		int siz = getSize(i, ++id);
		if (comp[x] == id) add = getPos(x);
		else for (int j = n - siz; j >= 0; j--)
				pos[j + siz] = pos[j + siz] || pos[j];
	}
	for (int i = 0; i <= n; i++)
		if (pos[i]) printf("%d\n", i + add);
	return 0;
}