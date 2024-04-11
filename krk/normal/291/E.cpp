#include <cstdio>
#include <vector>
#include <string>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxl = 300005;
const int Maxm = 20;
const int arg = 7919;

int n;
vector <int> neigh[Maxn];
string st[Maxn];
int id, L[Maxl], P[Maxl][Maxm], H[Maxl][Maxm];
int pw[Maxm];
string t;
char tmp[Maxl];
int res;

void Get(string &s)
{
	scanf("%s", tmp); s = tmp;
}

void Traverse(int v, int p)
{
	for (int i = 0; i < st[v].length(); i++) {
		L[id] = p == -1? 1: L[p] + 1; P[id][0] = p; H[id][0] = st[v][i] - 'a'; p = id++;
	}
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i], p);
}

bool canGet(int len, int h, int v)
{
	if (L[v] < len) return false;
	int got = 0;
	int p = 1;
	for (int i = Maxm - 1; i >= 0; i--)
		if (1 << i <= len) {
			got += p * H[v][i]; v = P[v][i];
			p *= pw[i];
			len -= 1 << i;
		}
	return h == got;
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		neigh[p].push_back(i);
		Get(st[i]);
	}
	Traverse(1, -1);
	pw[0] = arg;
	for (int i = 1; i < Maxm; i++) 
		pw[i] = pw[i - 1] * pw[i - 1];
	for (int j = 1; j < Maxm; j++)
		for (int i = 0; i < id; i++) {
			P[i][j] = P[P[i][j - 1]][j - 1];
			H[i][j] = H[P[i][j - 1]][j - 1] * pw[j - 1] + H[i][j - 1];
		}
	Get(t);
	int h = 0;
	for (int i = 0; i < t.length(); i++)
		h = h * arg + t[i] - 'a';
	for (int i = 0; i < id; i++)
		res += canGet(t.length(), h, i);
	printf("%d\n", res);
	return 0;
}