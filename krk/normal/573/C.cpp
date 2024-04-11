#include <cstdio>
#include <vector>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;
const int Maxd = 7;

int n;
vector <int> neigh[Maxn];
bool res = true;

int Traverse(int v, int p = 0)
{
	int got[Maxd] = {};
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		got[Traverse(u, v)]++;
	}
	vector <int> seq;
	for (int i = 3; i < Maxd; i++)
		while (got[i]--) seq.push_back(i);
	if (seq.size() > 1) { res = false; return 0; }
	if (seq.size() == 1)
		if (seq[0] == 6 || got[1] + got[2] > 0) { res = false; return 0; }
		else {
			if (seq[0] != 5) seq[0]++;
			int cur = seq[0] + got[0];
			if (cur >= Maxd) { res = false; return 0; }
			return cur;
		}		
	if (got[1] || got[2]) 
		if (got[2] == 0 || got[2] == 1) return 2;
		else if (got[2] == 2) return 3;
		else { res = false; return 0; }
	if (got[0] == 0 || got[0] == 1) return 0;
	else if (got[0] == 2) return 1;
	else return 2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	printf("%s\n", res? "Yes": "No");
	return 0;
}