#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long double ld;
typedef pair <int, int> ii;

const int Maxn = 105;

int n;
vector <ii> neigh[Maxn];

void Traverse(int v, int p, ld was)
{
	ld dif = 2.0l / ld(neigh[v].size());
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (p == u.first) continue;
		was += dif;
		while (was >= 2.0) was -= 2.0;
		if (was <= 1.0) { 
			printf("1 %d %d %d %.10lf\n", u.second, u.first, v, double(1.0l - was));
			Traverse(u.first, v, 1.0l + was); 
		} else {
			printf("1 %d %d %d %.10lf\n", u.second, v, u.first, double(2.0l - was));
			Traverse(u.first, v, was - 1.0l);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(ii(b, i + 1));
		neigh[b].push_back(ii(a, i + 1));
	}
	printf("%d\n", n - 1);
	Traverse(1, 0, 0.5l);
	return 0;
}