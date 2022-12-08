#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

int n, p[200200], d1[200200], s1[200200], v1[200200];
vector<int> g[200200];

void go1(int x, int l)
{
	p[x] = l;
	for (auto y : g[x]) if (y != l){
		go1(y, x);
		s1[x] += d1[y] + 1;
		d1[x] += s1[y];
	}
}

void go2(int x, int l)
{
	v1[x] = d1[x];
	if (p[x]){
		v1[x] += s1[p[x]] - (d1[x] + 1);
		if (p[p[x]]){
			v1[x] += v1[p[p[x]]] - s1[p[x]] + 1;
		}
	}

	for (auto y : g[x]) if (y != l){
		go2(y, x);
	}
}

int main()
{
	scanf ("%d", &n);
	for (int i = 1; i < n; i++){
		int x, y; scanf ("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	go1(1, 0);
	go2(1, 0);
	
	int a = n;
	for (int i = 1; i <= n; i++) if (a > v1[i]) a = v1[i];
	printf ("%d\n", a);

	return 0;
}