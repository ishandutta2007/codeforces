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

const int Maxb = 10;

int n, x, y;
int mask, pos;
int A, B;

bool Check(const vector <int> &V)
{
	if (V.empty()) return false;
	printf("? %d", V.size());
	for (int i = 0; i < V.size(); i++)
		printf(" %d", V[i]);
	printf("\n");
	fflush(stdout);
	int num; scanf("%d", &num);
	return num == (x ^ y) || num == y;
}

bool Sat(int num, int p)
{
	if (num & 1 << pos) return false;
	for (int i = Maxb - 1; i > p; i--)
		if ((num & 1 << i) != (A & 1 << i)) return false;
	if (num & 1 << p) return false;
	return true;
}

bool modCheck(int p)
{
	vector <int> V;
	for (int i = 1; i <= n; i++)
		if (Sat(i, p)) V.push_back(i);
	int res = Check(V);
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	for (int i = 0; i < Maxb; i++) {
		vector <int> V;
		for (int j = 1; j <= n; j++)
			if (j & 1 << i) V.push_back(j);
		if (Check(V)) mask |= 1 << i;
	}
	pos = Maxb;
	while (!(mask & 1 << pos)) pos--;
	for (int i = Maxb - 1; i > pos; i--)
		if (!modCheck(i)) A |= 1 << i;
	for (int i = pos - 1; i >= 0; i--)
		if (!modCheck(i)) A |= 1 << i;
	B = mask ^ A;
	if (A > B) swap(A, B);
	printf("! %d %d\n", A, B); fflush(stdout);
	return 0;
}