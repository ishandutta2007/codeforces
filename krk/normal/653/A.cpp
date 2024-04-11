#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 52;

int n;
vector <int> V;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		V.push_back(a);
	}
	sort(V.begin(), V.end()); V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 0; i + 2 < V.size(); i++)
		if (V[i + 2] - V[i] <= 2) {
			printf("YES\n"); return 0;
		}
	printf("NO\n");
	return 0;
}