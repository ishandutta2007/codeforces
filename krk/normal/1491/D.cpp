#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;

int q;
int a, b;

bool Solve(int a, int b)
{
	if (a > b) return false;
	int i = Maxb - 1;
	int j = Maxb - 1;
	while (i >= 0 && !(a & 1 << i)) i--;
	while (j >= 0 && !(b & 1 << j)) j--;
	bool good = false;
	while (true)
		if (i < 0 && j < 0) return true;
		else if (i < 0) return false;
		else if (j < 0) return good;
		else if (i > j) {
			if (!good) return false;
			a ^= 1 << i;
			while (i >= 0 && !(a & 1 << i)) i--;
		} else {
			if (i < j) good = true;
			a ^= 1 << i;
			b ^= 1 << j;
			while (i >= 0 && !(a & 1 << i)) i--;
			while (j >= 0 && !(b & 1 << j)) j--;
		}
}

int main()
{
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &a, &b);
		printf("%s\n", Solve(a, b)? "YES": "NO");
	}
    return 0;
}