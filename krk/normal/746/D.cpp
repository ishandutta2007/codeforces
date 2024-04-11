#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector <string> V;
int n, k, a, b;

int main()
{
	scanf("%d %d %d %d", &n, &k, &a, &b);
	bool tka = a >= b;
	while (a || b) {
		if (tka && a == 0 || !tka && b == 0) { printf("NO\n"); return 0; }
		if (tka)
			if (a >= b) {
				int tk = min(a, k);
				V.push_back(string(tk, 'G')); a -= tk;
			} else { V.push_back(string(1, 'G')); a--; }
		else if (b >= a) {
			int tk = min(b, k);
			V.push_back(string(tk, 'B')); b -= tk;
		} else { V.push_back(string(1, 'B')); b--; }
		tka = !tka;
	}
	for (int i = 0; i < V.size(); i++)
		printf("%s", V[i].c_str());
	printf("\n");
	return 0;
}