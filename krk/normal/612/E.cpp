#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;

int n;
bool tk[Maxn];
int a[Maxn], res[Maxn];
vector <vector <int> > V[Maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		vector <int> seq;
		int v = i;
		while (!tk[v]) {
			tk[v] = true; seq.push_back(v);
			v = a[v];
		}
		if (seq.size() % 2) {
			int delt = (seq.size() + 1) / 2;
			for (int i = 0; i < seq.size(); i++)
				res[seq[i]] = seq[(i + delt) % seq.size()];
		} else V[seq.size()].push_back(seq);
	}
	for (int i = 0; i < Maxn; i++)
		if (V[i].size() % 2) { printf("-1\n"); return 0; }
		else for (int j = 0; j < V[i].size(); j += 2)
				for (int k = 0; k < i; k++) {
					res[V[i][j][k]] = V[i][j + 1][k];
					res[V[i][j + 1][k]] = V[i][j][(k + 1) % i];
				}
	for (int i = 1; i <= n; i++)
		if (a[i] != res[res[i]]) { printf("-1\n"); return 0; }
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
    return 0;
}