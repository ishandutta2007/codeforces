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
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;
const int Inf = 1000000000;

int n, m, k;
char B[Maxn][Maxn];
set <int> R[Maxn], C[Maxn];
int dist[Maxn][Maxn];
int X1, Y1, X2, Y2;
vector <ii> Q;

void Left(int r, int c, int d)
{
	set <int>::iterator it = R[r].lower_bound(c);
	while (it != R[r].begin()) {
		it--;
		if (abs(*it - c) <= k && B[r][*it] != '#') {
			ii u = ii(r, *it); 
			dist[u.first][u.second] = d + 1; Q.push_back(u);
			C[*it].erase(r);
			R[r].erase(it++);
		} else break;
	}
}

void Up(int r, int c, int d)
{
	set <int>::iterator it = C[c].lower_bound(r);
	while (it != C[c].begin()) {
		it--;
		if (abs(*it - r) <= k && B[*it][c] != '#') {
			ii u = ii(*it, c);
			dist[u.first][u.second] = d + 1; Q.push_back(u);
			R[*it].erase(c);
			C[c].erase(it++);
		} else break;
	}
}

void Right(int r, int c, int d)
{
	set <int>::iterator it = R[r].upper_bound(c);
	while (it != R[r].end() && abs(*it - c) <= k && B[r][*it] != '#') {
		ii u = ii(r, *it);
		dist[u.first][u.second] = d + 1; Q.push_back(u);
		C[*it].erase(r);
		R[r].erase(it++);
	}
}

void Down(int r, int c, int d)
{
	set <int>::iterator it = C[c].upper_bound(r);
	while (it != C[c].end() && abs(*it - r) <= k && B[*it][c] != '#') {
		ii u = ii(*it, c);
		dist[u.first][u.second] = d + 1; Q.push_back(u);
		R[*it].erase(c);
		C[c].erase(it++);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", B[i] + 1);
		for (int j = 1; j <= m; j++) {
			R[i].insert(j);
			C[j].insert(i);
		}
	}
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	fill((int*)dist, (int*)dist + Maxn * Maxn, Inf); dist[X1][Y1] = 0;
	Q.push_back(ii(X1, Y1));
	R[X1].erase(Y1); C[Y1].erase(X1);
	for (int i = 0; i < Q.size(); i++) {
		ii v = Q[i];
		int d = dist[v.first][v.second];
		if (v == ii(X2, Y2)) { printf("%d\n", d); return 0; }
		Left(v.first, v.second, d);
		Up(v.first, v.second, d);
		Right(v.first, v.second, d);
		Down(v.first, v.second, d);
	}
	printf("-1\n");
	return 0;
}