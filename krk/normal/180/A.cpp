#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 205;

int n, m;
int inmem[Maxn];
int id = 1;
vector <int> res1, res2;

int Find(int from, int val)
{
	while (inmem[from] != val) from++;
	return from;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int siz; scanf("%d", &siz);
		for (int j = 0; j < siz; j++) { int a; scanf("%d", &a); inmem[a] = id++; }
	}
	for (int i = 1; i < id; i++) 
		if (inmem[i] != i) {
			if (inmem[i]) {
				int v = Find(i, 0);
				inmem[v] = inmem[i]; inmem[i] = 0;
				res1.push_back(i); res2.push_back(v);
			}
			int v = Find(i, i);
			inmem[i] = inmem[v]; inmem[v] = 0;
			res1.push_back(v); res2.push_back(i);
		}
	printf("%d\n", res1.size());
	for (int i = 0; i < res1.size(); i++) printf("%d %d\n", res1[i], res2[i]);
	return 0;
}