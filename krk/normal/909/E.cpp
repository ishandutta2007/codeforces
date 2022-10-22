#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, m;
int E[Maxn];
vector <int> neigh[Maxn];
int in[Maxn];
queue <int> Q0, Q1;
queue <int> Q2;
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &E[i]);
	for (int i = 0; i < m; i++) {
		int b, a; scanf("%d %d", &b, &a);
		neigh[a].push_back(b);
		in[b]++;
	}
	for (int i = 0; i < n; i++)
		if (in[i] == 0)
			if (E[i] == 0) Q0.push(i);
			else Q1.push(i);
	int ex = 0;
	while (ex < n) {
		while (!Q0.empty() || !Q1.empty())
			if (!Q0.empty()) {
				int v = Q0.front(); Q0.pop(); ex++;
				for (int i = 0; i < neigh[v].size(); i++) {
					int u = neigh[v][i];
					if (--in[u] == 0)
						if (E[u] == 0) Q0.push(u);
						else Q1.push(u);
				}
			} else if (!Q1.empty()) {
				int v = Q1.front(); Q1.pop(); Q2.push(v);
				for (int i = 0; i < neigh[v].size(); i++) {
					int u = neigh[v][i];
					if (E[u] == 1)
						if (--in[u] == 0) Q1.push(u);
				}
			}
		if (Q2.empty()) continue;
		res++;
		while (!Q2.empty()) {
			int v = Q2.front(); Q2.pop(); ex++;
			for (int i = 0; i < neigh[v].size(); i++){
				int u = neigh[v][i];
				if (E[u] == 0)
					if (--in[u] == 0) Q0.push(u);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}