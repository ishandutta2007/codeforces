#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 150005;
int n, f[N];
vector<int> g[N];
int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
void inline merge(int x, int y) {
	x = find(x), y = find(y);
	if(g[x].size() > g[y].size()) swap(x, y);
	f[x] = y;
	for (int i = 0; i < g[x].size(); i++)
		g[y].push_back(g[x][i]);
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) f[i] = i, g[i].push_back(i);
	for (int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y), merge(x, y);
	}
	int rt = find(1);
	for (int i = 0; i < g[rt].size(); i++)
		printf("%d ", g[rt][i]);
	return 0;
}