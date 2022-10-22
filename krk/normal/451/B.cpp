#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> V;

void Print(int ra, int rb)
{
	printf("yes\n");
	printf("%d %d\n", ra + 1, rb + 1);
}

int main()
{
	scanf("%d", &n); V.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &V[i]);
	int i = 0;
	while (i + 1 < n && V[i] <= V[i + 1]) i++;
	if (i + 1 >= n) Print(0, 0);
	else {
		int a = i;
		int b = i + 1;
		while (b + 1 < n && V[b] > V[b + 1]) b++;
		reverse(V.begin() + a, V.begin() + b + 1);
		bool ok = true;
		for (int i = 0; i + 1 < n && ok; i++)
			ok = V[i] <= V[i + 1];
		if (ok) Print(a, b);
		else printf("no\n");
	}
	return 0;
}