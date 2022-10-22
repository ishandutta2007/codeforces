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

const int Maxn = 1005;
const int Maxd = 5;

int n;
int X[Maxn][Maxd];
set <int> S;

int Get(int a, int b)
{
	int res = 0;
	for (int i = 0; i < Maxd; i++)
		res += X[a][i] * X[b][i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		S.insert(i);
		for (int j = 0; j < Maxd; j++)
			scanf("%d", &X[i][j]);
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			for (set <int>::iterator it = S.begin(); it != S.end(); ) if (*it != i && *it != j) {
				for (int k = 0; k < Maxd; k++) {
					X[i][k] -= X[*it][k];
					X[j][k] -= X[*it][k];
				}
				bool el = Get(i, j) > 0;
				for (int k = 0; k < Maxd; k++) {
					X[i][k] += X[*it][k];
					X[j][k] += X[*it][k];
				}
				if (el) S.erase(it++);
				else it++;
			} else it++;
		}
	printf("%d\n", S.size());
	for (set <int>::iterator it = S.begin(); it != S.end(); it++)
		printf("%d\n", *it + 1);
	return 0;
}