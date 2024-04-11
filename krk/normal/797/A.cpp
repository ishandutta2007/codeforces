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

int n, k;
vector <int> V;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 2; i * i <= n; i++)
		while (n % i == 0) {
			V.push_back(i);
			n /= i;
		}
	if (n > 1) V.push_back(n);
	if (V.size() < k) printf("-1\n");
	else {
		for (int i = 0; i < k - 1; i++)
			printf("%d ", V[i]);
		int cur = 1;
		for (int i = k - 1; i < V.size(); i++)
			cur *= V[i];
		printf("%d\n", cur);
	}
	return 0;
}