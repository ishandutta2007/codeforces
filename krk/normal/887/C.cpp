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

const int Maxn = 25;
const int Maxl = 3;
const int Maxc = 8;
int rots[Maxl][Maxc] = {{1, 3, 5, 7, 9, 11, 24, 22}, {13, 14, 5, 6, 17, 18, 21, 22}, {3, 4, 17, 19, 10, 9, 16, 14}};

vector <int> seq;
int res;

void Rotate(vector <int> &V, int rots[])
{
	int sav1 = V[rots[0]], sav2 = V[rots[1]];
	for (int i = 0; i + 3 < Maxc; i += 2) {
		V[rots[i]] = V[rots[i + 2]];
		V[rots[i + 1]] = V[rots[i + 3]];
	}
	V[rots[Maxc - 2]] = sav1; V[rots[Maxc - 1]] = sav2;
}

void Rotate2(vector <int> &V, int rots[])
{
	int sav1 = V[rots[Maxc - 1]], sav2 = V[rots[Maxc - 2]];
	for (int i = Maxc - 1; i - 3 >= 0; i -= 2) {
		V[rots[i]] = V[rots[i - 2]];
		V[rots[i - 1]] = V[rots[i - 3]];
	}
	V[rots[1]] = sav1; V[rots[0]] = sav2;
}

bool Check(const vector <int> &seq)
{
	for (int i = 1; i < Maxn; i += 4)
		for (int j = 1; j <= 3; j++)
			if (seq[i] != seq[i + j]) return false;
	return true;
}

int main()
{
	seq.push_back(0);
	for (int i = 1; i < Maxn; i++) {
		int a; scanf("%d", &a);
		seq.push_back(a);
	}
	for (int i = 0; i < Maxl; i++) {
		Rotate(seq, rots[i]);
		if (Check(seq)) { printf("YES\n"); return 0; }
		Rotate2(seq, rots[i]); Rotate2(seq, rots[i]);
		if (Check(seq)) { printf("YES\n"); return 0; }
		Rotate(seq, rots[i]);
	}
	printf("NO\n");
	return 0;
}